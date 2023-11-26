#include <iostream>
#include <map>
#include <string>
#include <shfl.h>

using namespace std;

COMMAND_MAIN(Workspace ws, map<string, string>&options, bool bgMode) {
    string input;
    getline(cin, input);
    if (!bgMode) info(input);
    return input;
}
