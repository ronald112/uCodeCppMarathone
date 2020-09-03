#include "bookSaver.h"

void Library::deleteBook(const string& str) {
    auto book = books.find(str);

    if (book != books.end())
        books.erase(book);
    else
        throw string("invalid book");
    if (remove(("./library/" + str).c_str()) == 0)
        cout << str << " deleted" << endl;
    else
        throw string("invalid book");
}
