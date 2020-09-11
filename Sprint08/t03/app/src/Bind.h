#pragma once

/* includes */
#include <functional>
#include <iostream>
#include <cmath>
#include <string>

namespace SpecializedFunctions {

namespace Math {

template <typename T>
auto pow2 = std::bind(std::pow<T, int>, std::placeholders::_1, 2);

template <typename T>
T add(const T arg1, const T arg2) {
    return arg1 + arg2;
}

auto iDontWontToCalculate = std::bind(add<int>, 2, 2);

}  // end namespace Math

namespace Output {

template <typename T>
void output3Arguments(const T& arg1, const T& arg2, const T& arg3) {
    std::cout << arg1 << " " << arg2 << " " << arg3 << std::endl;
}

template <typename T>
void outputPrintWords(const T& arg1, const T& arg2, const T& arg3, const T& arg4) {
    std::cout << arg1 << " " << arg2 << " " << arg3 << " " << arg4 << std::endl;
}

template <typename T>
auto outputWeird3Arguments = std::bind(output3Arguments<std::string>, std::placeholders::_2,
                            std::placeholders::_3, std::placeholders::_1);
auto outputFusRoDah = std::bind(output3Arguments<const char*>, "Fus", "Ro", "Dah");

auto outputLovelyWords = std::bind(outputPrintWords<std::string>, "I", "love", "you", "!");

}  // end namespace Output
}  // end namespace SpecializedFunctions
