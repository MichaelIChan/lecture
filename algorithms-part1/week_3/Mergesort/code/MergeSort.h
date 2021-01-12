#ifndef __MERGE_SORT_H
#define __MERGE_SORT_H

#include "implements_sort.h"

#include <iterator>
#include <vector>

/* 
 * merge_sort() assistent function,
 * merge [first, mid] and [mid + 1, last]
**/
template <class RandomAccessIterator>
void __merge(RandomAccessIterator first, RandomAccessIterator last)
{
    if (first == last - 1) return;
    typedef typename std::iterator_traits<RandomAccessIterator>::value_type T;
    std::vector<T> aux;
    for (RandomAccessIterator iter = first; iter != last; ++iter) {
        aux.push_back(*iter);
    }

    RandomAccessIterator mid = aux.begin() + (aux.end() - 1  - aux.begin()) / 2;
    RandomAccessIterator first1 = aux.begin(), last1 = mid + 1;
    RandomAccessIterator first2 = mid + 1, last2 = aux.end();
    for (RandomAccessIterator iter = first; iter != last; ++iter) {
        if (std::distance(last1, first1) >= 0)      *iter = *first2++;
        else if (std::distance(last2, first2) >= 0) *iter = *first1++;
        else if (__less(*first2, *first1))          *iter = *first2++;
        else                                        *iter = *first1++;
    }
}

/* 
 * merge_sort() assistent function
**/
template <class RandomAccessIterator>
void __sort(RandomAccessIterator first, RandomAccessIterator last)
{
    if (std::distance(first, last) == 1) return;
    RandomAccessIterator mid = first + (last - 1 - first) / 2;
    __sort(first, mid + 1);
    __sort(mid + 1, last);
    __merge(first, last);
}

/* 
 * merge_sort() interface
**/
template <class RandomAccessIterator>
void merge_sort(RandomAccessIterator first, RandomAccessIterator last)
{
    __sort(first, last);
}

#endif /* __MERGE_SORT_H */