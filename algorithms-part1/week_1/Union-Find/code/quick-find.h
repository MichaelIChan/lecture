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
    int find(int p) { return id[p]; }
    void Union(int p, int q)
    {
        // 将 p 和 q 归并到相同的分量中
        int pID = find(p);
        int qID = find(q);

        // 如果 p 和 q 已经在相同的分量之中则不需要采取任何行动
        if (pID == qID) return;

        // 将 p 的分量重命名为 q 的名称
        for (int i = 0; i < id.size(); ++i) {
            if (id[i] == pID) id[i] = qID;
        }
        cnt--;
    }
    bool connected(int p, int q) { return find(p) == find(q); }
private:
    std::vector<int> id;
    unsigned int cnt;
};