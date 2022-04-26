#include <iostream>
#include <bits/stdc++.h>
#include <fstream>

using namespace std;

// structure of token
struct token
{
    int tk_no;
    string lexeme;
    int lc;
};

vector<token> token_Set;
vector<string> keywords = {"main", "int", "float", "string", "bool", "for", "while", "return", "var", "if", "elsif", "else", "print"};

static token newtk(int tk_num, string lex, int line)
{
    token tk;
    tk.tk_no = tk_num;
    tk.lexeme = lex;
    tk.lc = line;
    return tk;
}

// error for stray character
void throw_error(char ch, int lc)
{
    cout << "Lexical error: stray "
         << "\'" << ch << "\'"
         << " in program at line number = " << lc << endl;
}
// error for stray lexeme
void throw_error(string lex, int *idx, int lc)
{
    cout << "Lexical error: stray "
         << "\'" << lex << "\'"
         << " in program at line number = " << lc << endl;
    (*idx)++;
}
// ignore comments while reading input file
void skipComments(string line, int *idx, int lc)
{
    (*idx)++;
    if (line[*idx] == '%')
    {
        while (line[*idx])
        {
            (*idx)++;
        }
    }
    else
    {
        (*idx)--;
        throw_error("%", idx, lc);
        return;
    }
}

// dfa for relational operators
void scanRelOp(string line, int *idx, int lc)
{
    switch (line[*idx])
    {
    case '<':
        (*idx)++;
        if (line[*idx] == '=')
        {
            token_Set.push_back(newtk(600, "<=", lc));
        }
        else
        {
            (*idx)--;
            token_Set.push_back(newtk(601, "<", lc));
        }
        break;
    case '>':
        (*idx)++;
        if (line[*idx] == '=')
        {
            token_Set.push_back(newtk(602, ">=", lc));
        }
        else
        {
            (*idx)--;
            token_Set.push_back(newtk(603, ">", lc));
        }
        break;
    case '=':
        (*idx)++;
        if (line[*idx] == '=')
        {
            token_Set.push_back(newtk(604, "==", lc));
        }
        else if (line[*idx] == ' ')
        {
            throw_error("=", idx, lc);
            return;
        }
        else
        {
            (*idx)--;
            throw_error("=", idx, lc);
            return;
        }
        break;
    }
    (*idx)++;
}

// dfa for assignment op
void scanAssignOp(string line, int *idx, int lc)
{
    (*idx)++;
    if (line[*idx] == '=')
    {
        token_Set.push_back(newtk(700, ":=", lc));
    }
    else if (line[*idx] == ' ')
    {
        throw_error(":", idx, lc);
        return;
    }
    else
    {
        (*idx)--;
        throw_error(":", idx, lc);
        return;
    }
    (*idx)++;
}

// dfa for scanning numbers (integer/float)
void scanNumberToken(string line, int *idx, int lc)
{
    int state = 0; // start state
    string lexeme = "";

    if (line[*idx] < '0' || line[*idx] > '9')
    {
        state = 5;
        throw_error(line[*idx], lc);
        (*idx)--;
        return;
    }

    if (state == 0)
    {
        if (line[*idx] >= '1' && line[*idx] <= '9')
        {
            state = 2;
            lexeme += line[*idx];
            (*idx)++;
        }
        else if (line[*idx] == '0')
        {
            state = 1;
            lexeme += line[*idx];
            (*idx)++;
        }
        else if (line[*idx] < '0' || line[*idx] > '9')
        {
            state = 5;
            throw_error(lexeme, idx, lc);
            (*idx)--;
            return;
        }
    }
    if (state == 1)
    {
        if (line[*idx] == '.')
        {
            state = 3;
            lexeme += line[*idx];
            (*idx)++;
        }
        else
        {
            token_Set.push_back(newtk(101, lexeme, lc));
        }
    }
    if (state == 2)
    {
        while (line[*idx] >= '0' && line[*idx] <= '9')
        {
            lexeme += line[*idx];
            (*idx)++;
        }
        if (line[*idx] == '.')
        {
            state = 3;
            lexeme += line[*idx];
            (*idx)++;
        }
        else
        {
            token_Set.push_back(newtk(100, lexeme, lc));
        }
    }
    if (state == 3)
    {
        if (line[*idx] < '0' || line[*idx] > '9')
        {
            state = 5;
            throw_error(lexeme, idx, lc);
            (*idx)--;
            return;
        }
        else
        {
            state = 4;
            lexeme += line[*idx];
            (*idx)++;
        }
    }
    if (state == 4)
    {
        while (line[*idx] >= '0' && line[*idx] <= '9')
        {
            lexeme += line[*idx];
            (*idx)++;
        }
        token_Set.push_back(newtk(101, lexeme, lc));
    }
}

