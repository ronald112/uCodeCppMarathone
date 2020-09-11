#pragma once

/* includes */
#include <iostream>

namespace UniversalReferenceDeterminant {

template <typename T>
void determineReference(T&& obj) {
    switch (*typeid(obj).name()) {
    case 'i': std::cout << "int"; break;
    case 'f': std::cout << "float"; break;
    case 'd': std::cout << "double"; break;
    case 'l': std::cout << "long"; break;
    case 'j': std::cout << "unsigned long"; break;
    case 'c': std::cout << "char"; break;
    }
    std::cout << " is ";
    if (std::is_lvalue_reference<T>::value)
        std::cout << "l-value reference" << std::endl;
    else
        std::cout << "r-value reference" << std::endl;
};

} // end namespace UniversalReferenceDeterminant
