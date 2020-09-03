#include "bookSaver.h"

void Library::printPrompt() {
    cout << "enter command:> ";
}

string getFileContent(const string &path) {
    ifstream file(path);
    string i_file;

    if (file)
        getline(file, i_file, '\0');
    else
        throw string("invalid book");
    return i_file;
}
