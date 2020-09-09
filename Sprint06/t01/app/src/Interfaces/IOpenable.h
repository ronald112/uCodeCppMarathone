#pragma once

#include <Containers/LockpickDifficulty.h>

class IOpenable {
    public:
    virtual bool tryToOpen(LockpickDifficulty) = 0;
    virtual ~IOpenable() = default;
};