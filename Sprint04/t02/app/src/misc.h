#pragma once

#include "dragonborn.h"
#include <map>
#include <functional>
#include <string>

using namespace std;

struct Patterns {
    Patterns();
    map<string, Dragonborn::Actions> cmd;
    map<Dragonborn::Actions, string> action;
};

void readCmd(std::string str, struct Patterns& patterns, Dragonborn& dr);
