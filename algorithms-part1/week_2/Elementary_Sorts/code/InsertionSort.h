#ifndef __INSERTION_SORT_H
#define __INSERTION_SORT_H

#include <iostream>

#include "implements_sort.h"

template <class RandomAccessIterator>
void insertion_sort(RandomAccessIterator first, RandomAccessIterator last)
{
    if (first == last) return;
    for (RandomAccessIterator i = first; i != last; ++i) {
        for (RandomAccessIterator j = i; j != first && __less(*j, *(j - 1)); --j) {
            __exch(*j, *(j - 1));
        }
    }
}

template <class RandomAccessIterator, class Compare>
void insertion_sort(RandomAccessIterator first, RandomAccessIterator last, Compare comp)
{
    if (first == last) return;
    for (RandomAccessIterator i = first; i != last; ++i) {
        for (RandomAccessIterator j = i; j != first && __less(*j, *(j - 1), comp); --j) {
            __exch(*j, *(j - 1));
        }
    }
}

#endif /* __INSERTION_SORT_H */