#include <iostream>
using namespace std;

const int MAX = 400;
// 斐波那契极限
// int 至多26项（unsigned 27项）
// long long 至多92项（unsigned 93项）
// double 超过100项，精度随在项数达到一定程度后降低

double fib[MAX];

int main()
{
    cout.flags(cout.fixed);

    fib[0] = 0; fib[1] = 1;
    cout << "1: " << fib[1] << endl;
    for (int i = 2; i < MAX; i++)
    {
        fib[i] = fib[i - 1] + fib[i - 2];
        cout << i << ": " <<  fib[i] << endl;
    }
}
