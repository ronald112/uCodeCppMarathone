#include "src/Soldiers.h"
#include "src/misc.h"
#include <iostream>

using namespace std;

int main(int argc, char* argv[]) {
    try {
        if (argc != 3) {
            throw("usage: ./imperialVsStormcloak [dmgOfSword] [dmgOfAxe]");
        }
        else {
            chkInput(argv);
            Weapon *sword = new Weapon(std::stoi(std::string(argv[1])));
            Weapon *axe = new Weapon(std::stoi(std::string(argv[2])));
            ImperialSoldier is;
            StormcloakSoldier ss;

            is.setWeapon(sword);
            ss.setWeapon(axe);
            cout << "\n***The battle has begun!***\n" << endl;
            while(is.getHealth() > 0 && ss.getHealth() > 0) {
                ss.attack(is);
                if (is.getHealth() > 0)
                    is.attack(ss);
                cout << "<<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>" << endl;
            }
            if (is.getHealth() > 0) {
                std::cout << "Imperial has won!\n" << std::endl;
            }
            else {
                std::cout << "Stormcloak has won!\n" << std::endl;
            }
        }
    }
    catch(const char* ex) {
        cerr << ex << endl;
    }
    return 0;
}
