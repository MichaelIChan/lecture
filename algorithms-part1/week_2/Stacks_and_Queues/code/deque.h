#include <iostream>

template <class T>
struct __list_node {
    typedef void* pointer;
    pointer prev;
    pointer next;
    T item;

    __list_node() { next = nullptr; prev = nullptr; }
};

template <class T>
class __list_iterator {
protected:
    typedef __list_node<T> list_node;
public:
    typedef T          value_type;
    typedef list_node* link_type;
public:
    __list_iterator(link_type first) { current = first; }

    bool hasNext() { return current != nullptr; }

    void remove()
    {
        std::cout << "You can't remove by a iterator" << std::endl;
        return;
    }

    value_type next()
    {
        if (!hasNext()) {
            std::cout << "have no next." << std::endl;
            exit(0);
        } else {
            value_type item = current->item;
            current = link_type(current->next);
            return item;
        }
    }
private:
    link_type current;
};

template <class T>
class deque {
protected:
    typedef __list_node<T> list_node;
public:
    typedef T                           value_type;
    typedef list_node*                  link_type;
    typedef __list_iterator<value_type> Iterator;
public:
    deque()
    {
        size = 0;
        first = new list_node();
        last = new list_node();
    }
    ~deque()
    {
        delete first;
        delete last;
    }

    // is the deque empty?
    bool isEmpty() { return size == 0; }

    // return the number of items on the deque
    int getSize() { return size; }

    // add the item to the front
    void addFirst(value_type item)
    {
        link_type tmp = first;
        first = new list_node();
        first->item = item;
        first->next = tmp;
        first->prev = nullptr;
        if (isEmpty()) {
            last = first;
        } else {
            tmp->prev = first;
        }
        size++;
    }

    // add the item to the back
    void addLast(value_type item)
    {
        link_type tmp = last;
        last = new list_node();
        last->item = item;
        last->next = nullptr;
        last->prev = tmp;
        if (isEmpty()) {
            first = last;
        } else {
            tmp->next = last;
        }
        size++;
    }

    // remove and return the item from the front
    value_type removeFirst()
    {
        value_type item = first->item;
        size--;
        if (isEmpty()) {
            first = nullptr;
            last = nullptr;
        } else {
            first = link_type(first->next);
            first->prev = nullptr;
        }
        return item;
    }

    // remove and return the item from the back
    value_type removeLast()
    {
        value_type item = last->item;
        size--;
        if (isEmpty()) {
            first = nullptr;
            last = nullptr;
        } else {
            last = link_type(last->prev);
            last->next = nullptr;
        }
        return item;
    }

    // return an iterator over items in order from front to back
    Iterator iterator() { return Iterator(first); }
private:
private:
    link_type first;
    link_type last;
    int size;
};