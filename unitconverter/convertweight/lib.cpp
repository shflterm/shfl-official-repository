#include <iostream>
#include <map>
#include <string>
#include <iomanip>
#include <shfl.h>

using namespace std;

// Function to convert weight units
double convertWeight(double value, const string& from_unit, const string& to_unit) {
    const double kilograms_per_pound = 0.453592;

    double result = 0.0;

    // Convert input value to kilograms
    if (from_unit == "pounds") {
        result = value * kilograms_per_pound;
    } else if (from_unit == "kilograms") {
        result = value;
    } else {
        cerr << "Error: Unsupported unit for conversion." << endl;
        return -1.0;  // Indicate error
    }

    // Convert from kilograms to the desired unit
    if (to_unit == "pounds") {
        result /= kilograms_per_pound;
    } else if (to_unit != "kilograms") {
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

    // Perform weight conversion
    double result = convertWeight(value, from_unit, to_unit);

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
