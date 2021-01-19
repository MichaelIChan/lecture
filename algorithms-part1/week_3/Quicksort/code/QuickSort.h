#ifndef __QUICK_SORT_H
#define __QUICK_SORT_H

#include "implements_sort.h"

#include <iterator>
#include <algorithm>

// 分割函数, 其返回值是分割后的右段第一个位置
template <class RandomAccessIterator>
RandomAccessIterator __partition(RandomAccessIterator first, RandomAccessIterator last)
{
    RandomAccessIterator i = first, j = last;   // 左右扫描指针
    typedef typename std::iterator_traits<RandomAccessIterator>::value_type T;
    T pivot = *first;                           // 切分元素
    while (true) {          // 扫描左右, 检查扫描结果是否结束并交换元素
        while (__less(*(++i), pivot)) if (i == last) break;
        while (__less(pivot, *(--j))) if (j == first) break;
        if (i >= j) break;
        __exch(*i, *j);
    }
    __exch(*first, *j);     // 将 pivot = a[j] 放入正确位置
    return j;
}

template <class RandomAccessIterator, class Compare>
RandomAccessIterator __partition(RandomAccessIterator first, RandomAccessIterator last, Compare comp)
{
    RandomAccessIterator i = first, j = last;   // 左右扫描指针
    typedef typename std::iterator_traits<RandomAccessIterator>::value_type T;
    T pivot = *first;                           // 切分元素
    while (true) {          // 扫描左右, 检查扫描结果是否结束并交换元素
        while (__less(*(++i), pivot, comp)) if (i == last) break;
        while (__less(pivot, *(--j), comp)) if (j == first) break;
        if (i >= j) break;
        __exch(*i, *j);
    }
    __exch(*first, *j);     // 将 pivot = a[j] 放入正确位置
    return j;
}

template <class RandomAccessIterator>
void __sort(RandomAccessIterator first, RandomAccessIterator last)
{
    if (last <= first) return;
    RandomAccessIterator j = __partition(first, last);
    __sort(first, j);
    __sort(j + 1, last);
}

template <class RandomAccessIterator, class Compare>
void __sort(RandomAccessIterator first, RandomAccessIterator last, Compare comp)
{
    if (last <= first) return;
    RandomAccessIterator j = __partition(first, last, comp);
    __sort(first, j, comp);
    __sort(j + 1, last, comp);
}

template <class RandomAccessIterator>
void quick_sort(RandomAccessIterator first, RandomAccessIterator last)
{
    std::random_shuffle(first, last);
    __sort(first, last);
}

template <class RandomAccessIterator, class Compare>
void quick_sort(RandomAccessIterator first, RandomAccessIterator last, Compare comp)
{
    std::random_shuffle(first, last);
    __sort(first, last, comp);
}

// 三向比较
template <class T>
inline int __compare3way(T x, T y)
{
    if      (x > y) return 1;
    else if (x < y) return -1;
    else            return 0;
}

template <class T, class Compare>
inline int __compare3way(T x, T y, Compare comp)
{
    return comp(x, y);
}

// 三向切分的快速排序
template <class RandomAccessIterator>
void __quick3way_sort(RandomAccessIterator first, RandomAccessIterator last)
{
    if (last <= first) return;
    RandomAccessIterator lt = first, i = first + 1, gt = last;
    typedef typename std::iterator_traits<RandomAccessIterator>::value_type T;
    T pivot = *first;
    while (i <= gt) {
        int cmp = __compare3way(*i, pivot);
        if      (cmp < 0) __exch(*lt++, *i++);
        else if (cmp > 0) __exch(*i, *gt--);
        else              i++;
    } // 至此, array[first .. lt - 1] < pivot = array[lt .. gt] < array[gt + 1 .. last]
    __quick3way_sort(first, lt - 1);
    __quick3way_sort(gt + 1, last);
}

template <class RandomAccessIterator, class Compare>
void __quick3way_sort(RandomAccessIterator first, RandomAccessIterator last, Compare comp)
{
    if (last <= first) return;
    RandomAccessIterator lt = first, i = first + 1, gt = last;
    typedef typename std::iterator_traits<RandomAccessIterator>::value_type T;
    T pivot = *first;
    while (i <= gt) {
        int cmp = __compare3way(*i, pivot, comp);
        if      (cmp < 0) __exch(*lt++, *i++);
        else if (cmp > 0) __exch(*i, *gt--);
        else              i++;
    }
    __quick3way_sort(first, lt - 1, comp);
    __quick3way_sort(gt + 1, last, comp);
}

template <class RandomAccessIterator>
void quick3way_sort(RandomAccessIterator first, RandomAccessIterator last)
{
    std::random_shuffle(first, last);
    __quick3way_sort(first, last - 1);
}

template <class RandomAccessIterator, class Compare>
void quick3way_sort(RandomAccessIterator first, RandomAccessIterator last, Compare comp)
{
    std::random_shuffle(first, last);
    __quick3way_sort(first, last - 1, comp);
}

#endif /* __QUICK_SORT_H */