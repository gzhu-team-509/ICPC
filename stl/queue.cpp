#include <iostream>
#include <queue>
using namespace std;

int main() {
    queue<int> que;
    que.push(2017);
    que.push(11);
    que.push(10);

    while (!que.empty())
    {
        cout << que.front() << " ";
        que.pop();
    }
    cout << endl;
}
