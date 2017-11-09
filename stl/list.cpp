#include <iostream>
#include <list>
using namespace std;

int main()
{
    list<int> lst(5 ,100);                      // 五个100
    lst.push_front(1);
    lst.push_back(200);
    list<int>::iterator p = lst.begin();

    lst.erase(p);

    // 遍历列表输出
    for (p = lst.begin(); p != lst.end(); p++)
    {
        cout << *p << " ";
    }
    cout << endl;

    lst.clear();
    cout << lst.size() << endl; 
}
