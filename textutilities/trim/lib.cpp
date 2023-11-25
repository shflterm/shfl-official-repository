#include <iostream>
#include <map>
#include <string>

using namespace std;

const string WHITESPACE = " \n\r\t\f\v";

string ltrim(const string&s) {
    const size_t start = s.find_first_not_of(WHITESPACE);
    return start == string::npos ? "" : s.substr(start);
}

string rtrim(const string&s) {
    const size_t end = s.find_last_not_of(WHITESPACE);
    return end == string::npos ? "" : s.substr(0, end + 1);
}

string trim(const string&s) { return rtrim(ltrim(s)); }

extern "C" string entrypoint(string ws, map<string, string>&options, bool bgMode) {
    string text = trim(options["text"]);
    if (!bgMode) cout << text << endl;
    return text;
}