// dfa for scanning named entities
void scanNamesToken(string line, int *idx, int lc)
{
    string lexeme = "";
    (*idx)--;
    char firstLetter = line[*idx];
    (*idx)++;
    while ((line[*idx]) && ((line[*idx] >= 'a' && line[*idx] <= 'z') || (line[*idx] >= '0' && line[*idx] <= '9') || (line[*idx] >= 'A' && line[*idx] <= 'Z') || (line[*idx] == '_')))
    {
        lexeme += line[*idx];
        (*idx)++;
    }
    if (firstLetter >= '0' && firstLetter <= '9')
    {
        throw_error(firstLetter + lexeme, idx, lc);
        return;
    }
    int flg = 0;
    for (int i = 0; i < keywords.size(); i++)
    {
        if (lexeme == keywords[i])
        {
            token_Set.push_back(newtk(501 + i, lexeme, lc));
            flg = 1;
            break;
        }
    }
    if (flg == 0)
    {

        token_Set.push_back(newtk(500, lexeme, lc));
    }
}

void scanStringliterals(string line, int *idx, int lc)
{
    // cout<<"str"<<endl;
    string lexeme = "";
    (*idx)++;
    int flg = 0;
    while (line[*idx] != '\"')
    {
        // cout<<line[*idx]<<endl;
        lexeme += line[*idx];
        (*idx)++;
    }
    token_Set.push_back(newtk(111, lexeme, lc));
    (*idx)++;
}

int scanTokens()
{
    ifstream fin;  // input file stream
    ofstream fout; // output file stream
    fin.open("C:/Users/BITS-PC/Desktop/Compiler Project/TC/tc_7.txt");
    fout.open("C:/Users/BITS-PC/Desktop/Compiler Project/TC/tc_7_op.txt");
    int lc = 0; // maintains line number count
    string line;
    while (getline(fin, line))
    {
        lc++;
        int idx = 0; // positional index
        while (line[idx])
        {
            if ((line[idx] >= 'A' && line[idx] <= 'Z') || (line[idx] >= 'a' && line[idx] <= 'z'))
            {
                scanNamesToken(line, &idx, lc);
            }
            else if ((line[idx] >= '0' && line[idx] <= '9'))
            {
                scanNumberToken(line, &idx, lc);
            }
            else
            {
                switch (line[idx])
                {
                case '%':
                    skipComments(line, &idx, lc);
                    break; // get comments
                case '\t':
                case ' ':
                    idx++;
                    break; // ignore whitespaces,tabs
                case '+':
                case '-':
                case '*':
                case '/':
                    switch (line[idx])
                    {
                    case '+':
                        token_Set.push_back(newtk(300, "+", lc));
                        break;
                    case '-':
                        token_Set.push_back(newtk(301, "-", lc));
                        break;
                    case '*':
                        token_Set.push_back(newtk(302, "*", lc));
                        break;
                    case '/':
                        token_Set.push_back(newtk(303, "/", lc));
                        break;
                    }
                    idx++;
                    break; // arithmetic operators
                case '>':
                case '<':
                case '=':
                    scanRelOp(line, &idx, lc);
                    break; // relational operator
                case '{':
                case '}':
                case '(':
                case ')':
                case '[':
                case ']':
                case ';':
                case ',':
                    // delimiters
                    switch (line[idx])
                    {
                    case '{':
                        token_Set.push_back(newtk(400, "{", lc));
                        break;
                    case '}':
                        token_Set.push_back(newtk(401, "}", lc));
                        break;
                    case '(':
                        token_Set.push_back(newtk(402, "(", lc));
                        break;
                    case ')':
                        token_Set.push_back(newtk(403, ")", lc));
                        break;
                    case ',':
                        token_Set.push_back(newtk(404, ",", lc));
                        break;
                    case '[':
                        token_Set.push_back(newtk(405, "[", lc));
                        break;
                    case ']':
                        token_Set.push_back(newtk(406, "]", lc));
                        break;
                    case ';':
                        token_Set.push_back(newtk(200, ";", lc));
                        break;
                    }
                    idx++;
                    break;
                case ':':
                    scanAssignOp(line, &idx, lc);
                    break;
                case '\"':
                    scanStringliterals(line, &idx, lc);
                    break;
                default:
                    throw_error(line[idx], lc);
                    idx++;
                    break;
                }
            }
        }
    }
    // Writing the token list on o/p file
    for (token tk : token_Set)
    {
        fout << "Token " << tk.tk_no << ", string \"" << tk.lexeme << "\", line number " << tk.lc << "\n";
    }

    fin.close();
    fout.close();
    return 0;
}