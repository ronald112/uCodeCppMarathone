#include "visitAll.h"

bool compareTowns(const Town& lhs, const Town& rhs) {
    int num1 = (lhs.stamina - lhs.distance);
    int num2 = (rhs.stamina - rhs.distance);

    if (num1 > 0 && num2 > 0) {
        return num1 < num2;
    }
    return num1 > num2;
}

deque<Town> createDeque(int argc, char* argv[]) {
    deque<Town> towns;
    int m_sum = 0;

    for (int i = 1; i < argc; i++) {
        Town town = fillTown(string(argv[i]), string(argv[i]), ",");
        ssize_t index = 0;

        if (town.name.size() == 0) {
            throw string("Argument " + string(argv[i]) + " is not valid");
        }
        m_sum += town.stamina - town.distance;
        towns.push_back(town);
    }
    if (m_sum < 0) {
        throw string("Mission: Impossible");
    }
    sort(towns.begin(), towns.end(), compareTowns);
    return towns;
}

int main(int argc, char* argv[]) {
    if (argc == 1) {
        cerr << "usage: ./visitAll [[name,stamina,distance] ...]" << endl;
        return 1;
    }
    else if (argc == 2) {
        cerr << "Mission: Impossible" << endl;
        return 1;
    }
    else {
        try {
            int index = 1;
            deque<Town> towns = createDeque(argc, argv);

            for (const auto& i : towns) {
                if (index == towns.size())
                    index = 0;
                cout << to_string(index++) + ". " + i.name << endl;
            }
        }
        catch(string exception) {
            cerr << exception << endl;
        }
    }
    return 0;
}
