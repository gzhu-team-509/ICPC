/**
 * 回溯法（深度优先搜索）产生给定集合的全排列
 *
 * 《算法设计与分析》 P61
**/
#include <iostream>
using namespace std;

int list[6] = {1, 2, 3, 4, 5, 6};

// 产生数组下标为k至的m的元素的全排列
void permutation(int array[], int k, int m)
{
    if (k == m) {
        for (int i = 0; i <= m; i++) {
            if (i) cout << " ";
            cout << array[i];
        }
        cout << endl;
    }

    for (int i = k; i <= m; i++)
    {
        swap(array[k], array[i]);
        permutation(array, k + 1, m);
        swap(array[i], array[k]);
    }
}

int main()
{
    permutation(list, 0, 3);
}
