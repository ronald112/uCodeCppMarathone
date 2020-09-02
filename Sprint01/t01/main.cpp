#include "moveAlong.h"

string toLower(const string& str) {
    string low_str;
    for (const auto& c : str) {
        low_str += tolower(c);
    }
    return low_str;
}

vector<string> createArray(int argc, char* argv[]) {
    vector<string> arr;

    for (int i = 1; i < argc; i++) {
        string lower(toLower(string(argv[i])));

        if (lower.find("mercer") != string::npos
            || lower.find("emer") != string::npos
            || lower.find("jim") != string::npos) {
            arr.push_back(string(argv[i]));
        }
    }
    return arr;
}

int main(int argc, char* argv[]) {
    if (argc == 1) {
        cerr << "usage: ./moveAlong [args]" << endl;
        return 1;
    }
    for (string i : createArray(argc, argv)) {
        cout << i + ", move along!" << endl;
    }
    return 0;
}
