#include <iostream>
#include <map>
#include <string>
#include <shfl.h>

using namespace std;

// Function to convert energy units
double convertEnergy(double value, const string& from_unit, const string& to_unit) {
    const double joules_to_kilocalories = 1.0 / 4184;

    double result = 0.0;

    // Convert input value to joules
    if (from_unit == "kilocalories") {
        result = value / joules_to_kilocalories;
    } else if (from_unit == "joules") {
        result = value;
    } else {
        cerr << "Error: Unsupported unit for conversion." << endl;
        return -1.0;  // Indicate error
    }

    // Convert from joules to the desired unit
    if (to_unit == "kilocalories") {
        result *= joules_to_kilocalories;
    } else if (to_unit != "joules") {
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

    // Perform energy conversion
    double result = convertEnergy(value, from_unit, to_unit);

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
