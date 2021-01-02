#include <iostream>
#include <vector>

#include "WeightedQuickUnionUF.h"

class Percolation {
public:
    // creates n-by-n grid, with all sites initially blocked
    Percolation() { }

    explicit Percolation(int n)
    {
        this->n = n + 1;
        uf = WeightedQuickUnionUF(this->n * this->n);
        matrix = std::vector<bool>((this->n * this->n), false);

        // (0, 0) 作为头虚拟节点, 并与有效矩阵中的第一行连通
        for (int i = 1; i < this->n; i++) {
            uf.Union(0, translator(1, i));
        }

        // (0, 1) 作为尾虚拟节点, 并与有效矩阵中的最后一行连通
        for (int i = 1; i < this->n; i++) {
            uf.Union(1, translator(this->n - 1, i));
        }
    }
    // opens the site (row, col) if it is not open already
    void open(int row, int col)
    {
        if (isOpen(row, col)) return;
        matrix[translator(row, col)] = true;
        num++;

        // if above site is open, Union them
        if (row - 1 > 0 && isOpen(row - 1, col)) {
            uf.Union(translator(row - 1, col), translator(row, col));
        }
        // if below site is open, Union them
        if (row + 1 < n && isOpen(row + 1, col)) {
            uf.Union(translator(row + 1, col), translator(row, col));
        }
        // if left site is open, Union them
        if (col - 1 > 0 && isOpen(row, col - 1)) {
            uf.Union(translator(row, col - 1), translator(row, col));
        }
        // if right site is open, Union them
        if (col + 1 < n && isOpen(row, col + 1)) {
            uf.Union(translator(row, col + 1), translator(row, col));
        }
    }

    // is the site (row, col) open?
    bool isOpen(int row, int col)
    {
        return matrix[translator(row, col)];
    }

    /**
     * 检查该点是否已经打开并且已经与顶部的虚拟点（相当于顶部的一排）连通
     * 用 WeightedQuickUnionUF 的 connected() 方法检测
     */
    // is the site (row, col) full?
    bool isFull(int row, int col)
    {
        return isOpen(row, col) && uf.connected(translator(row, col), 0);
    }

    // returns the number of open sites
    int numberOfOpenSites() { return num; }

    // does the system percolate?
    bool percolates() { return uf.connected(0, 1); }

private:
    /**
     * translate 2 dimension coordinate to 1 dimension pattern
     */
    inline int translator(int row, int col)
    {
        validate(row, col);
        return row * this->n + col;
    }

    /**
     * Validate the row and col indices.
     */
    inline void validate(int row, int col)
    {
        if (row <= 0 || row >= n) {
            std::cout << "the value of row and col is invalid" << std::endl;
            return;
        }
        if (col <= 0 || row >= n) {
            std::cout << "the value of row and col is invalid" << std::endl;
            return;
        }
    }

private:
    int n;
    WeightedQuickUnionUF uf;
    std::vector<bool> matrix;
    int num;
};