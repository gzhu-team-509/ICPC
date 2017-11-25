/**
 * Parencoding
 *
 * 用-1表示左括号，非负值表示右括号的个数。
**/
#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main()
{
    int t; cin >> t;
    while (t--)
    {
        stack<int> bracket;
        string w;

        int lst = 0, n; cin >> n;
        for (int i = 0; i < n; i++)
        {
            int cur; cin >> cur;
            int tot = cur - lst;
            while (tot--) bracket.push(-1);
            lst = cur;

            int idle = 0;
            while (bracket.top() != -1) {
                idle += bracket.top();
                bracket.pop();
            }
            bracket.pop();
            idle++;
            bracket.push(idle);
            w += to_string(idle);
        }

        for (int i = 0; i < w.length(); i++)
        {
            if (i) cout << " ";
            cout << w[i];
        }
        cout << endl;
    }
}
