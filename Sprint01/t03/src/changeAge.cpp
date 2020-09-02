#include "vampireRabbits.h"

void MyRabbits::changeAge() {
    for (auto& i : m_rabbits) {
        i.age++;
    }
}

void MyRabbits::deleteOld() {
    for (auto i = m_rabbits.begin(); i != m_rabbits.end();) {
        if ((*i).isVampire == false && (*i).age > 3) {
            if ((*i).gender == Gender::Female)
                females > 0 ? females-- : females = 0;
            else
                males > 0 ? males-- : males = 0;
            i = m_rabbits.erase(i);
        }
        else if ((*i).isVampire == true && (*i).age > 8) {
            i = m_rabbits.erase(i);
            vampires > 0 ? vampires-- : vampires = 0;
        }
        else
            ++i;
    }
}
