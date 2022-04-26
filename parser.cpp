#include <iostream>
#include <bits/stdc++.h>
#include <fstream>
#include "lexer.cpp"

map<pair<int, string>, pair<char, int>> populate_parse_table()
{
    map<pair<int, string>, pair<char, int>> mp;
    mp[{0, "main"}] = {'r', 5};
    mp[{2, "main"}] = {'s', 9};
    mp[{3, "main"}] = {'r', 5};
    mp[{10, "main"}] = {'r', 4};
    mp[{70, "main"}] = {'r', 3};
    /**********************/
    mp[{9, "("}] = {'s', 12};
    mp[{11, "("}] = {'s', 13};
    mp[{23, "("}] = {'s', 38};
    mp[{25, "("}] = {'s', 39};
    mp[{26, "("}] = {'s', 40};
    mp[{27, "("}] = {'s', 41};
    mp[{29, "("}] = {'s', 46};
    /**********************/
    mp[{12, ")"}] = {'s', 14};
    mp[{13, ")"}] = {'r', 8};
    mp[{15, ")"}] = {'s', 18};
    mp[{16, ")"}] = {'r', 7};
    mp[{19, ")"}] = {'r', 8};
    mp[{31, ")"}] = {'r', 6};
    mp[{38, ")"}] = {'r', 31};
    mp[{44, ")"}] = {'r', 35};
    mp[{45, ")"}] = {'r', 36};
    mp[{53, ")"}] = {'s', 75};
    mp[{54, ")"}] = {'r', 30};
    mp[{56, ")"}] = {'s', 78};
    mp[{57, ")"}] = {'s', 79};
    mp[{58, ")"}] = {'r', 24};
    mp[{69, ")"}] = {'s', 82};
    mp[{76, ")"}] = {'r', 31};
    mp[{80, ")"}] = {'r', 37};
    mp[{81, ")"}] = {'r', 38};
    mp[{85, ")"}] = {'r', 29};
    mp[{93, ")"}] = {'s', 96};
    /*********************/
    mp[{14, "{"}] = {'s', 17};
    mp[{18, "{"}] = {'s', 30};
    mp[{78, "{"}] = {'s', 87};
    mp[{82, "{"}] = {'s', 89};
    mp[{96, "{"}] = {'s', 99};
    mp[{98, "{"}] = {'s', 100};
    /**********************/
    mp[{20, "}"}] = {'s', 32};
    mp[{21, "}"}] = {'r', 10};
    mp[{24, "}"}] = {'r', 17};
    mp[{33, "}"}] = {'r', 9};
    mp[{47, "}"}] = {'s', 70};
    mp[{48, "}"}] = {'r', 11};
    mp[{49, "}"}] = {'r', 14};
    mp[{59, "}"}] = {'r', 32};
    mp[{74, "}"}] = {'r', 16};
    mp[{84, "}"}] = {'r', 28};
    mp[{88, "}"}] = {'r', 23};
    mp[{91, "}"}] = {'s', 94};
    mp[{92, "}"}] = {'s', 95};
    mp[{94, "}"}] = {'r', 22};
    mp[{95, "}"}] = {'r', 20};
    mp[{97, "}"}] = {'r', 18};
    mp[{101, "}"}] = {'s', 103};
    mp[{102, "}"}] = {'s', 104};
    mp[{103, "}"}] = {'r', 21};
    mp[{104, "}"}] = {'r', 19};
    /************************/
    mp[{4, "id"}] = {'s', 11};
    mp[{5, "id"}] = {'r', 25};
    mp[{6, "id"}] = {'r', 26};
    mp[{7, "id"}] = {'r', 27};
    mp[{13, "id"}] = {'s', 16};
    mp[{17, "id"}] = {'s', 23};
    mp[{19, "id"}] = {'s', 16};
    mp[{21, "id"}] = {'s', 23};
    mp[{22, "id"}] = {'s', 36};
    mp[{24, "id"}] = {'r', 17};
    mp[{28, "id"}] = {'s', 44};
    mp[{30, "id"}] = {'s', 23};
    mp[{37, "id"}] = {'s', 44};
    mp[{38, "id"}] = {'s', 54};
    mp[{39, "id"}] = {'s', 44};
    mp[{40, "id"}] = {'s', 44};
    mp[{41, "id"}] = {'s', 58};
    mp[{46, "id"}] = {'s', 44};
    mp[{48, "id"}] = {'r', 11};
    mp[{49, "id"}] = {'r', 14};
    mp[{50, "id"}] = {'s', 72};
    mp[{59, "id"}] = {'r', 32};
    mp[{60, "id"}] = {'s', 44};
    mp[{61, "id"}] = {'s', 44};
    mp[{62, "id"}] = {'r', 39};
    mp[{63, "id"}] = {'r', 40};
    mp[{64, "id"}] = {'r', 41};
    mp[{65, "id"}] = {'r', 42};
    mp[{66, "id"}] = {'r', 43};
    mp[{67, "id"}] = {'r', 44};
    mp[{68, "id"}] = {'r', 45};
    mp[{74, "id"}] = {'r', 16};
    mp[{76, "id"}] = {'s', 54};
    mp[{77, "id"}] = {'s', 44};
    mp[{84, "id"}] = {'r', 28};
    mp[{87, "id"}] = {'s', 23};
    mp[{88, "id"}] = {'r', 23};
    mp[{89, "id"}] = {'s', 23};
    mp[{90, "id"}] = {'s', 44};
    mp[{94, "id"}] = {'r', 22};
    mp[{95, "id"}] = {'r', 20};
    mp[{97, "id"}] = {'r', 18};
    mp[{99, "id"}] = {'s', 23};
    mp[{100, "id"}] = {'s', 23};
    mp[{103, "id"}] = {'r', 21};
    mp[{104, "id"}] = {'r', 19};
    /************************/
    mp[{16, ","}] = {'s', 19};
    mp[{36, ","}] = {'s', 50};
    mp[{54, ","}] = {'s', 76};
    mp[{72, ","}] = {'s', 50};
    /************************/
    mp[{28, ";"}] = {'r', 34};
    mp[{34, ";"}] = {'s', 48};
    mp[{35, ";"}] = {'s', 49};
    mp[{36, ";"}] = {'r', 13};
    mp[{42, ";"}] = {'s', 59};
    mp[{43, ";"}] = {'r', 33};
    mp[{44, ";"}] = {'r', 35};
    mp[{45, ";"}] = {'r', 36};
    mp[{52, ";"}] = {'s', 74};
    mp[{55, ";"}] = {'s', 77};
    mp[{71, ";"}] = {'r', 12};
    mp[{72, ";"}] = {'r', 13};
    mp[{75, ";"}] = {'s', 84};
    mp[{79, ";"}] = {'s', 88};
    mp[{80, ";"}] = {'r', 37};
    mp[{81, ";"}] = {'r', 38};
    mp[{83, ";"}] = {'r', 15};
    mp[{86, ";"}] = {'s', 90};
    /***********************/
    mp[{36, "["}] = {'s', 51};
    /***********************/
    mp[{28, "num"}] = {'s', 45};
    mp[{37, "num"}] = {'s', 45};
    mp[{39, "num"}] = {'s', 45};
    mp[{40, "num"}] = {'s', 45};
    mp[{46, "num"}] = {'s', 45};
    mp[{51, "num"}] = {'s', 73};
    mp[{60, "num"}] = {'s', 45};
    mp[{61, "num"}] = {'s', 45};
    mp[{62, "num"}] = {'r', 39};
    mp[{63, "num"}] = {'r', 40};
    mp[{64, "num"}] = {'r', 41};
    mp[{65, "num"}] = {'r', 42};
    mp[{66, "num"}] = {'r', 43};
    mp[{67, "num"}] = {'r', 44};
    mp[{68, "num"}] = {'r', 45};
    mp[{77, "num"}] = {'s', 45};
    mp[{90, "num"}] = {'s', 45};
    /*************************/
    mp[{73, "]"}] = {'s', 83};
    /*************************/
    mp[{23, ":="}] = {'s', 37};
    /*************************/
    mp[{17, "if"}] = {'s', 29};
    mp[{21, "if"}] = {'s', 29};
    mp[{24, "if"}] = {'r', 17};
    mp[{30, "if"}] = {'s', 29};
    mp[{48, "if"}] = {'r', 11};
    mp[{49, "if"}] = {'r', 14};
    mp[{59, "if"}] = {'r', 32};
    mp[{74, "if"}] = {'r', 16};
    mp[{84, "if"}] = {'r', 28};
    mp[{87, "if"}] = {'s', 29};
    mp[{88, "if"}] = {'r', 23};
    mp[{89, "if"}] = {'s', 29};
    mp[{94, "if"}] = {'r', 22};
    mp[{95, "if"}] = {'r', 20};
    mp[{97, "if"}] = {'r', 18};
    mp[{99, "if"}] = {'s', 29};
    mp[{100, "if"}] = {'s', 29};
    mp[{103, "if"}] = {'r', 21};
    mp[{104, "if"}] = {'r', 19};
    /*************************/
    mp[{95, "else"}] = {'s', 98};
    /*************************/
    mp[{17, "for"}] = {'s', 25};
    mp[{21, "for"}] = {'s', 25};
    mp[{24, "for"}] = {'r', 17};
    mp[{30, "for"}] = {'s', 25};
    mp[{48, "for"}] = {'r', 11};
    mp[{49, "for"}] = {'r', 14};
    mp[{59, "for"}] = {'r', 32};
    mp[{74, "for"}] = {'r', 16};
    mp[{84, "for"}] = {'r', 28};
    mp[{87, "for"}] = {'s', 25};
    mp[{88, "for"}] = {'r', 23};
    mp[{89, "for"}] = {'s', 25};
    mp[{94, "for"}] = {'r', 22};
    mp[{95, "for"}] = {'r', 20};
    mp[{97, "for"}] = {'r', 18};
    mp[{99, "for"}] = {'s', 25};
    mp[{100, "for"}] = {'s', 25};
    mp[{103, "for"}] = {'r', 21};
    mp[{104, "for"}] = {'r', 19};
    /**************************/
    mp[{17, "while"}] = {'s', 26};
    mp[{21, "while"}] = {'s', 26};
    mp[{24, "while"}] = {'r', 17};
    mp[{30, "while"}] = {'s', 26};
    mp[{48, "while"}] = {'r', 11};
    mp[{49, "while"}] = {'r', 14};
    mp[{59, "while"}] = {'r', 32};
    mp[{74, "while"}] = {'r', 16};
    mp[{84, "while"}] = {'r', 28};
    mp[{87, "while"}] = {'s', 26};
    mp[{88, "while"}] = {'r', 23};
    mp[{89, "while"}] = {'s', 26};
    mp[{94, "while"}] = {'r', 22};
    mp[{95, "while"}] = {'r', 20};
    mp[{97, "while"}] = {'r', 18};
    mp[{99, "while"}] = {'s', 26};
    mp[{100, "while"}] = {'s', 26};
    mp[{103, "while"}] = {'r', 21};
    mp[{104, "while"}] = {'r', 19};
    /***************************/
    mp[{17, "print"}] = {'s', 27};
    mp[{21, "print"}] = {'s', 27};
    mp[{24, "print"}] = {'r', 17};
    mp[{30, "print"}] = {'s', 27};
    mp[{48, "print"}] = {'r', 11};
    mp[{49, "print"}] = {'r', 14};
    mp[{59, "print"}] = {'r', 32};
    mp[{74, "print"}] = {'r', 16};
    mp[{84, "print"}] = {'r', 28};
    mp[{87, "print"}] = {'s', 27};
    mp[{88, "print"}] = {'r', 23};
    mp[{89, "print"}] = {'s', 27};
    mp[{94, "print"}] = {'r', 22};
    mp[{95, "print"}] = {'r', 20};
    mp[{97, "print"}] = {'r', 18};
    mp[{99, "print"}] = {'s', 27};
    mp[{100, "print"}] = {'s', 27};
    mp[{103, "print"}] = {'r', 21};
    mp[{104, "print"}] = {'r', 19};
    /***************************/
    mp[{0, "int"}] = {'s', 5};
    mp[{3, "int"}] = {'s', 5};
    mp[{17, "int"}] = {'s', 5};
    mp[{21, "int"}] = {'s', 5};
    mp[{24, "int"}] = {'r', 17};
    mp[{30, "int"}] = {'s', 5};
    mp[{48, "int"}] = {'r', 11};
    mp[{49, "int"}] = {'r', 14};
    mp[{59, "int"}] = {'r', 32};
    mp[{70, "int"}] = {'r', 3};
    mp[{74, "int"}] = {'r', 16};
    mp[{84, "int"}] = {'r', 28};
    mp[{87, "int"}] = {'s', 5};
    mp[{88, "int"}] = {'r', 23};
    mp[{89, "int"}] = {'s', 5};
    mp[{94, "int"}] = {'r', 22};
    mp[{95, "int"}] = {'r', 20};
    mp[{97, "int"}] = {'r', 18};
    mp[{99, "int"}] = {'s', 5};
    mp[{100, "int"}] = {'s', 5};
    mp[{103, "int"}] = {'r', 21};
    mp[{104, "int"}] = {'r', 19};
    /*************************/
    mp[{0, "string"}] = {'s', 6};
    mp[{3, "string"}] = {'s', 6};
    mp[{17, "string"}] = {'s', 6};
    mp[{21, "string"}] = {'s', 6};
    mp[{24, "string"}] = {'r', 17};
    mp[{30, "string"}] = {'s', 6};
    mp[{48, "string"}] = {'r', 11};
    mp[{49, "string"}] = {'r', 14};
    mp[{59, "string"}] = {'r', 32};
    mp[{70, "string"}] = {'r', 3};
    mp[{74, "string"}] = {'r', 16};
    mp[{84, "string"}] = {'r', 28};
    mp[{87, "string"}] = {'s', 6};
    mp[{88, "string"}] = {'r', 23};
    mp[{89, "string"}] = {'s', 6};
    mp[{94, "string"}] = {'r', 22};
    mp[{95, "string"}] = {'r', 20};
    mp[{97, "string"}] = {'r', 18};
    mp[{99, "string"}] = {'s', 6};
    mp[{100, "string"}] = {'s', 6};
    mp[{103, "string"}] = {'r', 21};
    mp[{104, "string"}] = {'r', 19};
    /***************************/
    mp[{0, "float"}] = {'s', 7};
    mp[{3, "float"}] = {'s', 7};
    mp[{17, "float"}] = {'s', 7};
    mp[{21, "float"}] = {'s', 7};
    mp[{24, "float"}] = {'r', 17};
    mp[{30, "float"}] = {'s', 7};
    mp[{48, "float"}] = {'r', 11};
    mp[{49, "float"}] = {'r', 14};
    mp[{59, "float"}] = {'r', 32};
    mp[{70, "float"}] = {'r', 3};
    mp[{74, "float"}] = {'r', 16};
    mp[{84, "float"}] = {'r', 28};
    mp[{87, "float"}] = {'s', 7};
    mp[{88, "float"}] = {'r', 23};
    mp[{89, "float"}] = {'s', 7};
    mp[{94, "float"}] = {'r', 22};
    mp[{95, "float"}] = {'r', 20};
    mp[{97, "float"}] = {'r', 18};
    mp[{99, "float"}] = {'s', 7};
    mp[{100, "float"}] = {'s', 7};
    mp[{103, "float"}] = {'r', 21};
    mp[{104, "float"}] = {'r', 19};
    /***************************/
    mp[{17, "return"}] = {'s', 28};
    mp[{21, "return"}] = {'s', 28};
    mp[{24, "return"}] = {'r', 17};
    mp[{30, "return"}] = {'s', 28};
    mp[{48, "return"}] = {'r', 11};
    mp[{49, "return"}] = {'r', 14};
    mp[{59, "return"}] = {'r', 32};
    mp[{74, "return"}] = {'r', 16};
    mp[{84, "return"}] = {'r', 28};
    mp[{87, "return"}] = {'s', 28};
    mp[{88, "return"}] = {'r', 23};
    mp[{89, "return"}] = {'s', 28};
    mp[{94, "return"}] = {'r', 22};
    mp[{95, "return"}] = {'r', 20};
    mp[{97, "return"}] = {'r', 18};
    mp[{99, "return"}] = {'s', 28};
    mp[{100, "return"}] = {'s', 28};
    mp[{103, "return"}] = {'r', 21};
    mp[{104, "return"}] = {'r', 19};
    /****************************/
    mp[{44, "+"}] = {'s', 62};
    mp[{44, "-"}] = {'s', 63};
    mp[{44, "*"}] = {'s', 64};
    mp[{44, "/"}] = {'s', 65};
    mp[{44, "<"}] = {'s', 66};
    mp[{44, ">"}] = {'s', 67};
    mp[{44, "=="}] = {'s', 68};
    /**********************/
    mp[{1, "$"}] = {'a', -1}; // accept
    mp[{8, "$"}] = {'r', 1};
    mp[{32, "$"}] = {'r', 2};
    /*********************/
    /** GOTO **/
    mp[{0, "PROG"}] = {'n', 1};
    mp[{2, "MAIN"}] = {'n', 8};
    mp[{0, "FUNCT"}] = {'n', 0};
    mp[{3, "FUNCT"}] = {'n', 3};
    mp[{0, "FUNCTS"}] = {'n', 2};
    mp[{3, "FUNCTS"}] = {'n', 10};
    mp[{13, "PARAM"}] = {'n', 15};
    mp[{19, "PARAM"}] = {'n', 31};
    mp[{17, "STMT_LIST"}] = {'n', 20};
    mp[{21, "STMT_LIST"}] = {'n', 33};
    mp[{30, "STMT_LIST"}] = {'n', 47};
    mp[{87, "STMT_LIST"}] = {'n', 91};
    mp[{89, "STMT_LIST"}] = {'n', 92};
    mp[{99, "STMT_LIST"}] = {'n', 101};
    mp[{100, "STMT_LIST"}] = {'n', 102};
    mp[{17, "STMT"}] = {'n', 21};
    mp[{21, "STMT"}] = {'n', 21};
    mp[{30, "STMT"}] = {'n', 21};
    mp[{87, "STMT"}] = {'n', 21};
    mp[{89, "STMT"}] = {'n', 21};
    mp[{99, "STMT"}] = {'n', 21};
    mp[{100, "STMT"}] = {'n', 21};
    mp[{22, "VARIABLES"}] = {'n', 34};
    mp[{50, "VARIABLES"}] = {'n', 71};
    mp[{22, "ARR"}] = {'n', 35};
    mp[{17, "IF_STMT"}] = {'n', 24};
    mp[{21, "IF_STMT"}] = {'n', 24};
    mp[{30, "IF_STMT"}] = {'n', 24};
    mp[{87, "IF_STMT"}] = {'n', 24};
    mp[{89, "IF_STMT"}] = {'n', 24};
    mp[{99, "IF_STMT"}] = {'n', 24};
    mp[{100, "IF_STMT"}] = {'n', 24};
    mp[{95, "ELSE_STMT"}] = {'n', 97};
    mp[{41, "PRINT_STMTS"}] = {'n', 57};
    mp[{0, "DTYPE"}] = {'n', 4};
    mp[{3, "DTYPE"}] = {'n', 4};
    mp[{17, "DTYPE"}] = {'n', 22};
    mp[{21, "DTYPE"}] = {'n', 22};
    mp[{30, "DTYPE"}] = {'n', 22};
    mp[{87, "DTYPE"}] = {'n', 22};
    mp[{89, "DTYPE"}] = {'n', 22};
    mp[{99, "DTYPE"}] = {'n', 22};
    mp[{100, "DTYPE"}] = {'n', 22};
    mp[{38, "ARGS"}] = {'n', 53};
    mp[{76, "ARGS"}] = {'n', 85};
    mp[{28, "RET_EXP"}] = {'n', 42};
    mp[{28, "EXPR"}] = {'n', 43};
    mp[{37, "EXPR"}] = {'n', 52};
    mp[{39, "EXPR"}] = {'n', 55};
    mp[{40, "EXPR"}] = {'n', 56};
    mp[{46, "EXPR"}] = {'n', 69};
    mp[{60, "EXPR"}] = {'n', 80};
    mp[{61, "EXPR"}] = {'n', 81};
    mp[{77, "EXPR"}] = {'n', 86};
    mp[{90, "EXPR"}] = {'n', 93};
    mp[{44, "ARITH_OP"}] = {'n', 60};
    mp[{44, "REL_OP"}] = {'n', 61};
    /*************************/
    return mp;
}

