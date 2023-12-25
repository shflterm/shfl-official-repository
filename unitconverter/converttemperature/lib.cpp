#include <iostream>
#include <map>
#include <string>
#include <shfl.h>

using namespace std;

// Function to convert temperature units
double convertTemperature(double value, const string& from_unit, const string& to_unit) {
    double result = 0.0;

    if (from_unit == "celsius" && to_unit == "fahrenheit") {
        // Celsius to Fahrenheit conversion
        result = (value * 9 / 5) + 32;
    } else if (from_unit == "fahrenheit" && to_unit == "celsius") {
        // Fahrenheit to Celsius conversion
        result = (value - 32) * 5 / 9;
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

    // Perform temperature conversion
    double result = convertTemperature(value, from_unit, to_unit);

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
