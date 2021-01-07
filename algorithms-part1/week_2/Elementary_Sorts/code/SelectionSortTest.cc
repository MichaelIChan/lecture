#include <iostream>
#include <cstdlib>
#include <vector>

#include "SelectionSort.h"

int main(void)
{   
    srand(time(NULL));

    {
        // test 1
        std::vector<int> array;
        const int SIZE = 20;
        for (int i = 0; i < SIZE; ++i) {
            array.push_back(rand() % SIZE);
        }

        show(array.begin(), array.end());

        selection_sort(array.begin(), array.end());

        show(array.begin(), array.end());

        std::cout << "is sorted ? " << isSorted(array.begin(), array.end()) << std::endl;
    }

    {
    // test 1
        std::vector<char> array;
        const int SIZE = 26;
        for (int i = 0; i < SIZE; ++i) {
            array.push_back((rand() % SIZE) + 65);  // push capital letter in
        }

        show(array.begin(), array.end());

        selection_sort(array.begin(), array.end());

        show(array.begin(), array.end());

        std::cout << "is sorted ? " << isSorted(array.begin(), array.end()) << std::endl;
    }

    return 0;
}