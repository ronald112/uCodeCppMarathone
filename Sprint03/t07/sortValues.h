#pragma once

template <class RandomAccessIterator>
RandomAccessIterator sortValues(RandomAccessIterator begin, RandomAccessIterator end) {
    for (RandomAccessIterator i = begin; i != end; i++) {
        for (RandomAccessIterator j = begin; j < i; j++) {
            if (*i < *j) {
                auto it = *i;

                *i = *j;
                *j = it;
            }
        }
    }
    return begin;
}
