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
void __merge(RandomAccessIterator first, RandomAccessIterator mid, RandomAccessIterator last)
{
    if (first == last - 1) return;
    typedef typename std::iterator_traits<RandomAccessIterator>::value_type T;
    std::vector<T> aux = std::vector<T>(last - first);

    RandomAccessIterator auxMid = aux.begin();
    int i = 0;
    for (RandomAccessIterator iter = first; iter != mid; ++iter) {
        aux[i++] = *iter;
        auxMid++;
    }
    for (RandomAccessIterator iter = mid; iter != last; ++iter) {
        aux[i++] = *iter;
    }

    RandomAccessIterator first1 = aux.begin(), last1 = auxMid;
    RandomAccessIterator first2 = auxMid, last2 = aux.end();
    for (RandomAccessIterator iter = first; iter != last; ++iter) {
        if (std::distance(last1, first1) >= 0)      *iter = *first2++;
        else if (std::distance(last2, first2) >= 0) *iter = *first1++;
        else if (__less(*first2, *first1))          *iter = *first2++;
        else                                        *iter = *first1++;
    }
}

template <class RandomAccessIterator, class Compare>
void __merge(RandomAccessIterator first, RandomAccessIterator mid, RandomAccessIterator last, Compare comp)
{
    if (first == last - 1) return;
    typedef typename std::iterator_traits<RandomAccessIterator>::value_type T;
    std::vector<T> aux = std::vector<T>(last - first);

    RandomAccessIterator auxMid = aux.begin();
    int i = 0;
    for (RandomAccessIterator iter = first; iter != mid; ++iter) {
        aux[i++] = *iter;
        auxMid++;
    }
    for (RandomAccessIterator iter = mid; iter != last; ++iter) {
        aux[i++] = *iter;
    }

    RandomAccessIterator first1 = aux.begin(), last1 = auxMid;
    RandomAccessIterator first2 = auxMid, last2 = aux.end();
    for (RandomAccessIterator iter = first; iter != last; ++iter) {
        if (std::distance(last1, first1) >= 0)      *iter = *first2++;
        else if (std::distance(last2, first2) >= 0) *iter = *first1++;
        else if (__less(*first2, *first1, comp))    *iter = *first2++;
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
    __merge(first, mid + 1, last);
}

template <class RandomAccessIterator, class Compare>
void __sort(RandomAccessIterator first, RandomAccessIterator last, Compare comp)
{
    if (std::distance(first, last) == 1) return;
    RandomAccessIterator mid = first + (last - 1 - first) / 2;
    __sort(first, mid + 1, comp);
    __sort(mid + 1, last, comp);
    __merge(first, mid + 1, last, comp);
}

/* 
 * merge_sort() interface
**/
template <class RandomAccessIterator>
void merge_sort(RandomAccessIterator first, RandomAccessIterator last)
{
    __sort(first, last);
}

template <class RandomAccessIterator, class Compare>
void merge_sort(RandomAccessIterator first, RandomAccessIterator last, Compare comp)
{
    __sort(first, last, comp);
}

/* 
 * merge_sortBU() interface
**/
template <class RandomAccessIterator>
void merge_sortBU(RandomAccessIterator first, RandomAccessIterator last)
{
    for (int sz = 1; sz < std::distance(first, last); sz = sz + sz) {
        std::cout << "sz = " << sz << std::endl;
        for (RandomAccessIterator left = first; std::distance(left, last - sz) > 0; left += sz + sz) {
            RandomAccessIterator right = std::distance(left + sz + sz, last) > 0 ? left + sz + sz : last;
            __merge(left, left + sz, right);
        }
    }
}

template <class RandomAccessIterator, class Compare>
void merge_sortBU(RandomAccessIterator first, RandomAccessIterator last, Compare comp)
{
    for (int sz = 1; sz < std::distance(first, last); sz = sz + sz) {
        std::cout << "sz = " << sz << std::endl;
        for (RandomAccessIterator left = first; std::distance(left, last - sz) > 0; left += sz + sz) {
            RandomAccessIterator right = std::distance(left + sz + sz, last) > 0 ? left + sz + sz : last;
            __merge(left, left + sz, right, comp);
        }
    }
}

#endif /* __MERGE_SORT_H */
