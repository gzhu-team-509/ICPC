/* Incomplete */
/**
 * Unscrambling Images
 *
 * 我的实现：
 * 计算出图像栅格对应的四叉树编码，然后输出。
 * 这样很浪费时间，因为图像的四叉树编码方式是自己想出来的，题目中并没有明确给出
 * （暗示不需要直到具体的编码方式）
 * 直接向标程那样一步到位得到栅格对应的四叉树编码是最简便的做法。
**/
#include <cstdio>
#define sfi(a) scanf("%d", &a)
using namespace std;

int main()
{
    int N; sfi(N); // 测试数据块，每个数据块之间有一个空行
    while (N--)
    {
        int k; sfi(k); // 每个数据块中测试用例的数量
        for (int kase = 1; kase <= k; kase++)
        {
            printf("Case %d\n", kase);

            int n; sfi(n); // 栅格的宽度

            int map[400]; // 根据测试图像建立的映射关系
            int pic[400]; // 储存待解密的节点
            memset(pic, -1, sizeof(pic));

            int mapn; sfi(mapn); // 测试图像的节点数量
            for (int i = 0; i < mapn; i++) // 建立节点映射关系
            {
                int idx, intensity; scanf("%d%d", &idx, &intensity);
                map[idx] = intensity;
            }

            int picn; sfi(picn); // 秘密图像的节点数量
            for (int i = 0; i < picn; i++)
            {
                int idx, intensity; scanf("%d%d", &idx, &intensity);
                pic[map[idx]] = intensity;
            }

        }

        if (N) printf("\n"); // 输出数据块末尾的空行
    }
}
