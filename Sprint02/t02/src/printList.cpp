#include "bookSaver.h"

void Library::showLibrary() {
    bool first = false;

    for (const auto& i : books) {
        if (first == true)
            cout << endl;
        first = true;
        cout << i.first << endl;
    }
}
