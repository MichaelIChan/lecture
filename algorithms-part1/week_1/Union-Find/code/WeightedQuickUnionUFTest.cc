// #include "quick-find.h"
// #include "quick-union.h"
#include "WeightedQuickUnionUF.h"

int main(void)
{
    int p, q;
    int N;
    std::cin >> N;
    WeightedQuickUnionUF uf = WeightedQuickUnionUF(N);

    while (std::cin >> p >> q) {
        if (uf.connected(p, q)) continue;   // 如果已连通则忽略
        uf.Union(p, q);                     // 归并分量
        std::cout << p << " " << q << std::endl;
    }
    std::cout << uf.count() << "components" << std::endl;

    return 0;
}