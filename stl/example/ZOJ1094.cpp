/* Matrix Chain Mutiplication */
#include <iostream>
#include <string>
#include <map>
#include <stack>
using namespace std;

struct Node
{
    int row, col;
};

map<char, Node> matrix;

int main()
{
    int n;
    cin >> n;
    while (n--)
    {
        char name;
        cin >> name;
        cin >> matrix[name].row >> matrix[name].col;
    }

    string exp;
    while (cin >> exp)
    {
        stack<Node> array;
        long long cnt = 0;
        int i;                                          // 哨兵变量
        for (i = 0; i < exp.length(); i++)
        {
            if (exp[i] == '(') continue;
            if (exp[i] == ')') 
            {
                Node b = array.top();
                array.pop();
                Node a = array.top();
                array.pop();
                if (a.col != b.row)
                {
                    cout << "error" << endl;
                    break;
                }
                cnt += a.row * a.col * b.col;
                Node tmp = {a.row, b.col};
                array.push(tmp);
            }
            else array.push(matrix[exp[i]]);
        }

        if (i == exp.size()) cout << cnt << endl;
    }
}
