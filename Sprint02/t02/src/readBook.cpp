#include "bookSaver.h"

void Library::readBook(const string& str) {
    try {
        cout << books.at(str) << endl;
    }
    catch(const exception& ex) {
        throw string("invalid book");
    }
}
