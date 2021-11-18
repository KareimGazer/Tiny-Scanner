#include "./helpers.hh"

bool isSymbol(char symbol) { return symbols.find(symbol) != symbols.end(); }

bool isReservedWord(string word) { return reservedWords.find(word) != reservedWords.end(); }

string getTokenTypeString(tokenType t) {
    switch (t)
    {
    case RESERVED:
        return "reserved word: ";
    case SPECIAL:
        return ""; // not mentioned in the output
    case ID:
        return "ID, name= ";
    case NUM:
        return "NUM, val= ";
    case ERR:
        return "ERROR ";
    case eof:
        return "EOF";
    default:
        break;
    }
}