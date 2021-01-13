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

template <class RandomAccessIterator>
void __sort(RandomAccessIterator first, RandomAccessIterator last)
{
    if (last <= first) return;
    RandomAccessIterator j = __partition(first, last);
    __sort(first, j);
    __sort(j + 1, last);
}

template <class RandomAccessIterator>
void quick_sort(RandomAccessIterator first, RandomAccessIterator last)
{
    std::random_shuffle(first, last);
    __sort(first, last);
}

#endif /* __QUICK_SORT_H */