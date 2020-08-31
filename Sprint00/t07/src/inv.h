#pragma once

#include <iostream>
#include <string>
#include <array>

using namespace std;

enum Item_type {
    WEAPON,
    FOOD,
    ARMOR,
    POTION,
    NO_ITEM
};

enum Cmd_type {
    INSERT,
    REMOVE,
    SHOW,
    HELP,
    EXIT,
    ERROR
};

struct Inv {
    Inv();
    void insertItem(const int& i_type);
    void removeItem(const int& i_type);
    void insertOrRemove(const int& cmd_type);
    void showInventory();
    void help();
    int parseCmd();
    void checkCmd(const int& cmd_type);
    void printPrompt();
    array<int, 12> my_inv;
    unsigned index = 0;
};
