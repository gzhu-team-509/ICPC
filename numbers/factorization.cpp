/**
 * 整数因式分解
 *
 * 《算法设计与分析》 P77
**/
#include <iostream>
using namespace std;

long long solve(int n)
{
    long long ans = 1;
    for (int i = 2; i < n; i++) {
        if (n % i == 0) ans += solve(i);
    }
    return ans;
}

int main()
{
    int n;
    while (cin >> n)
    {
        cout << solve(n) << endl;
    }
}
