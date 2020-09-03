#pragma once

#include <iostream>

template <class BidirectionalIterator>
bool isPalindrome(BidirectionalIterator begin, BidirectionalIterator end) {
    end--;
    while (begin != end) {
        if (*begin++ != *end--) {
            return false;
        }
    }
    return true;
}
