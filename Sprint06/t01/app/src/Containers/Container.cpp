#include "Container.h"

Container::Container(bool isLocked, const LockpickDifficulty difficulty)
    : m_isLocked(isLocked), m_difficulty(difficulty) {}

LockpickDifficulty Container::lockDifficulty() const {
    return m_difficulty;
}
bool Container::isLocked() const {
    return m_isLocked;
}
bool Container::tryToOpen(LockpickDifficulty skill) {
    if (skill < m_difficulty) {
        return false;
    }
    else {
        m_isLocked = true;
        return true;
    }
}
