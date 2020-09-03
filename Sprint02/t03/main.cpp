#include "tesLibrary.h"

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cerr << "usage: ./tesLibrary [file_name]" << endl;
        return 1;
    }
    try {
        regex pattern("\\s*"
                    "\"(.+)\""
                    "\\s*:\\s*"
                    "\"(.+)\""
                    "\\s*$");
        multimap<string, string> library;
        ifstream file(argv[1]);

        if (file.fail())
            throw string("error");
        readFile(file, library, pattern);
        printFile(library);
    }
    catch(const string& ex) {
        cerr << ex << endl;
    }
}
