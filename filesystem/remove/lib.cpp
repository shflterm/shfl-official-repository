#include <iostream>
#include <map>
#include <string>
#include <shfl.h>

using namespace std;
using namespace std::filesystem;

COMMAND_MAIN(Workspace ws, map<string, string>&options, bool bgMode) {
    const string path = options["path"];

    return to_string(remove(path));
}
