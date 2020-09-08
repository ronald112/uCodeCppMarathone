#include "Soldiers.h"
#include <string>
#include <iostream>

ImperialSoldier::ImperialSoldier() {
    m_health = 100;
}

ImperialSoldier::~ImperialSoldier() {
    delete m_weapon;
}

Sword::Sword(int damage) : m_damage(damage){}

int Sword::getDamage() const {
    return m_damage;
}

void ImperialSoldier::setWeapon(Sword* weapon) {
    m_weapon = weapon;
}

void ImperialSoldier::attack(TheStormcloakSoldier& enemy) {
    std::cout << "Imperial soldier attacks and deals " + std::to_string(m_weapon->getDamage()) + " damage" << std::endl;
    enemy.consumeDamage(m_weapon->getDamage());
}

void ImperialSoldier::consumeDamage(int amount) {
    m_health -= amount;
    std::cout << "Imperial soldier consumes " + std::to_string(amount) + " of damage";
    if (m_health <= 0) {
        std::cout << " and dies";
    }
}

int ImperialSoldier::getHealth() const {
    return m_health;
}
