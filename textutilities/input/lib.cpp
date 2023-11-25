#include <iostream>
#include <map>
#include <string>

using namespace std;

extern "C" string entrypoint(string ws, map<string, string>&options, bool bgMode) {
    string input;
    getline(cin, input);
    if (!bgMode) cout << input << endl;
    return input;
}
