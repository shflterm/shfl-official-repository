#include <iostream>
#include <map>
#include <string>
#include <shfl.h>

using namespace std;

// Function to convert speed units
double convertSpeed(double value, const string& from_unit, const string& to_unit) {
    const double kilometers_per_hour_to_miles_per_hour = 0.621371;
    const double kilometers_per_hour_to_knots = 0.539957;
    const double meters_per_second_to_kilometers_per_hour = 3.6;
    const double feet_per_second_to_meters_per_second = 0.3048;

    double result = 0.0;

    // Convert input value to kilometers per hour
    if (from_unit == "miles_per_hour") {
        result = value / kilometers_per_hour_to_miles_per_hour;
    } else if (from_unit == "kilometers_per_hour") {
        result = value;
    } else if (from_unit == "knots") {
        result = value / kilometers_per_hour_to_knots;
    } else if (from_unit == "meters_per_second") {
        result = value * meters_per_second_to_kilometers_per_hour;
    } else if (from_unit == "feet_per_second") {
        result = value / feet_per_second_to_meters_per_second / meters_per_second_to_kilometers_per_hour;
    } else {
        cerr << "Error: Unsupported unit for conversion." << endl;
        return -1.0;  // Indicate error
    }

    // Convert from kilometers per hour to the desired unit
    if (to_unit == "miles_per_hour") {
        result *= kilometers_per_hour_to_miles_per_hour;
    } else if (to_unit == "kilometers_per_hour") {
        result = value;
    } else if (to_unit == "knots") {
        result *= kilometers_per_hour_to_knots;
    } else if (to_unit == "meters_per_second") {
        result /= meters_per_second_to_kilometers_per_hour;
    } else if (to_unit == "feet_per_second") {
        result *= feet_per_second_to_meters_per_second * meters_per_second_to_kilometers_per_hour;
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

    // Perform speed conversion
    double result = convertSpeed(value, from_unit, to_unit);

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
