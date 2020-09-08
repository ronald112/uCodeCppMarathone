#include "src/Draugr.h"
#include <iostream>

static void oneArg(char *argv[]) {
    int shoutNumber = 0;

    try {
        shoutNumber = std::stoi(std::string(argv[1]));
    }
    catch(...) {
        throw ("error");
    }
    if (shoutNumber < 0 || shoutNumber > 8) {
        throw ("Invalid shoutNumber");
    }
    Draugr draugr;
    draugr.shoutPhrase(shoutNumber);
}

static void twoArg(char *argv[]) {
    int shoutNumber = 0;
    double set = 0;

    try {
        shoutNumber = std::stoi(std::string(argv[1]));
        set = std::stod(std::string(argv[2]));
    }
    catch(...) {
        throw ("error");
    }
    if (shoutNumber < 0 || shoutNumber > 8) {
        throw ("Invalid shoutNumber");
    }
    Draugr dr(set, 50);
    dr.shoutPhrase(shoutNumber);
    Draugr dr1(set);
    dr1.shoutPhrase(shoutNumber);
}

static void threeArg(char *argv[]) {
    int shoutNumber = 0;
    double health = 0;
    int frostResist = 0;

    try {
        shoutNumber = std::stoi(std::string(argv[1]));
        health = std::stod(std::string(argv[2]));
        frostResist = std::stoi(std::string(argv[3]));
    }
    catch(...) {
        throw ("Error");
    }
    if (shoutNumber < 0 || shoutNumber > 8) {
        throw ("Invalid shoutNumber");
    }
    Draugr draugr(health, frostResist);
    draugr.shoutPhrase(shoutNumber);
}

int main(int argc, char *argv[]) {
    try {
        if (argc < 2 || argc > 4) {
            std::cerr << "usage: ./draugr [shoutNumber] [health] [frostResist]\n";
        }
        else if (argc == 2) {
            oneArg(argv);
        }
        else if (argc == 3) {
            twoArg(argv);
        }
        else if (argc == 4) {
            threeArg(argv);
        }
    }
    catch (const char* ex) {
        std::cerr << ex << std::endl;
    }
    return 0;
}