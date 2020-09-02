#pragma once

#include <iostream>
#include <string>
#include <algorithm>
#include <deque>

using namespace std;

struct Town {
    string name;
    int stamina;
    int distance;
    Town(string n_name = "0", int n_st = 0, int n_dist = 0) {
        name = n_name;
        n_st = stamina;
        n_dist = distance;
    }
};

Town fillTown(string str1, string str, const string d);
