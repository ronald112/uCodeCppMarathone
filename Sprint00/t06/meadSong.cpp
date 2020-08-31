#include "meadSong.h"

void setupStrings(string& bottle, string& where, string& take_one) {
    bottle = "bottles of mead";
    where = "on the wall";
    take_one = "Take one down and pass it around,";
}

void printPoem(string& bottle, string& where, string& take_one, int num) {
    for (int i = num - 1; i > 0;) {
        if (i == 1) {
            cout << i << " bottle of mead " + where + ", "
                << i << " bottle of mead." << endl;
            cout << "Take it down and pass it around, ";
        }
        else {
            cout << i << " " + bottle + " " + where + ", "
                << i << " " + bottle + "." << endl;
            cout << take_one + " ";
        }
        if (--i == 0)
            cout << "no more " + bottle + " " + where + "." << endl;
        else
            cout << i << " " + bottle + " " + where + "." << endl;
    }
    cout << "No more " + bottle + " " + where + ",";
    cout << "no more " + bottle + "." << endl;
    cout << "Go to the store and buy some more, 99 ";
    cout << bottle + " " + where + "." << endl;
}
