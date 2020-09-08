#include "Soldiers.h"
#include <string>
#include <iostream>

Soldier::Soldier(std::string&& name, int health) {
    m_name = name;
    m_health = health;
    std::cout << "Soldier " << m_name << " was created\n";
}

ImperialSoldier::ImperialSoldier() : Soldier(std::move("Martin"), 100) {
    std::cout << "Imperial soldier was created" << std::endl;
}

StormcloakSoldier::StormcloakSoldier() : Soldier(std::move("Flynn"), 100) {
    std::cout << "Stormcloak soldier was created" << std::endl;
}

Soldier::~Soldier() {
    std::cout << "Soldier " << m_name << " was deleted" << std::endl;
}

ImperialSoldier::~ImperialSoldier() {
    std::cout << "Imperial soldier was deleted\n";
}

StormcloakSoldier::~StormcloakSoldier() {
    std::cout << "Stormcloak soldier was deleted\n";
}

Weapon::Weapon(int damage) : m_damage(damage) {}

int Weapon::getDamage() const {
    return m_damage;
}

void Soldier::setWeapon(Weapon* weapon) {
    m_weapon = weapon;
}

void Soldier::attack(Soldier& other) {
    std::cout << m_name << " attacks " << other.m_name << " and deals "
        + std::to_string(m_weapon->getDamage()) + " damage" << std::endl;
    other.m_health -= this->m_weapon->getDamage();
}

int Soldier::getHealth() const {
    return m_health;
}
