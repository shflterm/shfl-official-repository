#include <iostream>
#include <map>
#include <string>

using namespace std;

#ifdef _WIN32
#define EXPORT __declspec(dllexport)
#else
#define EXPORT
#endif

extern "C" EXPORT string entrypoint(string ws, map<string, string>&options, bool bgMode) {
    string text = options["text"];
    text[0] = toupper(text[0]);
    if (!bgMode) cout << text << endl;
    return text;
}
