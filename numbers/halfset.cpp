/**
 * 半数集问题
 *
 * 《算法设计与分析》 P75
**/
#include <iostream>
using namespace std;

long long cache[1000];

long long cal(int n)
{
    if (cache[n]) return cache[n];

    long long ans = 1;
    if (n == 1) ans = 1;
    for (int i = 1; i <= n / 2; i++)
    {
        ans += cal(i);
    }
    cache[n] = ans;
    return ans;
}

int main()
{
    int n;
    while (cin >> n)
    {
        cout << cal(n) << endl;
    }
}
