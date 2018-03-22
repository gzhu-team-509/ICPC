#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
typedef long long LL;

const int maxN = 100010;

LL Di[maxN], Dii[maxN];

int lowbit(int x) {
	return x &= -x;
}

void init() {
	memset(Di, 0, sizeof(Di));
	memset(Dii, 0, sizeof(Dii));
}

void add(LL *bit, int x, LL val) {
	while (x < maxN) {
		bit[x] += val;
		x += lowbit(x);
	}
}

LL sum(LL *bit, int x) {
	LL rslt = 0;
	while (x) {
		rslt += bit[x];
		x -= lowbit(x);
	}
	return rslt;
}

void add(int a, int b, LL val) {
	add(Di, a, val);
	add(Di, b+1, -val);
	add(Dii, a, -a*val);
	add(Dii, b+1, (b+1)*val);
}

LL sum(int x) {
	return sum(Di, x)*(x+1) + sum(Dii, x);
}

LL get(int a, int b) {
	return sum(b) - sum(a-1);
}

int main()
{	
	int n, q;
	while (scanf("%d%d", &n, &q) == 2)
	{
		init();
		
		for (int i=1; i<=n; ++i) {
			LL val; scanf("%lld", &val);
			add(Dii, i, val);
		}
		
		while (q--) {
			char ch; scanf(" %c", &ch);
			if (ch == 'Q') {
				int a, b; scanf("%d%d", &a, &b);
				printf("%lld\n", get(a, b));
			}
			if (ch == 'C') {
				int a, b; LL c; scanf("%d%d%lld", &a, &b, &c);
				add(a, b, c);
			}
		}
	}
}
