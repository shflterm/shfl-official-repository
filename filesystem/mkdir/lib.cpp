#include <iostream>
#include <map>
#include <string>
#include <filesystem>
#include <shfl.h>

using namespace std;
using namespace std::filesystem;

COMMAND_MAIN(Workspace* ws, map<string, string>&options, bool bgMode) {
    string name = options["name"];
    const path dir = ws->currentDirectory() / name;
    create_directories(dir);
    return dir.string();
}
