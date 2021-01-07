#ifndef __SELECTION_SORT_H
#define __SELECTION_SORT_H

#include <iostream>

#include "implements_sort.h"

template <class RandomAccessIterator>
void selection_sort(RandomAccessIterator first, RandomAccessIterator last)
{
    if (first == last) return;
    for (RandomAccessIterator i = first; i != last; ++i) {
        RandomAccessIterator min = i;
        for (RandomAccessIterator j = i + 1; j != last; ++j) {
            if(__less(*j, *min)) min = j;
        }
        __exch(*i, *min);
    }
}

template <class RandomAccessIterator, class Compare>
void selection_sort(RandomAccessIterator first, RandomAccessIterator last, Compare comp)
{
    if (first == last) return;
    for (RandomAccessIterator i = first; i != last; ++i) {
        RandomAccessIterator min = i;
        for (RandomAccessIterator j = i + 1; j != last; ++j) {
            if(__less(*j, *min, comp)) min = j;
        }
        __exch(*i, *min);
    }
}

#endif /* __SELECTION_SORT_H */