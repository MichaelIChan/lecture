#include <iostream>
#include <string>

#include "RandomizedQueue.h"

using std::string;

int main(int argc, char const *argv[])
{
    RandomizedQueue<int> rq;
    rq.enqueue(1);
    rq.enqueue(2);
    rq.enqueue(3);
    rq.enqueue(4);
    rq.enqueue(5);
    rq.enqueue(6);
    rq.enqueue(7);
    rq.enqueue(8);
    rq.enqueue(9);
    rq.enqueue(10);
    rq.enqueue(11);
    rq.enqueue(12);
    rq.enqueue(13);
    rq.enqueue(14);
    std::cout << "dequeue: " << rq.dequeue() << std::endl;

    std::cout << "\nuse iterator:" << std::endl;
    for (auto ite = rq.iterator(); ite.hasNext();) {
        std::cout << ite.next() << " ";
    }
    std::cout << std::endl;
    return 0;
}
