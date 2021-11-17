#include "./scan.hh"

token getToken(string input, int& index, int limit) {
    string output = ""; token currentToken;
    index--;
    state currentState, nextState;
    int nextIndex;

    nextState = currentState = START;

    while (currentState != DONE) {
        currentState = nextState;
        nextIndex = index + 1;
        //cout <<"looking at: "<<input[nextIndex] << " State: " << currentState << endl;
        // todo in each state

        switch (currentState) {
        case START:
            if (isalpha(input[nextIndex]) || isdigit(input[nextIndex]) || isSymbol(input[nextIndex]) || input[nextIndex] == ':') {
                output += input[nextIndex];
                //cout << "start: " <<output<< endl;
                index++;
                //if(isSymbol(input[index])) currentToken.tType = SPECIAL;
            }
            else if (input[nextIndex] == ' ' || input[nextIndex] == '\t' || input[nextIndex] == '\n') index++;
            else if (input[nextIndex] == '{') index++;
            else index++; // error
            if (isSymbol(input[index])) currentToken.tType = SPECIAL;
            break;
        case INCOMMENT:
            index++;
            break;
        case INASSIGN:
            if (input[nextIndex] == '=') {
                output += input[nextIndex];
                currentToken.tType = SPECIAL;
                //cout << "inid: " << output<< endl;
                index++;
            }
            break;
        case INID:
            if (isalpha(input[nextIndex]) || isdigit(input[nextIndex])) {
                output += input[nextIndex];
                //currentToken.tType = ID;
                //cout << "inid: " << output<< endl;
                index++;
            }
            currentToken.tType = ID;
            break;
        case INNUM:
            if (isdigit(input[nextIndex])) {
                output += input[nextIndex];
                //cout << "innum: " << output<< endl;
                index++;
            }
            currentToken.tType = NUM;
            break;
        case DONE:
            //cout << "Done: " << output<< endl;
            index++;
            if (isReservedWord(output))currentToken.tType = RESERVED;
            currentToken.tVal = output;
            return currentToken;
            break;
        case ERROR:
            //cout << "ERROR: " << output<< endl;
            if (index == limit && output == "") {
                currentToken.tVal = "";
                currentToken.tType = eof;
                return currentToken;
            }
            isError = true;
            currentToken.tType = ERR;
            currentToken.tVal = output;
            return currentToken;
        default: // error
            cout << "output error" << endl;
            break;
        }

        // transition from each state
        switch (currentState) {
        case START:
            if (input[nextIndex] == '{') nextState = INCOMMENT;
            else if (input[nextIndex] == ':') nextState = INASSIGN;
            else if (isalpha(input[nextIndex])) nextState = INID;
            else if (isdigit(input[nextIndex])) nextState = INNUM;
            else if (isSymbol(input[nextIndex])) nextState = DONE;
            else if (input[nextIndex] == ' ' || input[nextIndex] == '\t' || input[nextIndex] == '\n')  nextState = START;
            else nextState = ERROR;
            break;
        case INCOMMENT:
            if (input[nextIndex] == '}') nextState = START;
            else nextState = INCOMMENT;
            break;
        case INASSIGN:
            if (input[nextIndex] == '=') nextState = DONE;
            else nextState = ERROR;
            break;
        case INID:
            if (isalpha(input[nextIndex]) || isdigit(input[nextIndex])) nextState = INID;
            else nextState = DONE;
            break;
        case INNUM:
            if (isdigit(input[nextIndex])) nextState = INNUM;
            else nextState = DONE;
        case DONE:
            nextState = DONE; // not sure
            break;
        case ERROR:
            nextState = ERROR; // no way out
            break;
        default: // error
            cout << "No Token" << endl;
            break;
        }
        
        if (index < limit && input[index] == '\n') {
            if (lineNum <= lines.size())
            {
                cout << lineNum << ": " << lines[lineNum - 1];
                lineNum++;
            }
            if (textBuffer != "") cout << textBuffer;
            textBuffer = "";
        }
    }
}
