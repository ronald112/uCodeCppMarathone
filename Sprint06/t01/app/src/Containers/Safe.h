#pragma once

#include "Container.h"

class Safe final : public Container {
    public:
    Safe(bool isLocked, LockpickDifficulty ld)
        : Container(isLocked, ld) {};
    std::string name() const {
        return "Safe";
    };
};
