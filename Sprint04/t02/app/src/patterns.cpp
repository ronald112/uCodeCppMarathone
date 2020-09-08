#include "misc.h"

Patterns::Patterns() {
    cmd["shout"] = Dragonborn::Actions::Shout;
    cmd["magic"] = Dragonborn::Actions::Magic;
    cmd["weapon"] = Dragonborn::Actions::Weapon;
}

void readCmd(std::string str, struct Patterns& patterns, Dragonborn& dr) {
    dr.executeAction(patterns.cmd.at(str));
}
