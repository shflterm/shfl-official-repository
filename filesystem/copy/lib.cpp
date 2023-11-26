#include <iostream>
#include <map>
#include <string>
#include <shfl.h>

using namespace std;
using namespace std::filesystem;

COMMAND_MAIN(Workspace ws, map<string, string>&options, bool bgMode) {
    const string source = options["source"];
    const string destination = options["destination"];

    copy(source, destination);

    return absolute((ws.currentDirectory()/destination)).string();
}
