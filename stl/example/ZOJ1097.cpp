/**
 * Code the Tree
 *
 * 不要定义全局的Vector，然后使用clear()来清空Vector，这样会导致Vector的容量变为0。
 * 注意函数传参时要传递Vector的引用。
**/
#include <iostream>
#include <vector>
#include <set>
#include <queue>
using namespace std;

void parse(vector<set<int>> &adj, int p = 0) // p = 0表示第一次读取编号
{
    int x; cin >> x; // 下一个节点的编号

    if(p) {
        adj[p].insert(x);
        adj[x].insert(p);
    }

    while (true)
    {
        char ch; cin >> ch;
        if (ch == '(') parse(adj, x);
        else break;
    }
}

int main()
{
    cin.tie(0); cout.tie(0); ios_base::sync_with_stdio(false);
//! while (scanf(" ( ") != EOF) 启用流加速后不要混用cin和stdin

    char ch;
    while (cin >> ch)
    {
        vector<set<int>> adj(1024, set<int>()); // adjacent
        priority_queue<int, vector<int>, greater<int>> leafs;

        // 取得节点关系
        parse(adj);

        // 统计节点的个数
        int n = 0;
        for (int i = 0; i < adj.size(); i++)
        {
            if (adj[i].size()) {
                n++;
                if (adj[i].size() == 1) {
                    leafs.push(i);
                }
            }
        }

        // 生成Prufer编码
        for (int i = 1; i < n; i++)
        {
            int p = leafs.top();
            leafs.pop();

            int q = *(adj[p].begin()); // 与p相邻的节点q
            adj[p].erase(q);
            adj[q].erase(p);
            if (adj[q].size() == 1) leafs.push(q);

            if (i > 1) cout << " ";
            cout << q;
        }
        cout << endl;
    }
}
