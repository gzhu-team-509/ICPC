#include <cstdlib>
#include <ctime>
#include <stack>
#include <iostream>
using namespace std;

#define rep(i, a, b) for (int i = int(a); i < int(b); i++)

int main() {
    stack<int> stk;

    // 入栈
    rep(i, 0, 10)
    {
        stk.push(rand());
    }

    // 出栈
    rep(i, 0, 10)
    {
        cout << stk.top() << endl;
        stk.pop();
    }

    // 入栈
    rep(i, 0, 10)
    {
        stk.push(rand());
    }

    // 清空栈方式1
    while (stk.size())
    {
        cout << stk.top() << endl;
        stk.pop();
    }

    // 入栈
    rep(i, 0, 10)
    {
        stk.push(rand());
    }

    // 清空栈方式2
    while (!stk.empty())
    {
        cout << stk.top() << endl;
        stk.pop();
    }
}