vector<string> get_rules()
{
    vector<string> rules(50);
    rules[0] = "S -> PROG";
    rules[1] = "PROG -> FUNCTS MAIN";
    rules[2] = "MAIN -> main ( ) { STMT_LIST }";
    rules[3] = "FUNCT -> DTYPE id ( PARAM ) { STMT_LIST }";
    rules[4] = "FUNCTS -> FUNCT FUNCTS";
    rules[5] = "FUNCTS -> ''";
    rules[6] = "PARAM -> id , PARAM";
    rules[7] = "PARAM -> id";
    rules[8] = "PARAM -> ''";
    rules[9] = "STMT_LIST -> STMT STMT_LIST";
    rules[10] = "STMT_LIST -> STMT";
    rules[11] = "STMT -> DTYPE VARIABLES ;";
    rules[12] = "VARIABLES -> id , VARIABLES";
    rules[13] = "VARIABLES -> id";
    rules[14] = "STMT -> DTYPE ARR ;";
    rules[15] = "ARR -> id [ num ]";
    rules[16] = "STMT -> id := EXPR ;";
    rules[17] = "STMT -> IF_STMT";
    rules[18] = "IF_STMT -> if ( EXPR ) { STMT_LIST } ELSE_STMT";
    rules[19] = "ELSE_STMT -> else { STMT_LIST }";
    rules[20] = "ELSE_STMT -> ''";
    rules[21] = "STMT -> for ( EXPR ; EXPR ; EXPR ) { STMT_LIST }";
    rules[22] = "STMT -> while ( EXPR ) { STMT_LIST }";
    rules[23] = "STMT -> print ( PRINT_STMTS ) ;";
    rules[24] = "PRINT_STMTS -> id";
    rules[25] = "DTYPE -> int";
    rules[26] = "DTYPE -> string";
    rules[27] = "DTYPE -> float";
    rules[28] = "STMT -> id ( ARGS ) ;";
    rules[29] = "ARGS -> id , ARGS";
    rules[30] = "ARGS -> id";
    rules[31] = "ARGS -> ''";
    rules[32] = "STMT -> return RET_EXP ;";
    rules[33] = "RET_EXP -> EXPR";
    rules[34] = "RET_EXP -> ''";
    rules[35] = "EXPR -> id";
    rules[36] = "EXPR -> num";
    rules[37] = "EXPR -> id ARITH_OP EXPR";
    rules[38] = "EXPR -> id REL_OP EXPR";
    rules[39] = "ARITH_OP -> +";
    rules[40] = "ARITH_OP -> -";
    rules[41] = "ARITH_OP -> *";
    rules[42] = "ARITH_OP -> /";
    rules[43] = "REL_OP -> <";
    rules[44] = "REL_OP -> >";
    rules[45] = "REL_OP -> ==";

    return rules;
}

