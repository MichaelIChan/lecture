#include <iostream>
#include <string>

#include "deque.h"

using std::string;

int main(int argc, char const *argv[])
{
    string str;
    deque<string> deque;
    while (std::cin >> str) {
        if (str == "-") {
            std::cout << deque.removeLast();
        } else {
            deque.addLast(str);
        }
    }
    std::cout << "\nuse iterator:" << std::endl;
    for (auto ite = deque.iterator(); ite.hasNext();) {
        std::cout << ite.next() << std::endl;
    }
    return 0;
}
