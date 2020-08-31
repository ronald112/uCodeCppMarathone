#include "inv.h"

static int getItemByString(const string& item) {
    if (item == "a")
        return Item_type::ARMOR;
    else if (item == "w")
        return Item_type::WEAPON;
    else if (item == "f")
        return Item_type::FOOD;
    else if (item == "p")
        return Item_type::POTION;
    else
        return Item_type::NO_ITEM;
}

void Inv::insertOrRemove(const int& cmd_type) {
    string arg;

    cin >> arg;
    if (cin.peek() != '\n') {
        cerr << "Invalid command." << endl;
        getline(cin, arg);
    }
    else if (arg != "a" && arg != "w" && arg != "f" && arg != "p") {
        cerr << "Invalid item." << endl;
    }
    else if (cmd_type == Cmd_type::INSERT) {
        insertItem(getItemByString(arg));
    }
    else if (cmd_type == Cmd_type::REMOVE) {
        removeItem(getItemByString(arg));
    }
}

void Inv::checkCmd(const int& cmd_type) {
    if (cmd_type == Cmd_type::INSERT || cmd_type == Cmd_type::REMOVE) {
        insertOrRemove(cmd_type);
    }
    else if (cmd_type == Cmd_type::SHOW) {
        showInventory();
    }
    else if (cmd_type == Cmd_type::HELP) {
        help();
    }
    else if (cmd_type == Cmd_type::ERROR) {
        cerr << "Invalid command." << endl;
    }
}

int Inv::parseCmd() {
    string cmd;
    cin >> cmd;
    if (cmd.size() == 0)
        return -1;
    if (cmd == "insert") {
        return Cmd_type::INSERT;
    }
    else if (cmd == "remove") {
        return Cmd_type::REMOVE;
    }
    else if (cmd == "show") {
        return Cmd_type::SHOW;
    }
    else if (cmd == "help") {
        return Cmd_type::HELP;
    }
    else if (cmd == "exit") {
        return Cmd_type::EXIT;
    }
    else {
        return Cmd_type::ERROR;
    }
}
