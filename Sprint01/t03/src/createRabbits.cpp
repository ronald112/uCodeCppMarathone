#include "vampireRabbits.h"

// 1 + rand() % 3 от 1 до 3х

Rabbit MyRabbits::m_createRabbit() {
    Rabbit rabbit;

    if ((rand() % 100) == 1) {
        rabbit.isVampire = true;
        vampires++;
    }
    else {
        rabbit.isVampire = false;
        if ((rand() % 100) > 50) {
            rabbit.gender = Gender::Male;
            males++;
        }
        else {
            rabbit.gender = Gender::Female;
            females++;
        }
    }
    rabbit.age = 0;
    return rabbit;
}

MyRabbits::MyRabbits() {
    for (int i = 0; i < 10; i++) {
        m_rabbits.push_back(m_createRabbit());
    }
}

void MyRabbits::createVampires() {
    int n_vamp = vampires;

    for (auto& i : m_rabbits) {
        if (n_vamp <= 0)
            break;
        if (i.isVampire == false) {
            i.isVampire = true;
            zombies++;
            if (i.gender == Gender::Male)
                males--;
            else
                females--;
            n_vamp--;
        }
    }
}

void MyRabbits::createRabbits() {
    int num = males < females ? males : females;
    for (int i = 0; i < num; i++) {
        m_rabbits.push_back(m_createRabbit());
    }
}
