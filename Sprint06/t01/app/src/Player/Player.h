#pragma once
#include <Containers/LockpickDifficulty.h>
#include <iostream>
#include <string>

class Player final {
    public:
    explicit Player(const std::string& name) : m_name(name) {};

    void openContainer(Container* container) {
        if (container != nullptr) {
            if (container->tryToOpen(m_lockpickSkill) == true) {
                std::cout << m_name << " successfully opened " << container->name() << std::endl;
            }
            else {
                std::cout << m_name << " skill is too low to open " << container->name() << std::endl;
            }
        }
    };

    void setLockpickSkill(LockpickDifficulty skill) {
        m_lockpickSkill = skill;
    };

    private:
    LockpickDifficulty m_lockpickSkill{LockpickDifficulty::None};
    std::string m_name;
};