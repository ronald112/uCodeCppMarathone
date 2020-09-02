#pragma once

#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <forward_list>

using namespace std;

struct NamesFeature {
    string path;
    void iterateFile();
    void changeList();
    void save();
    forward_list<string> names;
};
