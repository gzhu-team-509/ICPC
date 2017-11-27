/**
 * Big String
 *
 * 利用斐波那契数列的经典例题
**/
#include <iostream>
#include <string>
using namespace std;

const int LEN = 90;

long long fib[LEN];

int main()
{
    fib[0] = 7; fib[1] = 10;
    for (int i = 2; i < LEN; i++) fib[i] = fib[i - 1] + fib[i - 2];
    string base = "T.T^__^";

    long long n;
    while (cin >> n)
    {
        while (n > 7) {
            int i = 0;
            while (i < LEN && fib[i] < n) i++;
            n -= fib[i - 1];
        }

        cout << base[n - 1] << endl;
    }
}