// parser to call the lexer function
int main()
{
    scanTokens();
    map<pair<int, string>, pair<char, int>> parse_table = populate_parse_table();
    stack<string> st;
    vector<string> rules = get_rules();
    st.push("0");
    int ptr = 0;
    while (ptr < token_Set.size())
    {
        stack<string> tmp = st;

        token tk = token_Set[ptr];
        int tk_no = tk.tk_no;
        string input = symbol_table[tk_no];
        pair<char, int> action = parse_table[{stoi(st.top()), input}];
        cout << "Input token : " << tk.lexeme << endl;
        cout << "Stack state : ";
        while (!tmp.empty())
        {
            cout << tmp.top() << " ";
            tmp.pop();
        }
        cout << endl;
        cout << "Action : " << action.first << action.second << endl;

        if (action.first == 'a')
        {
            cout << "ACCEPTED" << endl;
            break;
        }
        cout << "=================================================================" << endl;
        if (action.first == 's')
        {
            st.push(input);
            st.push(to_string(action.second));
            ptr++;
        }
        if (action.first == 'r')
        {
            string rule = rules[action.second];
            vector<string> v;
            stringstream ss(rule);
            string word;
            int cou = 0;
            while (ss >> word)
            {
                v.push_back(word);
                if (word != "''")
                {
                    cou++;
                }
            }
            int tmp = 2 * (cou - 2);
            while (tmp--)
            {
                st.pop();
            }
            int nm = stoi(st.top());
            st.push(v[0]);
            pair<char, int> nxt_action = parse_table[{nm, v[0]}];
            st.push(to_string(nxt_action.second));
        }
    }
    // structure of algorithm
    /*
    stack<string> st;
    |    |
    |    |
    |_0__|<--INITIAL
    while(Scan the tokens){
        if(mp.find({stoi(st.top()),token}).find()==mp.end()){
            Report and call Errror routine
        }
        else{
            GOTO and perform Shift/Reduce action
        }
    }
    */

    return 0;
}