#include "stdAlgoV1.h"

void NamesFeature::check_line(const string& str) {
    if (str.find("rich") != string::npos)
        rich = true;
    if (str.find("mel") == string::npos)
        mel_amount++;
    size_t pos;
    if ((pos = str.find("vel")) != string::npos) {
        if (str[pos + 3] == '\0') {
            all_end_vel++;
        }
    }
    if (str.size() == 15)
        big_lengths = false;
    size++;
}

void NamesFeature::iterateFile() {
    ifstream file(path);

    if (file) {
        string str;

        while (getline(file, str)) {
            check_line(str);
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
        namesfeature.print();
    }
    catch(const char* ex) {
        cerr << "error" << endl;
    }
    return 0;
}
