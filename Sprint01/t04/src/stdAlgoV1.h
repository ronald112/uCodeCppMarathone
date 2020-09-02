#pragma once

#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>

using namespace std;

struct NamesFeature {
    int size = 0;
    bool rich = false;
    bool big_lengths = true;
    int all_end_vel = 0;
    int mel_amount = 0;
    string path;
    void iterateFile();
    void check_line(const string& str);
    void print();
};
