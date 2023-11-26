#include <map>
#include <string>
#include <filesystem>
#include <shfl.h>

using namespace std;
using namespace std::filesystem;

COMMAND_MAIN(Workspace* ws, map<string, string>&options, bool bgMode) {
    const path to = options["path"];
    ws->moveDirectory(to);
    return absolute(ws->currentDirectory()).string();
}
