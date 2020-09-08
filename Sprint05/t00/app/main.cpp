#include "src/Draugr.h"
#include <iostream>

int main(int argc, char *argv[]) {
    if (argc != 2) {
        std::cerr << "usage: ./draugr [shoutNumber]\n";
    }
    else {
        Draugr draugr;

        try {
            draugr.shoutPhrase(std::stoi(std::string(argv[1])));
        }
        catch(...) {
            std::cerr << "Invalid shoutNumber" << std::endl;
        }
    }
    return 0;
}