#include <iostream>
#include <map>
#include <string>
#include <shfl.h>

using namespace std;

COMMAND_MAIN(Workspace* ws, map<string, string>&options, bool bgMode) {
    if (!bgMode) info(absolute(ws->currentDirectory()).string());
    return absolute(ws->currentDirectory()).string();
}
