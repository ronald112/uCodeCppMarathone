#include "vampireRabbits.h"

int main() {
    MyRabbits myrabbits;
    bool first = false;
    srand(time(0));

    while (myrabbits.sum < 1000 && myrabbits.m_rabbits.size() > 0) {
        if (first == true)
            cout << endl;
        first = true;
        myrabbits.changeAge();
        myrabbits.createVampires();
        myrabbits.createRabbits();
        myrabbits.deleteOld();
        myrabbits.print();
        myrabbits.sum = myrabbits.males + myrabbits.females + myrabbits.vampires + myrabbits.zombies;
        SLEEP(1);
    }
    return 0;
}
