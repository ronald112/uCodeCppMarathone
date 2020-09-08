#include "Soldiers.h"
#include <iostream>

void chkInput(char *argv[]) {
    int idmg = 0;
    int sdmg = 0;

    try {
        idmg = std::stoi(std::string(argv[1]));
        sdmg = std::stoi(std::string(argv[2]));
    }
    catch(...) {
        throw("Damage has to be in a range of 10-20 points.");
    }
    if (idmg < 10 || idmg > 20 || sdmg < 10 || sdmg > 20) {
        throw("Damage has to be in a range of 10-20 points.");
    }
}
