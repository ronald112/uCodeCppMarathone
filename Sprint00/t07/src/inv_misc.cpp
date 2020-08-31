#include "inv.h"

void Inv::printPrompt() {
    cout << "Enter command:> ";
}

void Inv::help() {
    cout << "Available commands:\n"
            "1. insert <itemType>\n"
            "2. remove <itemType>\n"
            "3. show inventory\n"
            "4. help\n"
            "5. exit" << endl;
}



