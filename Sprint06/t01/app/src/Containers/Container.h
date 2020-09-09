#pragma once

#include <Interfaces/ILockable.h>
#include <Interfaces/IOpenable.h>
#include <string>
#include "LockpickDifficulty.h"

class Container : public ILockable, public IOpenable {
    public:
    Container(bool isLocked, const LockpickDifficulty difficulty)
        : m_isLocked(isLocked), m_difficulty(difficulty) {};
    virtual ~Container() = default;

    LockpickDifficulty lockDifficulty() const {
        return m_difficulty;
    };
    bool isLocked() const {
       return m_isLocked;
    };
    bool tryToOpen(LockpickDifficulty skill) {
        if (skill < m_difficulty) {
            return false;
        }
        else {
            m_isLocked = true;
            return true;
        }
    };

    virtual std::string name() const = 0;

    private:
    bool m_isLocked{false};
    LockpickDifficulty m_difficulty;
};
