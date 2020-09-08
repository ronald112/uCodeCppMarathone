#pragma once

class Draugr {
 public:
    Draugr(double health, int frostResist);
    Draugr(int frostResist) : Draugr(100, frostResist) {};
    Draugr() : Draugr(100, 50) {};
    void shoutPhrase(int shoutNumber) const;
 private:
    double m_health;
    const int m_frostResist;
};
