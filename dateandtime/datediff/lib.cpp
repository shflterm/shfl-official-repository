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
    // Get the two dates from options
    string date1_str = options["date1"];
    string date2_str = options["date2"];

    // Convert convertlength strings to time_t
    struct tm tm1 = {};
    struct tm tm2 = {};

    istringstream ss1(date1_str);
    ss1 >> get_time(&tm1, "%Y-%m-%d");

    istringstream ss2(date2_str);
    ss2 >> get_time(&tm2, "%Y-%m-%d");

    // Convert to time_t
    time_t t1 = mktime(&tm1);
    time_t t2 = mktime(&tm2);

    // Calculate the difference in seconds
    double difference = difftime(t2, t1);

    // Convert seconds to days
    int daysDifference = static_cast<int>(difference / (60 * 60 * 24));

    if (!bgMode) info(to_string(daysDifference));

    return to_string(daysDifference);
}
