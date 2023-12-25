#include <iostream>
#include <map>
#include <string>
#include <shfl.h>

using namespace std;

// Function to convert data volume units
double convertDataVolume(double value, const string& from_unit, const string& to_unit) {
    const double bytes_to_kilobytes = 1.0 / 1024;
    const double kilobytes_to_megabytes = 1.0 / 1024;
    const double megabytes_to_gigabytes = 1.0 / 1024;
    const double gigabytes_to_terabytes = 1.0 / 1024;

    double result = 0.0;

    // Convert input value to bytes
    if (from_unit == "kilobytes") {
        result = value / bytes_to_kilobytes;
    } else if (from_unit == "megabytes") {
        result = value / bytes_to_kilobytes / kilobytes_to_megabytes;
    } else if (from_unit == "gigabytes") {
        result = value / bytes_to_kilobytes / kilobytes_to_megabytes / megabytes_to_gigabytes;
    } else if (from_unit == "terabytes") {
        result = value / bytes_to_kilobytes / kilobytes_to_megabytes / megabytes_to_gigabytes / gigabytes_to_terabytes;
    } else if (from_unit == "bytes") {
        result = value;
    } else {
        cerr << "Error: Unsupported unit for conversion." << endl;
        return -1.0;  // Indicate error
    }

    // Convert from bytes to the desired unit
    if (to_unit == "kilobytes") {
        result *= bytes_to_kilobytes;
    } else if (to_unit == "megabytes") {
        result *= bytes_to_kilobytes * kilobytes_to_megabytes;
    } else if (to_unit == "gigabytes") {
        result *= bytes_to_kilobytes * kilobytes_to_megabytes * megabytes_to_gigabytes;
    } else if (to_unit == "terabytes") {
        result *= bytes_to_kilobytes * kilobytes_to_megabytes * megabytes_to_gigabytes * gigabytes_to_terabytes;
    } else if (to_unit != "bytes") {
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

    // Perform data volume conversion
    double result = convertDataVolume(value, from_unit, to_unit);

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
