#include "./globals.hh"
#include "./helpers.hh"
#include "./scan.hh"

int main() {
    string key;
    while (key != "exit") {
        string filePath;
        token outToken;
        cout << "please enter File Path: " << endl;
        cin >> filePath;
        string text = "";
        string textLine = "";
        ifstream MyReadFile(filePath);
        while (getline(MyReadFile, textLine)) {
            text += textLine + "\n";
            lines.push_back(textLine + "\n");
        }
        //getline(cin, input);
        limit = text.size();
        lineNum = 1; index = 0; isError = false; textBuffer = "";
        while (index < limit && !isError) {
            outToken = getToken(text, index, limit);
            //cout << "got token: "<< index <<" " << limit<< endl;
            textBuffer += "\t" + to_string(lineNum) + ": " + getTokenTypeString(outToken.tType) + outToken.tVal + "\n";
            // cout <<"stopped at: " <<input[index]<< endl;
        }
        cout << textBuffer << endl;
        textBuffer = "";
        MyReadFile.close();
        lines.clear();

        cout << "type 'exit' to exit else to continue and restart the program" << endl;
        cin >> key;
    }
    return 0;
}
