#include <iostream>
#include "cants.h"
using namespace std;

int main()
{
    cout << "This is an example to show hwo to use rep() and dwn()." << endl;
    cout << endl << "Let's count form 1 to 9." << endl;
    rep(i, 1, 10) cout << i << endl;
    cout << endl << "Let's count from 9 to 1." << endl;
    dwn(i, 10, 1) cout << i << endl;
}
