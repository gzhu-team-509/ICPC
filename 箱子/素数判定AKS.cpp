#include <bits/stdc++.h>
using namespace std;
using LL = long long;

// AKS判定算法 “一般的、多项式的、确定性的和无仰赖的” 
// O(log12(n))

// @TODO:
// 查证 isn2() 函数 

// Reference:
// https://zh.wikipedia.org/zh-hans/AKS%E8%B3%AA%E6%95%B8%E6%B8%AC%E8%A9%A6

auto square = [](LL x) {
	return x*x;
};

LL gcd(LL a, LL b)
{
	return b == 0 ? a : gcd(b, a%b);
}

LL fpow(LL a, LL b)
{
	LL ans = 1, base = a;
	while (b)
	{
		if (b&1) ans *= base;
		base *= base, b >>= 1;
	}
	return ans;
}

LL fpow(LL a, LL b, LL mod)
{
	LL ans = 1, base = a%mod;
	while (b)
	{
		if (b&1) ans *= base, ans %= mod;
		base *= base, base %= mod, b >>= 1;
	}
	return ans;
}
 
// 判定n（奇数）是否为平方数 
bool isn2(LL n)
{
	if (n%3 == 2) return false;
	LL l = ceil(log(n)/log(3)/2), r = floor(log2(l));
	LL g = 1, s = 2;
	for (LL m = 1; m <= r; ++m)
	{
		LL mod = fpow(3, 1LL<<m);
		LL ng = (s * (g - g*g - n) + mod) % mod;
		LL ns = (2*s - 2*g*square(s) + mod) % mod;
		g = ng, s = ns;
	}
	g = (g-s*(g*g-n) + fpow(3, l)) % fpow(3, l);
	if (g*g == n) return true;
	if (square(fpow(3, l)-g) == n) return true;
	return false;
}

int main()
{
	for (int i = 1; i <= 1000; ++i)
	{
		if (i & 1 && isn2(i))
		{
			cout << i << endl;
		}
	}
}

