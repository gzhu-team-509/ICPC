/**
 * Unscrambling Images
 *
 * 其实，输出格式与《算法设计与分析》上的格式不一样
**/
#include <cstdio>
#include <cstring>
#define sfi(a) scanf("%d", &a)
using namespace std;

int main()
{
    int N; sfi(N);
    while (N--)
    {
        int k; sfi(k); // 测试用例的数量
        for (int kase = 1; kase <= k; kase++)
        {
            if (kase != 1) printf("\n");
            printf("Case %d\n\n", kase); // 注意格式

            int n; sfi(n); // 图像栅格的宽度

            int map[256]; // 图像单元格到四叉树编码之间的映射
            int pic[400]; // 秘密图像的四叉树编码和亮度值
            memset(pic, -1, sizeof(pic));

            int mapn; sfi(mapn);
            while (mapn--) {
                int idx, intensity; sfi(idx), sfi(intensity);
                map[intensity] = idx; // 编号intensity的单元格的四叉树编码为idx
            }

            int picn; sfi(picn);
            while (picn--) {
                int idx, intensity; sfi(idx), sfi(intensity);
                pic[idx] = intensity;
            }

            // 输出单元格(i, j)的图像
            for (int i = 0; i < n; i++)
            {
                for (int j = 0; j < n; j++)
                {
                    int idx = map[i * n + j];
                    while (pic[idx] == -1) idx = (idx - 1) / 4;
                    printf("%4d", pic[idx]);
                }
                printf("\n");
            }
        }
        if (N) printf("\n"); // 处理数据块之间的空格
    }
}
