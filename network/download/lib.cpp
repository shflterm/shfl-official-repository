#include <map>
#include <string>
#include <chrono>
#include <iomanip>
#include <shfl.h>

using namespace std;

COMMAND_MAIN(Workspace* ws, map<string, string>& options, bool bgMode) {
    const string url = options["url"];
    path outputFile = options.count("output_file") > 0 ? path(options["output_file"]) : "";

    if (outputFile.empty()) {
        const string urlFileName = url.substr(url.find_last_of('/') + 1);
        outputFile = ws->currentDirectory() / urlFileName;
    }

    downloadFile(url, outputFile);

    return absolute(outputFile).string();
}
