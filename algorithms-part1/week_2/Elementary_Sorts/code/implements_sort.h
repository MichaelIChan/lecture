#ifndef __IMPLEMENTS_SORT_H
#define __IMPLEMENTS_SORT_H

#include <iostream>

template <class RandomAccessIterator, class BidirectionalIterator, class Distance>
inline BidirectionalIterator __copy_backward(RandomAccessIterator first, 
                                             RandomAccessIterator last, 
                                             BidirectionalIterator result,
                                             Distance*)
{
    for (Distance __n = last - first; __n > 0; --__n) {
        *--result = *--last;
    }
    return result;
}

template <class T>
bool __less(T x, T y)
{
    return x < y;
}

template <class T, class Compare>
bool __less(T x, T y, Compare comp)
{
    return comp(x, y) < 0;
}

template <class T>
inline void __exch(T& x, T& y)
{
    T tmp = x;
    x = y;
    y = tmp;
}

template <class RandomAccessIterator>
void show(RandomAccessIterator first, RandomAccessIterator last)
{
    for (RandomAccessIterator i = first; i != last; ++i) {
        std::cout << *i << " ";
    }
    std::cout << std::endl;
}

template <class RandomAccessIterator>
bool isSorted(RandomAccessIterator first, RandomAccessIterator last)
{
    for (RandomAccessIterator i = first + 1; i != last; ++i) {
        if (__less(*i, *(i - 1))) return false;
    }
    return true;
}

template <class RandomAccessIterator, class Compare>
bool isSorted(RandomAccessIterator first, RandomAccessIterator last, Compare comp)
{
    for (RandomAccessIterator i = first + 1; i != last; ++i) {
        if (__less(*i, *(i - 1), comp)) return false;
    }
    return true;
}

#endif /* _IMPLEMENTS_SORT__ */