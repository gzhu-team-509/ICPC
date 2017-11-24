/**
 * NTA
 *
 * 难点在于建树以及填充信号表的结构
**/
#include <iostream>
#include <vector>
using namespace std;

struct signal
{
    int left, right;
};

vector<signal> table[20][20];
char tree[2048];
int treeLevel, treeDeep;
int tot, legal, unit;                   // 信号总数n，合法信号数m，发射单元数k

bool judge(int signal, int node);

int main()
{
    int kase = 0;
    while (cin >> tot >> legal >> unit, tot || legal || unit)
    {
        if (kase) cout << endl;         // 注意细节
        cout << "NTA" << ++kase << ":" << endl;

        for (int i = 0; i < tot; i++)
        {
            for (int j = 0; j < unit; j++)
            {
                table[i][j].clear();
                while (true)
                {
                    signal tmp;
                    cin >> tmp.left >> tmp.right;
                    table[i][j].push_back(tmp);

                    if (getchar() == ' ') continue;
                    else break;
                }
            }
        }

        while (cin >> treeLevel, ~treeLevel)
        {
            treeDeep = 1;
            for (int i = 0; i <= treeLevel; i++)
            {
                for (int j = 0; j < (1 << i); j++)
                {
                    cin >> tree[treeDeep];
                    treeDeep++;
                }
            }

            if (judge(0, 1)) cout << "Valid" << endl;
            else cout << "Invalid" << endl;
        }
    }
}

bool judge(int signal, int node)
{
    // 判断是否为叶子节点
    if (node >= treeDeep || tree[node] == '*')
    {
        if (signal < tot - legal) return false;
        else return true;
    }

    // 回溯搜索叶子节点
    int transmitter = tree[node] - 'a';
    for (int i = 0; i < table[signal][transmitter].size(); i++)
    {
        int left = 2 * node;
        int right = left + 1;
        int signal1 = table[signal][transmitter][i].left;
        int signal2 = table[signal][transmitter][i].right;
        if (judge(signal1, left) && judge(signal2, right)) return true;
    }
    return false;
}
