#pragma once

#include "Container.h"

class Barrel final : public Container {
    public:
    Barrel() : Container(false, LockpickDifficulty::None) {};
    std::string name() const {
        return "Barrel";
    };
};
