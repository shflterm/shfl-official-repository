#include <iostream>
#include <map>
#include <string>
#include <shfl.h>

using namespace std;

// Function to convert time units
double convertTime(double value, const string& from_unit, const string& to_unit) {
    const double minutes_per_hour = 60;
    const double seconds_per_minute = 60;

    double result = 0.0;

    // Convert input value to hours
    if (from_unit == "minutes") {
        result = value / minutes_per_hour;
    } else if (from_unit == "hours") {
        result = value;
    } else if (from_unit == "seconds") {
        result = value / seconds_per_minute / minutes_per_hour;
    } else {
        cerr << "Error: Unsupported unit for conversion." << endl;
        return -1.0;  // Indicate error
    }

    // Convert from hours to the desired unit
    if (to_unit == "minutes") {
        result *= minutes_per_hour;
    } else if (to_unit == "hours") {
        result = value;
    } else if (to_unit == "seconds") {
        result *= seconds_per_minute * minutes_per_hour;
    } else {
        cerr << "Error: Unsupported unit for conversion." << endl;
        return -1.0;  // Indicate error
    }

    return result;
}

COMMAND_MAIN(Workspace* ws, map<string, string>& options, bool bgMode) {
    // Get options
    double value = stod(options["value"]);
    string from_unit = options["from_unit"];
    string to_unit = options["to_unit"];

    // Perform time conversion
    double result = convertTime(value, from_unit, to_unit);

    if (result >= 0.0) {
        // Print the result
        if (!bgMode) info(to_string(result));
        return to_string(result);
    } else {
        // Error occurred during conversion
        error("Error: Unsupported unit for conversion.");
        return "";
    }
}
