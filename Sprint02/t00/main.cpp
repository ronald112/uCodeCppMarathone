#include "uniqueWords.h"

void UniqueWors::iterateFile() {
    ifstream file(path);

    if (file) {
        string str;

        while (file >> str) {
            if (str.back() == '!' || str.back() == ','
                || str.back() == '.' || str.back() == '?')
                str.erase(str.end() - 1);
            words.insert(str);
        }
    }
    else
        throw "error";
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cerr << "usage: ./uniqueWords [file_name]" << endl;
        return 1;
    }
    try {
        UniqueWors uniquewors;
        uniquewors.path = string(argv[1]);
        uniquewors.iterateFile();
        uniquewors.save();
    }
    catch(const char* ex) {
        cerr << "error" << endl;
    }
    return 0;
}
