#include <iostream>
#include <string>

using namespace std;

void checkLine(const string& str, size_t i) {
    if (str[i] != '\0') {
        throw("error");
    }
}

int main(int argc, char* argv[]) {
    if (argc != 5)
        cerr << "usage:./automaton [name] [level] [health] [stamina]\n";
    else {
        auto i = 1;
        try {
            auto index = 0ul;
            auto name = string(argv[i]);
            auto lvl = stoi(argv[++i], &index);
            checkLine(string(argv[i]), index);
            auto health = stof(argv[++i], &index);
            checkLine(string(argv[i]), index);
            auto stamina = stod(argv[++i], &index);
            checkLine(string(argv[i]), index);
            cout << "Name = " << name << endl;
            cout << "Level = " << lvl << endl;
            cout << "Health = " << health << endl;
            cout << "Stamina = " << stamina << endl;
        }
        catch (const exception& ex) {
            cerr << "Invalid argument " << argv[i] << endl;
        }
    }
    return 0;
}
