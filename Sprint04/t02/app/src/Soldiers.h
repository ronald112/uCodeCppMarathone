#pragma once

class ImperialSoldier;

class Axe final {
 public:
    Axe(int damage);
    int getDamage() const;
 private:
    const int m_damage;
};

class TheStormcloakSoldier final {
 public:
    TheStormcloakSoldier();
    ~TheStormcloakSoldier();
    void setWeapon(Axe* weapon);
    void attack(ImperialSoldier& enemy);
    void consumeDamage(int amount);
    int getHealth() const;
 private:
    Axe* m_weapon;
    int m_health;
};

//-------------------------------------------

class Sword final {
 public:
    Sword(int damage);
    int getDamage() const;
 private:
    const int m_damage;
};

class ImperialSoldier final {
 public:
    ImperialSoldier();
    ~ImperialSoldier();
    void setWeapon(Sword* weapon);
    void attack(TheStormcloakSoldier& enemy);
    void consumeDamage(int amount);
    int getHealth() const;
 private:
    Sword* m_weapon;
    int m_health;
};
