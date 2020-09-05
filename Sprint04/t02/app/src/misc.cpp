#include "Soldiers.h"
#include <string>
#include <iostream>

// Imperial soldier attacks and deals 20 damage$
// Stormcloak soldier consumes 20 of damage$
// Stormcloak soldier attacks and deals 18 damage$
// Imperial soldier consumes 18 of damage$
// <<<<<<<<<<<<<<<<<<<<<<<<<>>>>>>>>>>>>>>>>>>>>>>>>>

bool setWeapon(ImperialSoldier& is, TheStormcloakSoldier& ss, char *argv[]) {
    int idmg = std::stoi(std::string(argv[1]));
    int sdmg = std::stoi(std::string(argv[2]));

    if (idmg < 10 || idmg > 20 || sdmg < 10 || sdmg > 20) {
        std::cerr << "Damage has to be in a range of 10-20 points.\n";
        return false;
    }
    Sword *sword = new Sword(idmg);
    Axe *axe = new Axe(sdmg);

    is.setWeapon(sword);
    ss.setWeapon(axe);
    return true;
}



void printBattle(const ImperialSoldier& is, const TheStormcloakSoldier& ss, int idmg, int sdmg) {
    std::cout << "Imperial soldier attacks and deals " + std::to_string(idmg) + " damage" << std::endl;
    std::cout << "Stormcloak soldier consumes " + std::to_string(idmg) + " of damage";
    if (ss.getHealth() <= 0) {
        std::cout << " and dies";
        return;
    }
    std::cout << std::endl;
    std::cout << "Stormcloak soldier attacks and deals " + std::to_string(sdmg) + " damage" << std::endl;
    std::cout << "Imperial soldier consumes " + std::to_string(sdmg) + " of damage";
    if (is.getHealth() <= 0) {
        std::cout << " and dies";
        return;
    }
}