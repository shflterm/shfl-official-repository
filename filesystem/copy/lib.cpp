#include <iostream>
#include <map>
#include <string>
#include <shfl.h>

using namespace std;
using namespace std::filesystem;

COMMAND_MAIN(Workspace* ws, map<string, string>&options, bool bgMode) {
    const path source = options["source"];
    const path destination = options["destination"];

    copy(source, destination, copy_options::recursive);

    return absolute(ws->currentDirectory() / destination).string();
}
