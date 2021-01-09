#ifndef __SHELL_SORT_H
#define __SHELL_SORT_H

#include "implements_sort.h"

template <class RandomAccessIterator>
void shell_sort(RandomAccessIterator first, RandomAccessIterator last)
{
    if (first == last) return;
    long N = last - first;
    long h = 1;
    while (h < N / 3) h = 3 * h + 1; // 1, 4, 13, 40, 121, 364, 1093
    while (h >= 1) {
        for (RandomAccessIterator i = first + h; i != last; ++i) {
            for (RandomAccessIterator j = i; j != first + h - 1 && __less(*j, *(j - h)); j = j - h) {
                __exch(*j, *(j - h));
            }
        }
        h = h / 3;
    }
}

template <class RandomAccessIterator, class Compare>
void shell_sort(RandomAccessIterator first, RandomAccessIterator last, Compare comp)
{
    if (first == last) return;
    long N = last - first;
    long h = 1;
    while (h < N / 3) h = 3 * h + 1;
    while (h >= 1) {
        for (RandomAccessIterator i = first + h; i != last; ++i) {
            for (RandomAccessIterator j = i; j != first + h - 1 && __less(*j, *(j - h), comp); j = j - h) {
                __exch(*j, *(j - h));
            }
        }
        h = h / 3;
    }
}

#endif /* __SHELL_SORT_H */