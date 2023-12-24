#include <iostream>
#include <map>
#include <string>
#include <chrono>
#include <ctime>
#include <iomanip>
#include <sstream>
#include <shfl.h>

using namespace std;

COMMAND_MAIN(Workspace* ws, map<string, string>& options, bool bgMode) {
    const auto now = chrono::system_clock::to_time_t(chrono::system_clock::now());

    stringstream ss;
    ss << put_time(localtime(&now), "%H:%M:%S");
    string currentTime = ss.str();

    if (!bgMode) info(currentTime);

    return currentTime;
}