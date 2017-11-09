#include <vector>
#include <iostream>
#include <ctime>
#include <cstdlib>
using namespace std;

int main()
{
    /* 构造函数 */
    {
        vector<int> vct;                // 空Vector
        vector<int> vct1(10);           // 初始化为大小为10的Vector
        vector<int> vct2(10, 0);        // 初始化为大小为10，每个元素的值都为0的Vector
        vector<int> vct3(vct1);         // 另一个Vector的副本
    }

    vector<int> vct;
    for (int i = 0; i < 10; i++)
    {
        vct.push_back(rand());
    }

    /* 下标访问 */
    {
        for (int i = 0; i < 10; i++)
        {
            cout << vct[i] << " ";
        }
        cout << endl;
    }

    /* 迭代器访问 */
    {
        vector<int>::iterator p;
        for (p = vct.begin(); p!=vct.end(); p++)
        {
            cout << *p << " ";
        }
        cout << endl;
    }

    /* 删除元素 */
    {
        // while (vct.size()) vct.pop_back();
        vct.clear();
        cout << vct.size() << endl;
    }
}
