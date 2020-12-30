/*

union-find 算法的 API

class WeightedQuickUnionUF

WeightedQuickUnionUF(int N)     以整数标示(o 到 N - 1) 初始化 N 个触点
void Union(int p, int q)        在 p 和 q 之间添加一条连接
int find(int p)                 p (0 到 N - 1) 所在的分量的标示符
bool connected(int p, int q)    如果 p 和 q 存在于同一个分量中则返回 true
int count()                     连通分量的数量

*/

#include <iostream>
#include <vector>

class WeightedQuickUnionUF {
public:
    WeightedQuickUnionUF() { }
    WeightedQuickUnionUF(int N)
    {
        cnt = N;
        id = std::vector<int>(N);
        for (int i = 0; i < N; ++i) id[i] = i;
        sz = std::vector<int>(N);
        for (int i = 0; i < N; ++i) sz[i] = 1;
    }
    int count() { return cnt; }
    int find(int p)
    {
        // 跟随链接找到根节点
        while (p != id[p]) {
            id[p] = id[id[p]];  // 使每一个节点指向它的父节点
            p = id[p];
        }
        return p; 
    }
    void Union(int p, int q)
    {
        int i = find(p);
        int j = find(q);
        if (i == j) return;

        // 将小树的根节点连接到大树的根节点
        if (sz[i] < sz[j]) {
            id[i] = j; sz[j] += sz[i];
        } else {
            id[j] = i; sz[i] += sz[j];
        }
        
        cnt--;
    }
    bool connected(int p, int q) { return find(p) == find(q); }
private:
    std::vector<int> id;
    std::vector<int> sz;
    unsigned int cnt;
};