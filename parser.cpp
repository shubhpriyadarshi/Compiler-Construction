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
    mp[{9, "("}] = {'s', 12};
    mp[{11, "("}] = {'s', 13};
    mp[{23, "("}] = {'s', 38};
    mp[{25, "("}] = {'s', 39};
    mp[{26, "("}] = {'s', 40};
    mp[{27, "("}] = {'s', 41};
    mp[{29, "("}] = {'s', 46};
}

// parser to call the lexer function
int main()
{
    scanTokens();

    // structure of algorithm
    /*
    stack<string> st;
    |    |
    | 0  |<-- INITIAL STACK
    |_$__|
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