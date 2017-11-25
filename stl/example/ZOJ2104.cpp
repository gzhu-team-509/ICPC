/* Let the Ballon Fly */
#include <iostream>
#include <map>
#include <string>
using namespace std;

int main()
{
    int n;
    while (cin >> n && n)
    {
        map<string, int> ballon;

        while (n--) {
            string s; cin >> s;
            ballon[s]++;
        }

        int mx = 0;
        map<string, int>::iterator i, loc;
        for (i = ballon.begin(); i != ballon.end(); i++)
        {
            if (i -> second > mx) {
                mx = i -> second;
                loc = i;
            }
        }

        cout << loc -> first << endl;
    }
}
