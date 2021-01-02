#include <iostream>
#include <vector>
#include <cstdlib>
#include <cmath>

#include "Percolation.h"

class PercolationStats {
public:
    PercolationStats(int n, int trials) {
        /* initialize random seed: */
        srand(time(NULL));

        if (n <= 0 || trials <= 0) {
            std::cout << "Invalid input : n or trials must > 0 !";
        }
        est = std::vector<double>(trials);
        for (int k = 0; k < trials; ++k) {
            Percolation percolation = Percolation(n);
            double count = 0;
            while (!percolation.percolates()) {
                /* generate secret number between 1 and n + 1: */
                int i = rand() % n + 1;
                int j = rand() % n + 1;
                if (percolation.isOpen(i, j)) continue;
                percolation.open(i, j);
                count++;
            }
            est[k] = count / (n * n);
        }
        mean = setMean(est);
        stddev = setStddev(est);
        confidenceLo = mean - (1.96 * stddev) / std::sqrt(trials);
        confidenceHi = mean + (1.96 * stddev) / std::sqrt(trials);
    }

    double getMean() { return mean; }

    double getStddev() { return stddev; }

    double getConfidenceLo() { return confidenceLo; }

    double getConfidenceHi() { return confidenceHi; }

private:
    /**
     * Returns the average value in the specified array.
     */
    double setMean(std::vector<double>& array)
    {
        double sum = 0;
        for (int i = 0; i < array.size(); ++i) {
            sum += array[i];
        }
        return sum / array.size();
    }

    /**
     * Returns the sample standard deviation in the specified array.
     */
    double setStddev(std::vector<double>& array)
    {
        return std::sqrt(var(array));
    }

    /**
     * Returns the sample variance in the specified array.
     */
    double var(std::vector<double>& array)
    {
        if (array.size() == 0) return 0.0;
        double avg = setMean(array);
        double sum = 0.0;
        for (int i = 0; i < array.size(); i++) {
            sum += (array[i] - avg) * (array[i] - avg);
        }
        return sum / (array.size() - 1);
    }

private:
    long double mean;
    long double stddev;
    long double confidenceLo;
    long double confidenceHi;
    std::vector<double> est;
};
