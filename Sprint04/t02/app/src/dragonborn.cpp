#include "dragonborn.h"
#include "misc.h"
#include <iostream>

void Dragonborn::executeAction(const Actions action) {
    const std::map<Actions, void (Dragonborn::*)() const> ptr_to_out {
        {Actions::Shout, &Dragonborn::shoutThuum},
        {Actions::Magic, &Dragonborn::attackWithMagic},
        {Actions::Weapon, &Dragonborn::attackWithWeapon}
    };

    std::invoke(ptr_to_out.at(action), this);
}

void Dragonborn::shoutThuum() const {
    std::cout << "Yol Toor Shul" << std::endl;
}

void Dragonborn::attackWithMagic() const {
    std::cout << "*attacks with magic spell*" << std::endl;
}

void Dragonborn::attackWithWeapon() const {
    std::cout << "*attacks with weapon*" << std::endl;
}
