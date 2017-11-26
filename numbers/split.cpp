/**
 * 整数划分问题
 *
 * n的k划分是指n的一个最大加数不超过k的划分
 * 《算法设计与分析》 P62
**/
#include <iostream>
using namespace std;

// 计算正整数n的k划分数量
int split(int n, int k)
{
    if (n == 1 || k == 1) return 1;
    else if (k > n) return split(n, n);
    else if (n == k) return 1 + split(n, n - 1);
    else return split(n - k, k) + split(n, k - 1);
}

// 计算正整数n的划分数量
int split(int n)
{
    return split(n, n);
}

int main()
{
    int n;
    while (cin >> n)
    {
        cout << split(n) << endl;
    }
}
