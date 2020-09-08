#pragma once

#include <string>

/* Weapon.h */
class Weapon {
public:
    explicit Weapon(int damage);
    virtual ~Weapon() = default;
    int getDamage() const;
private:
    const int m_damage;
};

class Soldier {
public:
    Soldier(std::string&& name, int health);
    virtual ~Soldier();
    void attack(Soldier& other);
    void setWeapon(Weapon* weapon);
    int getHealth() const;
private:
    Weapon* m_weapon{nullptr};
    std::string m_name;
    int m_health;
};

class ImperialSoldier final : public Soldier {
public:
    ImperialSoldier();
    ~ImperialSoldier();
};

class StormcloakSoldier final : public Soldier {
public:
    StormcloakSoldier();
    ~StormcloakSoldier();
};
