#pragma once

#include "Container.h"

class Chest final : public Container {
    public:
    Chest(bool isLocked, LockpickDifficulty ld)
        : Container(isLocked, ld) {};
    std::string name() const {
        return "Chest";
    };
};
