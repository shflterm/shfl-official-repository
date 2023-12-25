#include <iostream>
#include <map>
#include <string>
#define _USE_MATH_DEFINES
#include <cmath>
#include <shfl.h>

using namespace std;

// Function to convert angle units
double convertAngle(double value, const string& from_unit, const string& to_unit) {
    constexpr double degrees_to_radians = M_PI / 180;

    double result = 0.0;

    // Convert input value to degrees
    if (from_unit == "radians") {
        result = value / degrees_to_radians;
    } else if (from_unit == "degrees") {
        result = value;
    } else {
        cerr << "Error: Unsupported unit for conversion." << endl;
        return -1.0;  // Indicate error
    }

    // Convert from degrees to the desired unit
    if (to_unit == "radians") {
        result *= degrees_to_radians;
    } else if (to_unit != "degrees") {
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

    // Perform angle conversion
    double result = convertAngle(value, from_unit, to_unit);

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
