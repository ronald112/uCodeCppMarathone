#include "tesLibrary.h"

void printFile(const multimap<string, string>& library) {
    string unique_author;
    unsigned book_cnt = 1;

    for (const auto& i : library) {
        if (unique_author != i.first) {
            unique_author = i.first;
            book_cnt = 1;
            cout << unique_author << ":" << endl;
        }
        cout << book_cnt++ << ": " << i.second << endl;
    }
}

void readFile(ifstream& file, multimap<string, string>& library, const regex& pattern) {
    unsigned line = 1;

    for (string i_str; getline(file, i_str); line++) {
        cmatch match;

        if (i_str.size() == 0)
            continue;
        if (regex_match(i_str.c_str(), match, pattern)) {
            library.insert({match.str(1), match.str(2)});
        }
        else {
            throw string("Line " + to_string(line) + " is invalid");
        }
    }
}
