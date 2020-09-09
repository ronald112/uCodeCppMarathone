#pragma once

#include <string>
#include <set>
#include <iostream>

#include "Creature.h"

namespace Creatures {
    class Redguard final : public Creature {
        public:
        Redguard(const std::string& name) : Creature(name) {};
        void sayPhrase() const {
            std::cout << "I am " << this->getName() << " from Redguards, wanna trade?" << std::endl;
        };
    };
}