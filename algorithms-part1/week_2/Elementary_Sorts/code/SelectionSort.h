#include <iostream>

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