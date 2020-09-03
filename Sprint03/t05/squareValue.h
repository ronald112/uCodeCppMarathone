#pragma once

#include <algorithm>
#include <vector>

template <class Container>
void squareValue(Container& container) {
    for (class Container::iterator i = container.begin();
        i != container.end(); i++) {
        *i *= *i;
    }
}