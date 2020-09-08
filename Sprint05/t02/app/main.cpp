#include "src/Draugr.h"
#include "src/misc.h"
#include <iostream>

using namespace std;

static void fourArg(char* argv[], pair<string, string>&& names) {
    int shoutNumber = 0;
    double set = 0;

    try {
        shoutNumber = std::stoi(std::string(argv[1]));
        set = std::stod(std::string(argv[3]));
    }
    catch(...) {
        throw ("error");
    }
    if (shoutNumber < 0 || shoutNumber > 8) {
        throw ("Invalid shoutNumber");
    }
    Draugr dr(set, 50);
    dr.setName(move(names.first));
    dr.shoutPhrase(shoutNumber);
    Draugr dr1(dr);
    dr1.setName(move(names.second));
    dr1.shoutPhrase(shoutNumber);
}

static void fiveArg(char* argv[], pair<string, string>&& names) {
    int shoutNumber = 0;
    double health = 0;
    int frostResist = 0;

    try {
        shoutNumber = std::stoi(std::string(argv[1]));
        health = std::stod(std::string(argv[3]));
        frostResist = std::stoi(std::string(argv[4]));
    }
    catch(...) {
        throw ("Error");
    }
    if (shoutNumber < 0 || shoutNumber > 8) {
        throw ("Invalid shoutNumber");
    }
    Draugr dr(health, frostResist);
    dr.setName(move(names.first));
    dr.shoutPhrase(shoutNumber);
    Draugr dr1(move(dr));
    dr.setName(move(names.second));
    dr.shoutPhrase(shoutNumber);
}

int main(int argc, char *argv[]) {
    try {
        if (argc < 4 || argc > 5) {
            throw("usage: ./draugr [shoutNumber] [name1,name2] [health] [frostResist]");
        }
        else {
            if (argc == 4) {
                fourArg(argv, parce(argc, argv));
            }
            else if (argc == 5) {
                fiveArg(argv, parce(argc, argv));
            }
        }
    }
    catch (const char* ex) {
        cerr << ex << endl;
    }
    return 0;
}