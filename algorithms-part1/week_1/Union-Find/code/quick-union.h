/*

union-find 算法的 API

class UF

UF(int N)                       以整数标示(o 到 N - 1) 初始化 N 个触点
void Union(int p, int q)        在 p 和 q 之间添加一条连接
int find(int p)                 p (0 到 N - 1) 所在的分量的标示符
bool connected(int p, int q)    如果 p 和 q 存在于同一个分量中则返回 true
int count()                     连通分量的数量

*/

#include <iostream>
#include <vector>

class UF {
public:
    UF(int N)
    {
        cnt = N;
        id = std::vector<int>(N);
        for (int i = 0; i < N; ++i) {
            id[i] = i;
        }
    }
    int count() { return cnt; }
    int find(int p)
    {
        // 找出分量的名称
        while (p != id[p]) p = id[p];
        return p; 
    }
    void Union(int p, int q)
    {
        // 将 p 和 q 的根节点统一
        int pRoot = find(p);
        int qRoot = find(q);
        if (pRoot == qRoot) return;

        id[pRoot] = qRoot;
        
        cnt--;
    }
    bool connected(int p, int q) { return find(p) == find(q); }
private:
    std::vector<int> id;
    unsigned int cnt;
};