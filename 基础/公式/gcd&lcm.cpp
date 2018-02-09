#include <bits/stdc++.h>
using namespace std;
using LL = unsigned long long;

LL gcd(LL a, LL b)
{
	return b == 0 ? a : gcd(b, a%b);
}

LL lcm(LL a, LL b)
{
	return a*b / gcd(a, b);
}

LL lcm(vector<LL> vec)
{
	if (vec.size() == 1) return vec[0];
	LL cur = lcm(vec[0], vec[1]);
	for (unsigned i = 2; i < vec.size(); ++i)
	{
		cur = lcm(cur, vec[i]);
	}
	return cur;
}

int main()
{	
	vector<LL> vec;
	for (int i = 1; i < 50; ++i) // overflow when i > 43 
	{
		vec.push_back(i);
		
		if (i == 44) cout << "-- Warning: Overflow! --" << endl;
		cout << i << ": " << lcm(vec) << endl; 
	}
}

