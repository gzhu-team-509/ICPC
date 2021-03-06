// 张昆玮线段树的一种实现，适用于单点修改，区间和查询
// 清空树，建树，修改和查询
#include <bits/stdc++.h>
using namespace std;

struct ZWKSegmentTree
{
	int levl;
	long long *node, *head;
	long long bgn, end;
	
	ZWKSegmentTree(int n)
	{
		levl = n;
		bgn = 1 << (levl - 1), end = 1 << levl;
		node = new long long[end], head = node + bgn;
	}
	
	void clear()
	{
		memset(node, 0, end * sizeof(long long));
	}
	
	void build()
	{
		for (long long i = bgn; i < end; ++i)
		{
			long long cur = i;
			while (cur >>= 1) node[cur] += node[i];
		}
	}
	
	void update(int n, int v)
	{
		n += bgn;
		do {
			node[n] += v;
		} while (n >>= 1);
	}
	
	// 查询开区间(a, b)内的元素和
	long long query(int a, int b)
	{
		long long tot = 0;
		for (a += bgn - 1, b += bgn + 1; a ^ b ^ 1; a >>= 1, b >>= 1)
		{
			if (~a&1) tot += node[a + 1];
			if (b&1) tot += node[b - 1];
		}
		return tot;
	}
} t(17);

int main()
{
	#ifdef LOCAL
	freopen("in.txt", "r", stdin);
	#endif
	
	int t, kase = 0; scanf("%d", &t); 
	while (t--)
	{
		printf("Case %d:\n", ++kase);
		
		T.clear();
		int n; scanf("%d", &n);
		for (int i = 1; i <= n; ++i)
		{
			scanf("%lld", &T.head[i]); 
		}
		T.build();
		
		char cmd[10];
		while (scanf("%s", cmd) == 1)
		{
			if (cmd[0] == 'Q')
			{
				int a, b; scanf("%d%d", &a, &b);
				printf("%lld\n", T.query(a, b));
			}
			if (cmd[0] == 'A')
			{
				int n, v; scanf("%d%d", &n, &v);
				T.update(n, v);
			}
			if (cmd[0] == 'S')
			{
				int n, v; scanf("%d%d", &n, &v);
				T.update(n, -v);
			}
			if (cmd[0] == 'E') break;
		}
	}
}

