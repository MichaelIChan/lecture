#include <iostream>
#include <cstdlib>

template <class T>
class __randomized_queue_iterator {
public:
    typedef T value_type;
public:
    explicit __randomized_queue_iterator() { }
    __randomized_queue_iterator(value_type array[], int sz)
    {
        this->size = sz;
        current = 0;
        items = new value_type[size];
        for (int i = 0; i < size; i++) {
            items[i] = array[i];
        }
        shuffle();
    }

    bool hasNext()
    {
        return current < size;
    }

    void remove()
    {
        std::cout << "You can't remove by items iterator" << std::endl;
        return;
    }

    value_type next()
    {
        if (!hasNext()) {
            std::cout << "have no next." << std::endl;
            exit(0);
        }
        return items[current++];
    }
private:
    /**
     * Rearranges the elements of the specified array in uniformly random order.
     */
    void shuffle()
    {
        srand(time(NULL));
        for (int i = 0; i < size; i++) {
            int r = i + (rand() % (size - i));  // get random number between i and size
            double temp = items[i];
            items[i] = items[r];
            items[r] = temp;
        }
    }
private:
    value_type* items;
    int current;
    int size;
};

template <class T>
class RandomizedQueue {
public:
    typedef T                              value_type;
    typedef __randomized_queue_iterator<T> Iterator;

public:
    // construct an empty randomized queue
    RandomizedQueue()
    {
        size = 0;
        array = (value_type*) new value_type[1];
        storage = 1;
    }
    ~RandomizedQueue()
    {
        delete[] array;
    }

    // is the randomized queue empty?
    bool isEmpty() { return size == 0; }

    // return the number of items on the randomized queue
    int getSize() { return size; }

    // add the item
    void enqueue(value_type item)
    {
        if (size == storage) resize(2 * size);
        array[size] = item;
        size++;
        std::cout << "push " << item << " in" << std::endl;
    }

    // remove and return items random item
    value_type dequeue()
    {
        srand(time(NULL));
        int i = rand() % size;
        value_type temp = array[i];
        if (i != --size) {
            for (int k = i; k < size; ++k) {
                array[k] = array[k + 1];
            }
        }
        if (size > 0 && size == storage / 4) resize(storage / 2);
        return temp;
    }

    // return items random item (but do not remove it)
    value_type sample()
    {
        srand(time(NULL));
        int x = rand() % size + 1;
        return array[x];
    }

    void resize(int capacity)
    {
        value_type* tmp = (value_type*) new value_type[capacity];
        for (int i = 0; i < size; i++) {
            tmp[i] = array[i];
        }
        storage = capacity;
        delete[] array;
        array = tmp;
    }

    // return an independent iterator over items in random order
    Iterator iterator()
    {
        return Iterator(array, size);
    }

private:
    value_type* array;
    int         size;       // the number of elements
    int         storage;    // the number of storage size
};
