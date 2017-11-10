#include <iostream>
#include <set>
using namespace std;

int main()
{
    set<string> fruits;
    fruits.insert("Apple");
    fruits.insert("Banana");
    fruits.insert("Grapes");
    fruits.insert("Orange");

    set<string>::iterator p = fruits.find("Orange");
    cout << *p << endl;
}
