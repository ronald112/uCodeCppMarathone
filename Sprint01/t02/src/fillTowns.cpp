#include "visitAll.h"

static void checkLine(string str1, string str, size_t i) {
    if (str[i] != '\0') {
        throw string("Argument " + str1 + " is not valid");
    }
}

static int getStamina(string str1, string& str,
                    const string d, size_t pos = 0) {
    string input = str.substr(0, pos);
    int stamina = 0;

    if (input.size() == 0 || input.front() == ' ') {
        throw string("Argument " + str1 + " is not valid");
    }
    str.erase(0, pos + d.length());
    stamina = stoi(input, &pos);
    checkLine(str1, input, pos);
    return stamina;
}

Town fillTown(string str1, string str, const string d) {
    Town town;
    string input;
    size_t pos = 0;

    if ((pos = str.find(d)) != string::npos) {
        town.name = str.substr(0, pos);
        str.erase(0, pos + d.length());
    }
    if ((pos = str.find(d)) != string::npos)
        town.stamina = getStamina(str1, str, d, pos);
    input = str;
    if (input.size() == 0 || input.front() == ' ')
        throw string("Argument " + str1 + " is not valid");
    town.distance = stoi(input, &pos);
    checkLine(str1, input, pos);
    return town;
}

