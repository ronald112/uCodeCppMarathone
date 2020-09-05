#pragma once

#include "Soldiers.h"
#include <string>
#include <iostream>

void printBattle(const ImperialSoldier& is, const TheStormcloakSoldier& ss, int idmg, int sdmg);
bool setWeapon(ImperialSoldier& is, TheStormcloakSoldier& ss, char *argv[]);