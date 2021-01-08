#ifndef __INSERTION_SORT_H
#define __INSERTION_SORT_H

#include <iostream>
#include <iterator>

#include "implements_sort.h"

// insertion_sort() 辅助函数 __unguarded_linear_insert()
template <class RandomAccessIterator, class T>
void __unguarded_linear_insert(RandomAccessIterator last, T value)
{
    RandomAccessIterator next = last;
    --next;
    // insertion sort 的内循环
    // 注意, 一旦不再出现逆转对 (inversion), 循环就可以结束了
    while (__less(value, *next)) {     // 逆转对 (inversion) 存在
        *last = *next;          // 调整
        last = next;            // 调整迭代器
        --next;                 // 左移一个位置
    }
    *last = value;              // value 的正确落脚处
}

template <class RandomAccessIterator, class T, class Compare>
void __unguarded_linear_insert(RandomAccessIterator last, T value, Compare comp)
{
    RandomAccessIterator next = last;
    --next;
    while (__less(value, *next, comp)) {
        *last = *next;
        last = next;
        --next;
    }
    *last = value;
}

// insertion_sort() 辅助函数 __linear_insert()
template <class RandomAccessIterator>
inline void __linear_insert(RandomAccessIterator first, RandomAccessIterator last)
{
    typedef typename std::iterator_traits<RandomAccessIterator>::value_type T;
    T value = *last;
    if (__less(value, *first)) {                    // 尾元素比头元素小
        __copy_backward(first, last, last + 1);     // 将整个区间向右递移一个位置
        *first = value;                             // 令头元素等于原先的尾元素值
    } else {
        __unguarded_linear_insert(last, value);
    }
}

template <class RandomAccessIterator, class Compare>
inline void __linear_insert(RandomAccessIterator first, RandomAccessIterator last, Compare comp)
{
    typedef typename std::iterator_traits<RandomAccessIterator>::value_type T;
    T value = *last;
    if (__less(value, *first)) {
        __copy_backward(first, last, last + 1);
        *first = value;
    } else {
        __unguarded_linear_insert(last, value, comp);
    }
}

template <class RandomAccessIterator>
void insertion_sort(RandomAccessIterator first, RandomAccessIterator last)
{
    if (first == last) return;
    for (RandomAccessIterator i = first + 1; i != last; ++i) {  // 外循环
        __linear_insert(first, i);
        // 以上, [first, i) 形成一个子区间
    }
}

template <class RandomAccessIterator, class Compare>
void insertion_sort(RandomAccessIterator first, RandomAccessIterator last, Compare comp)
{
    if (first == last) return;
    for (RandomAccessIterator i = first + 1; i != last; ++i) {
        __linear_insert(first, i, comp);
    }
}

#endif /* __INSERTION_SORT_H */