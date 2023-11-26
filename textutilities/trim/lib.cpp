#include <iostream>
#include <map>
#include <string>
#include <shfl.h>

using namespace std;

COMMAND_MAIN(Workspace* ws, map<string, string>&options, bool bgMode) {
    string text = trim(options["text"]);
    if (!bgMode) info(text);
    return text;
}
