#pragma once

#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <set>

using namespace std;

struct UniqueWors {
    void iterateFile();
    void save();
    string path;
    multiset<string> words;
};
