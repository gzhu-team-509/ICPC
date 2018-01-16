#include <bits/stdc++.h>
using namespace std;

struct LeftTree
{
	const static int MXN = 100100;
	int tot = 0;
	int l[MXN], r[MXN], v[MXN], d[MXN];
	
	int init(int x)
	{
		tot++;
		v[tot] = x;
		l[tot] = r[tot] = d[tot] = 0;
		return tot;
	}
	
	int merge(int x, int y)
	{
		if (!x) return y;
		if (!y) return x;
		if (v[x] < v[y])
			swap(x, y);
		r[x] = merge(r[x], y);
		if (d[l[x]] < d[r[x]])
			swap(l[x], r[x]);
		d[x] = d[r[x]] + 1;
		return x;
	}
	
	int insert(int x, int v)
	{
		return merge(x, init(v));
	}
	
	int top(int x)
	{
		return v[x];
	}
	
	int pop(int x)
	{
		return merge(l[x], r[x]);
	}
} t;

int main()
{
	int head = t.init(10);
	for (int i = 1; i < 10; ++i)
	{
		head = t.insert(head, rand() + 1);
		cout << t.top(head) << endl;
	}
	
	cout << endl;
	while (head != 0)
	{
		cout << t.top(head) << endl;
		head = t.pop(head);
	}
	cout << endl;
}
