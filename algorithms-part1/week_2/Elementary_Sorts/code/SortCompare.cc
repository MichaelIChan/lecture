#include <iostream>
#include <ctime>
#include <string>
#include <vector>
#include <algorithm>

#include "InsertionSort.h"
#include "SelectionSort.h"

class SortCompare {
public:
    double timeRandomInput(std::string& alg, int N, int T)
    {
        double total = 0.0;
        std::vector<double> a = std::vector<double>(N);
        for (int t = 0; t < T; ++t) {
            for (int i = 0; i < N; ++i) {
                a[i] = i;
            }
            std::random_shuffle(a.begin(), a.end());    // random_shuffle() 打乱容器中的数据
            total += getTime(alg, a);
        }
        return total;
    }

private:
    double getTime(std::string& alg, std::vector<double>& a)
    {
        std::clock_t start = clock();
        if (alg == "Insertion") insertion_sort(a.begin(), a.end());
        if (alg == "Selection") selection_sort(a.begin(), a.end());
        std::clock_t end = clock();
        return (double)(end - start) / CLOCKS_PER_SEC;
    }
};

int main(int argc, char const *argv[])
{
    std::string alg1 = std::string(argv[1]);
    std::string alg2 = std::string(argv[2]);
    int N = std::stoi(std::string(argv[3]));
    int T = std::stoi(std::string(argv[4]));

    SortCompare sc;
    double t1 = sc.timeRandomInput(alg1, N, T);
    double t2 = sc.timeRandomInput(alg2, N, T);

    std::cout << "For " << N << " random doubles: " << std::endl;
    std::cout << alg1 << " needs " << t1 << " seconds" << std::endl;
    std::cout << alg2 << " needs " << t2 << " seconds" << std::endl;

    return 0;
}
