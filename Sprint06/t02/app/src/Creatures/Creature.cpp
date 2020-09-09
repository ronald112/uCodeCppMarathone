#include "Creature.h"

static void coutSpellName(const Spells::SpellType& spell) {
    switch (spell) {
    case Spells::SpellType::Healing: std::cout << "healing"; break;
    case Spells::SpellType::Equilibrium: std::cout << "equilibrium"; break;
    case Spells::SpellType::Flames: std::cout << "flames"; break;
    case Spells::SpellType::Freeze: std::cout << "freeze"; break;
    case Spells::SpellType::Fireball: std::cout << "fireball"; break;
    }
}

Creatures::Creature::Creature(const std::string& name) : m_name(name), m_health(100), m_mana(100) {
    std::cout << m_name << " was born!" << std::endl;
}

Creatures::Creature::~Creature() {
    for (auto& i : m_spells) {
        delete i;
    }
}

void Creatures::Creature::learnSpell(Spells::ISpell* spell) {
    if (m_spells.count(spell) != 0) {
        std::cout << m_name << " already knows the ";
        coutSpellName(spell->getType());
        std::cout << " spell!" << std::endl;
    }
    else {
        m_spells.insert(spell);
        std::cout << m_name << " has learned the ";
        coutSpellName(spell->getType());
        std::cout << " spell successfully!" << std::endl;
    }
}

void Creatures::Creature::castSpell(const Spells::SpellType type, Creature& creature) {
    for (const auto& i : m_spells) {
        if (i->getType() == type) {
            if ((i->cast(*this, creature)) == true) {
                std::cout << m_name << " has cast the ";
                coutSpellName(type);
                std::cout << " spell on " << creature.getName() << "!" << std::endl;;
            }
            else {
                std::cout << m_name << " can't cast the ";
                coutSpellName(type);
                std::cout << "!" << std::endl;
            }
            return;
        }
    }
    std::cout << m_name << " doesn't know the ";
    coutSpellName(type);
    std::cout << " spell." << std::endl;
}

std::string Creatures::Creature::getName() const {
    return m_name;
}
int Creatures::Creature::getHealth() const {
    return m_health;
}
int Creatures::Creature::getMana() const {
    return m_mana;
}

void Creatures::Creature::setHealth(int health) {
    m_health = health;
    if (m_health > 100)
        m_health = 100;
    else if (m_health < 0)
        m_health = 0;
}

void Creatures::Creature::setMana(int mana) {
    m_mana = mana;
    if (m_mana > 100)
        m_mana = 100;
    else if (m_mana < 0)
        m_mana = 0;
}

std::ostream& operator<<(std::ostream& os, const Creatures::Creature& creature) {
    return os << creature.getName() << " : " << creature.getHealth() << " HP, " << creature.getMana() << " MP.";
}

