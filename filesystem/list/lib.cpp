#include <map>
#include <string>
#include <shfl.h>

using namespace std;
using namespace std::filesystem;

COMMAND_MAIN(Workspace* ws, map<string, string>&options, bool bgMode) {
    int files = 0;
    for (const auto&entry: directory_iterator(ws->currentDirectory())) {
        if (entry.is_directory()) info(bg_blue + " " + entry.path().filename().string() + " ");
        else info(entry.path().filename().string());
        files++;
    }

    return to_string(files);
}
