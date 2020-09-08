#pragma once

#include <string>

class Draugr {
 public:
    Draugr(double health, int frostResist);
    Draugr(int frostResist) : Draugr(100, frostResist) {};
    Draugr() : Draugr(100, 50) {};
    void shoutPhrase(int shoutNumber) const;
    Draugr(Draugr& other);
    Draugr(Draugr&& other);
    void setName(const std::string&& name);
 private:
    double m_health;
    const int m_frostResist;
 private:
    std::string m_name;
};
