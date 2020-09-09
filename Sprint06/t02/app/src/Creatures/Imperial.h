#pragma once

#include <string>
#include <set>
#include <iostream>

#include "Creature.h"

namespace Creatures {
    class Imperial final : public Creature {
        public:
        Imperial(const std::string& name) : Creature(name) {};
        void sayPhrase() const {
            std::cout << "I am " << this->getName() << ", Imperial soldier! Stop right here!" << std::endl;
        };
    };
}