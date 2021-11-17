#pragma once

#include <iostream>
#include <string>
#include <map>
#include <iterator>
#include <fstream>
#include <vector>

using namespace std;

map<char, char> symbols = { {'+', '+'}, {'-', '-'}, {'*', '*'}, {'/', '/'},
                           {'=', '='}, {'<', '<'}, {'(', '('}, {')', ')'},
                           {';', ';'},
};

map<string, string> reservedWords = { {"if", "if"}, {"then", "then"}, {"else", "else"}, {"end", "end"},
                           {"repeat", "repeat"}, {"until", "until"}, {"read", "read"}, {"write", "write"},
};


typedef enum {
    RESERVED, SPECIAL, NUM, ID, ERR, eof
}tokenType;

typedef enum {
    START, INCOMMENT, INNUM, INID, INASSIGN, DONE, ERROR
}state;

typedef struct token {
    tokenType tType;
    string tVal;
}token;

int index = 0;
int limit = 0;
bool isError = false;
int lineNum = 0;
string textBuffer;
vector<string> lines;