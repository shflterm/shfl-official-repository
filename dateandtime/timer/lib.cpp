#include <iostream>
#include <map>
#include <string>
#include <chrono>
#include <thread>
#include <shfl.h>

using namespace std;

COMMAND_MAIN(Workspace* ws, map<string, string>& options, bool bgMode) {
    string seconds_str = options["seconds"];
    int seconds = stoi(seconds_str);

    if (seconds <= 0) {
        if (!bgMode) error("Invalid value for seconds. Must be a positive integer.");
        return "";
    }
    this_thread::sleep_for(chrono::seconds(seconds));

    return "";
}
