#include "uniqueWords.h"

void UniqueWors::save() {
    string new_name;
    size_t pos;

    if ((pos = path.find(".")) != string::npos) {
        for (int i = 0; i < pos; i++)
            new_name += path[i];
        new_name += "_mod";
        new_name += &path[pos];
    }
    else
        new_name = path + "_mod";
    ofstream file(new_name);
    for (const auto& i : words) {
        file << i << '\n';
    }
}
