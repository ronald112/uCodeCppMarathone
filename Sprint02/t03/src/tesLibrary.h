#pragma once

#include <iostream>
#include <string>
#include <algorithm>
#include <fstream>
#include <sstream>
#include <regex>
#include <map>

using namespace std;

void printFile(const multimap<string, string>& library);
void readFile(ifstream& file, multimap<string, string>& library, const regex& pattern);
