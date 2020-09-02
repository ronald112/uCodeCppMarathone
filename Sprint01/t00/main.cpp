#include "simpleSort.h"

array<string, 5> createArray(char* argv[]) {
    array<string, 5> arr;

    argv++;
    for (string& i : arr) {
        i = string(*argv);
        argv++;
    }
    sort(arr.begin(), arr.end());
    return arr;
}

int main(int argc, char* argv[]) {
    if (argc != 6) {
        cerr << "usage: ./simpleSort arg1 arg2 arg3 arg4 arg5" << endl;
        return 1;
    }
    bool first = true;
    for (const string& str : createArray(argv)) {
        if (first == false) {
            cout << " ";
        }
        cout << str;
        first = false;
    }
    cout << endl;
    return 0;
}
