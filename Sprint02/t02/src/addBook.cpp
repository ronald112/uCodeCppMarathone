#include "bookSaver.h"

void Library::addBook(const string& str) {
    string full_path = "./library/" + str;
    books.insert(make_pair(str, getFileContent(full_path)));
    cout << str << " added" << endl;
}
