#include <iostream>
#include <map>
#include <string>

using namespace std;

extern "C" string entrypoint(string ws, map<string, string>&options, bool bgMode) {
    string text = options["text"];
    text[0] = toupper(text[0]);
    if (!bgMode) cout << text << endl;
    return text;
}
