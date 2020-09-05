#include "src/misc.h"

int main(int argc, char *argv[]) {
    if (argc != 3) {
        std::cerr << "usage: ./imperialVsStormcloak [dmgOfSword] [dmgOfAxe]\n";
    }
    else {
        ImperialSoldier is;
        TheStormcloakSoldier ss;
        if (setWeapon(is, ss, argv) == false) {
            exit(1);
        }

        while(is.getHealth() > 0 && ss.getHealth() > 0) {
            is.attack(ss);
            ss.attack(is);
            printBattle(is, ss, std::stoi(argv[1]), std::stoi(argv[2]));
            std::cout << "\n<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>" << std::endl;
        }
        if (is.getHealth() > 0) {
            std::cout << "Imperial has won!\n";
        }
        else {
            std::cout << "Stormcloak has won!\n";
        }
    }
    return 0;
}