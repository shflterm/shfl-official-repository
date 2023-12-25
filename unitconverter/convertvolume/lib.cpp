#include <iostream>
#include <map>
#include <string>
#include <iomanip>
#include <shfl.h>

using namespace std;

// Function to convert volume units
double convertVolume(double value, const string& from_unit, const string& to_unit) {
    const double liters_per_gallon = 3.78541;

    double result = 0.0;

    // Convert input value to liters
    if (from_unit == "gallons") {
        result = value * liters_per_gallon;
    } else if (from_unit == "liters") {
        result = value;
    } else {
        cerr << "Error: Unsupported unit for conversion." << endl;
        return -1.0;  // Indicate error
    }

    // Convert from liters to the desired unit
    if (to_unit == "gallons") {
        result /= liters_per_gallon;
    } else if (to_unit != "liters") {
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

    // Perform volume conversion
    double result = convertVolume(value, from_unit, to_unit);

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
