#include "stdAlgoV2.h"

// l.remove_if([](int n){ return n > 10; }); // remove all elements greater than 10
void NamesFeature::changeList() {
    names.remove_if([](const string &str) {
        return find_if(str.begin(), str.end(), [](const char &c) {
            return (c == 'c' || c == 'b' || c == 'l');
        }) != str.end();
    });
    replace_if(names.begin(), names.end(), [](const string& str) {
        return str.size() > 10;
    }, "Long one");
    replace_if(names.begin(), names.end(), [](const string& str) {
        return str.size() < 4;
    }, "Short one");
    names.unique();
    names.sort();
    names.reverse();
}

void NamesFeature::iterateFile() {
    ifstream file(path);

    if (file) {
        string str;

        while (getline(file, str, '\n')) {
            names.push_front(str);
        }
    }
    else
        throw "error";
}

int main(int argc, char* argv[]) {
    if (argc != 2) {
        cerr << "usage: ./stdAlgoV1 [file_name]" << endl;
        return 1;
    }
    try {
        NamesFeature namesfeature;

        namesfeature.path = string(argv[1]);
        namesfeature.iterateFile();
        namesfeature.changeList();
        namesfeature.save();
    }
    catch(const char* ex) {
        cerr << "error" << endl;
    }
    return 0;
}
