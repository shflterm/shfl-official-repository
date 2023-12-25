#include <iostream>
#include <map>
#include <string>
#include <iomanip>
#include <shfl.h>

using namespace std;

// Function to convert length units
double convertLength(double value, const string& from_unit, const string& to_unit) {
    const double meters_per_foot = 0.3048;
    const double meters_per_mile = 1609.34;
    const double meters_per_kilometer = 1000.0;

    double result = 0.0;

    // Convert input value to meters
    if (from_unit == "feet") {
        result = value * meters_per_foot;
    } else if (from_unit == "miles") {
        result = value * meters_per_mile;
    } else if (from_unit == "kilometers") {
        result = value * meters_per_kilometer;
    } else if (from_unit == "meters") {
        result = value;
    } else {
        cerr << "Error: Unsupported unit for conversion." << endl;
        return -1.0;  // Indicate error
    }

    // Convert from meters to the desired unit
    if (to_unit == "feet") {
        result /= meters_per_foot;
    } else if (to_unit == "miles") {
        result /= meters_per_mile;
    } else if (to_unit == "kilometers") {
        result /= meters_per_kilometer;
    } else if (to_unit != "meters") {
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

    // Perform length conversion
    double result = convertLength(value, from_unit, to_unit);

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
