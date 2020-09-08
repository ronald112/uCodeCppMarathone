#include "Draugr.h"
#include <map>
#include <iostream>

using namespace std;

Draugr::Draugr(double health, int frostResist) : m_health(health), m_frostResist(frostResist) {
    cout << "Draugr with " << health << " health and " << frostResist << "% frost resist was born" << endl;
}

void Draugr::setName(const std::string&& name) {
    m_name = name;
}

Draugr::Draugr(Draugr& other) : m_health(other.m_health), m_frostResist(other.m_frostResist), m_name(other.m_name) {
    cout << "Draugr with " << m_health << " health and " << m_frostResist << "% frost resist was born" << endl;
    cout << "Copy constructor was called" << endl;
}

Draugr::Draugr(Draugr&& other)
    : m_health(other.m_health), m_frostResist(other.m_frostResist), m_name(move(other.m_name)) {
    cout << "Draugr with " << m_health << " health and " << m_frostResist << "% frost resist was born" << endl;
    cout << "Move constructor was called" << endl;
}

void Draugr::shoutPhrase(int shoutNumber) const {
    map<int, string> shouts {
        {0, "Qiilaan Us Dilon!"},
        {1, "Bolog Aaz, Mal Lir!"},
        {2, "Kren Sosaal!"},
        {3, "Dir Volaan!"},
        {4, "Aar Vin Ok!"},
        {5, "Unslaad Krosis!"},
        {6, "Faaz! Paak! Dinok!"},
        {7, "Aav Dilon!"},
        {8, "Sovngarde Saraan!"}
    };
    cout << "Draugr " << m_name << " (" << m_health << " health, " << m_frostResist << "% frost resist) shouts:\n"
        << shouts.at(shoutNumber) << endl;
}
