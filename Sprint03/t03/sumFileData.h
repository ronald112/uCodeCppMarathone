#pragma once

#include <fstream>
#include <iterator>
#include <string>

template <class T>
T sumFileData(const std::string& fileName) {
    std::ifstream file(fileName);
    std::istream_iterator<T> i(file);
    std::istream_iterator<T> end_of_stream;
    T res = 0;

    while (i != end_of_stream) {
        res += *i;
        i.operator++();
    }
    return res;
}
