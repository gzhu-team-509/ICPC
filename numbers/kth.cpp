/**
 * 第k小数问题
 *
 * 《算法设计与分析》 P71
**/
#include <iostream>
#include <algorithm>
using namespace std;

// 在Array内选择第k小的元素
int select(int array[], int length, int k)
{
    int privot = array[0];
    int left = 1, right = length - 1;
    while (true)
    {
        while (array[left] <= privot) left++;
        while (array[right] > privot) right--;
        if (left < right) swap(array[left], array[right]);
        else break;
    }
    int nleft = right;
    if (nleft == k - 1) return privot;
    else if (nleft > k - 1) return select(array + 1, nleft, k);
    else return select(array + nleft + 1, length - nleft - 1, k - nleft - 1);
}

int main()
{
    int array[10];
    for (int i = 0; i < 10; i++) {
        array[i] = rand();
        if (i) cout << " ";
        cout << array[i];
    }
    cout << endl;

    for (int i = 1; i < 8; i++) {
        cout << i << ": " << select(array, 10, i) << endl;
    }

    sort(array, array + 10);
    for (int i = 0; i < 10; i++) {
        if (i) cout << " ";
        cout << array[i];
    }
    cout << endl;

}
