#include "Soldiers.h"
#include <string>
#include <iostream>

TheStormcloakSoldier::TheStormcloakSoldier() {
    m_health = 100;
}

TheStormcloakSoldier::~TheStormcloakSoldier() {
    delete m_weapon;
}

Axe::Axe(int damage) : m_damage(damage){}

int Axe::getDamage() const {
    return m_damage;
}

void TheStormcloakSoldier::setWeapon(Axe* weapon) {
    m_weapon = weapon;
}

void TheStormcloakSoldier::attack(ImperialSoldier& enemy) {
    std::cout << "Stormcloak soldier attacks and deals "
        + std::to_string(m_weapon->getDamage()) + " damage" << std::endl;
    enemy.consumeDamage(m_weapon->getDamage());
}

void TheStormcloakSoldier::consumeDamage(int amount) {
    m_health -= amount;
    std::cout << "Stormcloak soldier consumes " + std::to_string(amount) + " of damage";
    if (m_health <= 0) {
        std::cout << " and dies";
    }
}

int TheStormcloakSoldier::getHealth() const {
    return m_health;
}
