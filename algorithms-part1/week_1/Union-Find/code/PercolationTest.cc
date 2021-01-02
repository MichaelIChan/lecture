#include <iostream>
#include <string>

#include "PercolationStats.h"

int main(int argc, char const *argv[])
{
    PercolationStats stats = 
        PercolationStats(std::stoi(std::string(argv[1])), std::stoi(std::string(argv[2])));
    std::cout << "mean                    = " << stats.getMean() << std::endl;
    std::cout << "stddev                  = " << stats.getStddev() << std::endl;
    std::cout << "95% confidence interval = " << stats.getConfidenceLo() << ", "
                                              << stats.getConfidenceHi() << std::endl;
    return 0;
}
