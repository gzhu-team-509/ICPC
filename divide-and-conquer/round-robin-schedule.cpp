/**
 * 循环赛日程表
 *
 * 《算法设计与分析》 P66
**/
#include <iostream>
#include <cmath>
#include <cstring>
using namespace std;

const int MAXN = 100;

int schedule[MAXN][MAXN];

void copy(int begin, int edge)
{
    for (int i = 0; i < edge; i++)
    for (int j = 0; j < edge; j++) {
//      复制总应该从第一行开始
//!     schedule[begin + edge + i][begin + edge + j] = schedule[begin + i][begin + j];
//!     schedule[begin + edge + i][begin + j] = schedule[begin + i][begin + edge + j];
        schedule[1 + edge + i][begin + edge + j] = schedule[1 + i][begin + j];
        schedule[1 + edge + i][begin + j] = schedule[1 + i][begin + edge + j];
    }
}

int main()
{
    int k;
    while (cin >> k && k > 0)
    {
        int tot = pow(2, k); // 最终日程表的边长
        for (int i = 1; i <= tot; i++) schedule[1][i] = i;

        int edge = 1; // 复制单元的边长
        while (edge < tot)
        {
            int cnt = tot / (edge * 2); // 复制进行的组数
            for (int i = 1; i <= cnt; i++)
                copy(1 + 2 * edge * (i - 1), edge);
            edge *= 2;
        }

        for (int i = 1; i <= tot; i++) {
            for (int j = 1; j <= tot; j++) {
                if (j != 1) cout << " ";
                cout << schedule[i][j];
            }
            cout << endl;
        }
        cout << endl;
    }
}
