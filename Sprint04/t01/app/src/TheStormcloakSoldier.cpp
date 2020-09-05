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
    enemy.consumeDamage(m_weapon->getDamage());
}

void TheStormcloakSoldier::consumeDamage(int amount) {
    m_health -= amount;
}

int TheStormcloakSoldier::getHealth() const {
    return m_health;
}
