/**
 * 取余运算
 *
 * 《算法设计与分析》 P77
**/
#include <iostream>
using namespace std;

long long rpow(int a, int b, int m)
{
    if (b == 1) return a % m;
    if (b % 2) return ((a % m) * rpow(a, b - 1, m)) % m;
    else return (rpow(a, b / 2, m) * rpow(a, b / 2, m)) % m;
}

int main()
{
    int a, b, m;
    while (cin >> a >> b >> m)
    {
        cout << rpow(a, b, m) << endl;
    }
}
