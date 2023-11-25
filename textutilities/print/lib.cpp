#include <iostream>
#include <map>
#include <string>

using namespace std;

extern "C" string entrypoint(string ws, map<string, string>&options, bool bgMode) {
    string text = options["text"];
    if (!bgMode) cout << text;
    return text;
}
