#include <iostream>
#include <algorithm>
using namespace std;

// 在n个元素的T类型非降序数组中寻找并返回key的下标
template<class T>
int binarySearch(T array[], const T& key, int n)
{
    int begin = 0, end = n - 1;
    while (begin <= end)
    {
        int middle = (begin + end) / 2;
        if (array[middle] == key) return middle;
        else if (array[middle] < key) begin = middle + 1;
        else end = middle - 1;
    }
    return -1;
}

int main()
{
    int num[10];
    for (int i = 0; i < 10; i++) num[i] = rand();
    sort(num, num + 10);
    for (int i = 0; i < 10; i++) {
        if (i) cout << " ";
        cout << num[i];
    }
    cout << endl;

    int key;
    while (cin >> key) {
        cout << binarySearch(num, key, 10) << endl;
    }
}
