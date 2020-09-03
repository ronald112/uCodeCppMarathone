#pragma once

#include <iterator>
#include <iostream>
#include <algorithm>

template <typename Container>
void outputContainer(const Container& container) {
    std::ostream_iterator<typename Container::value_type> output(std::cout, "\n");
    std::copy(container.begin(), container.end(), output);
}
