#include <iostream>
#include <cstdlib>
#include <vector>
#include <algorithm>

#include "MergeSort.h"

int main(void)
{   
    srand(time(NULL));

    {
        // test 1
        std::vector<int> array;
        const int SIZE = 20;
        for (int i = 0; i < SIZE; ++i) {
            array.push_back(i);
        }
        std::random_shuffle(array.begin(), array.end());

        show(array.begin(), array.end());

        merge_sortBU(array.begin(), array.end());

        show(array.begin(), array.end());

        std::cout << "is sorted ? " << isSorted(array.begin(), array.end()) << std::endl;
    }

    {
        // test 2
        std::vector<char> array;
        const int SIZE = 26;
        for (int i = 0; i < SIZE; ++i) {
            array.push_back(i + 65);  // push capital letter in
        }
        std::random_shuffle(array.begin(), array.end());

        show(array.begin(), array.end());

        merge_sortBU(array.begin(), array.end());

        show(array.begin(), array.end());

        std::cout << "is sorted ? " << isSorted(array.begin(), array.end()) << std::endl;
    }

    return 0;
}