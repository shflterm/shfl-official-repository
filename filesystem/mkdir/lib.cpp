#include <iostream>
#include <map>
#include <string>
#include <shfl.h>

using namespace std;

COMMAND_MAIN(Workspace* ws, map<string, string>&options, bool bgMode) {
    string text = options["text"];
    text[0] = toupper(text[0]);
    if (!bgMode) cout << text << endl;
    return text;
}
