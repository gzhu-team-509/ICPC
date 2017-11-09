#include <map>
#include <string>
#include <iostream>
using namespace std;

int main()
{
    /* Map */
    {
        map<string, double> pricing;
        pricing["Coffee"] = 12.5;
        pricing.insert(make_pair("Banana", 2.5));

        map<string, double>::iterator p;
        for (p = pricing.begin(); p != pricing.end(); p++)
        {
            cout << p -> first << " " << p -> second << endl;
        }
    }

    cout << endl;

    /* Multimap */
    {
        multimap<string, double> pricing;
//!     pricing["Coffee"] = 12.2;
        pricing.insert(make_pair("Coffee", 13));
        pricing.insert(make_pair("Coffee", 14.5));

        multimap<string, double>::iterator p;
        for (p = pricing.begin(); p != pricing.end(); p++)
        {
            cout << p -> first << " " << p -> second << endl;
        }
    }

}
