/**
 * 输油管道问题 - 中位数定理
 *
 * 《算法设计与分析》 P73
**/
#include <iostream>
#include <cmath>
using namespace std;

int well[1000];

int select(int left, int right, int k)
{
    int l = left + 1, r = right, privot = well[left];
    while (true)
    {
        while (well[l] <= privot) l++;
        while (well[r] > privot) r--;
        if (l < r) swap(well[l], well[r]);
        else break;
    }
    int nleft = r - left;
    if (nleft == k - 1) return privot;
    else if (nleft > k - 1) return select(left + 1, r, k);
    else return select(l, right, k - nleft - 1);
}

int main()
{
    int n; cin >> n;

    int x; // x坐标，读取后丢弃
    for (int i = 0; i < n; i++) cin >> x >> well[i];
    int pos = select(0, n - 1, n / 2);

    int sum = 0;
    for (int i = 0; i < n; i++) {
        sum += abs(well[i] - pos);
    }
    cout << sum << endl;
}
