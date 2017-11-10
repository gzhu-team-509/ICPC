#include <iostream>
#include <string>
#include <stack>
#include <vector>
using namespace std;

string a, b;                        // 原单词和目标单词
stack<char> build;                  // 构造目标字符串
vector<char> operate;               // 记录入栈出栈操作
int length;

// iPush记录入栈操作的次数，iPop记录出栈操作的次数
void dfs(int iPush, int iPop)
{
    // 当出入栈操作刚好为源单词的长度时，目标单词构造完毕，输出操作序列
    if (iPush == length && iPop == length)
    {
        for (int i = 0; i < operate.size(); i++)
        {
            cout << operate[i] << " ";
        }
        cout << endl;
    }

    // 入栈操作
    if (iPush + 1 <= length)
    {
        build.push(a[iPush]);
        operate.push_back('i');
        dfs(iPush + 1, iPop);
        build.pop();
        operate.pop_back();
    }

    // 出栈操作
    if (iPop + 1 <= iPush && iPop + 1 <= length && build.top() == b[iPop])
    {
        char tc = build.top();
        build.pop();                // 将当前字符出栈
        operate.push_back('o');     // 记录出栈操作
        dfs(iPush, iPop + 1);       // 搜索下一个位置
        build.push(tc);             // 恢复刚刚出栈的字符，便于下一个搜索
        operate.pop_back();         // 恢复出栈操作
    }
}

int main()
{
    while (cin >> a >> b)
    {
        length = a.length();
        cout << "[" << endl;
        dfs(0, 0);
        cout << "]" << endl;
    }
}
