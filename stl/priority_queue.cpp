#include <queue>
#include <string>
#include <iostream>
using namespace std;

int main()
{
    /* 自定义结构 */
    {
        struct info
        {
            string name;
            double score;
            /* 重载使score最小的info处于堆顶 */
            bool operator < (const info &rhs) const
            {
                return rhs.score < score;
            }
        };

        priority_queue<info> que;

        info in;
        in.name = "Jack";
        in.score = 20;
        que.push(in);
        in.name = "Tommas";
        in.score = 30;
        que.push(in);
        in.name = "John";
        in.score = 99;
        que.push(in);

        cout << que.top().name << " " << que.top().score << endl;
    }

    cout << endl;

    {
        /* 使用仿函数Greater<T>来声明最小化堆 */
        priority_queue<int, std::vector<int>, greater<int>> que;
        que.push(200);
        que.push(100);
        que.push(1);

        cout << que.top() << endl;
    }

}
