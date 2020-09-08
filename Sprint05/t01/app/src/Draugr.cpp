#include "Draugr.h"
#include <map>
#include <iostream>

using namespace std;

Draugr::Draugr(double health, int frostResist) : m_health(health), m_frostResist(frostResist) {
    cout << "Draugr with " << health << " health and " << frostResist << "% frost resist was born!" << endl;
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
    cout << "Draugr (" << m_health << " health, " << m_frostResist << "% frost resist) shouts:\n"
        << shouts.at(shoutNumber) << endl;
}
