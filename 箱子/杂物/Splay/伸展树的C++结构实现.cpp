#include <bits/stdc++.h>
using namespace std;

// HYSBZ-1588
// Splay implement with C++ structure
// This code might confuse you.

// Splay Elementary
// Basic - https://hrbust-acm-team.gitbooks.io/acm-book/content/data_structure/ds_part4.html
// Example - http://www.cnblogs.com/kuangbin/archive/2013/03/17/2964546.html
// Sigle-spin and Double-spin - http://www.cnblogs.com/TheRoadToTheGold/p/6372344.html
// Proof - https://www.zhihu.com/question/40777845/answer/175396400

const int maxN = 100100; 
const int INF  = 0x3F3F3F3F;

int head, tot;
struct {
	int val, ch[2]; // ch[0]: left son.
	int fa;
} node[maxN];

// Assign a new node with father and value
int assign(int fa, int val)
{
	++tot;
	node[tot].fa = fa, node[tot].val = val;
	node[fa].ch[node[fa].val < val] = tot;
	if (head == 0) head = tot;
	return tot;
}

// Rotate a node x; kind==0: left-spin
void rotate(int x, int kind) // Die3: Messup rotate
{
	int y = node[x].fa;
	node[y].ch[!kind] = node[x].ch[kind];
	node[node[x].ch[kind]].fa = y;
	if (node[y].fa)
		node[node[y].fa].ch[node[node[y].fa].ch[1]==y] = x;
	node[x].fa = node[y].fa;
	node[x].ch[kind] = y;
	node[y].fa = x;
} 

// Splay node x under node goal 
void splay(int x, int goal)
{
	while (node[x].fa != goal)
	{
		if (node[node[x].fa].fa == goal) // Die1: Mistake "==" for "="
			rotate(x, node[node[x].fa].ch[0] == x);
		else 
		{
			int y = node[x].fa;
			int kind = node[node[y].fa].ch[0] == y;
			if (node[y].ch[kind] == x) {
				rotate(x, !kind);
				rotate(x, kind);
			}
			else {
				rotate(y, kind);
				rotate(x, kind);
			}
		}
	}
	if (goal == 0) head = x; // Die2: Forget to update
}

int insert(int x)
{
	int cur = head;
	while (node[cur].ch[node[cur].val < x])
		cur = node[cur].ch[node[cur].val < x];
	int idx = assign(cur, x);
	splay(idx, 0);
	return idx;
}

// Return the largest value which is lower than node[x].val
int lower(int x)
{
	int nxt = node[x].ch[0];
	if (!nxt) return INF;
	while (node[nxt].ch[1])
		nxt = node[nxt].ch[1];
	return node[nxt].val;
} 

// Return the smallest value which is higher than node[x].val
int higher(int x)
{
	int nxt = node[x].ch[1];
	if (!nxt) return INF;
	while (node[nxt].ch[0])
		nxt = node[nxt].ch[0];
	return node[nxt].val;
}

int main()
{
	int n; scanf("%d", &n);
	
	int ans = 0, cur; scanf("%d", &cur);
	ans += cur; insert(cur);
	
	while (--n)
	{
		scanf("%d", &cur);
		int idx = insert(cur);
		
		int a = lower(idx);
		int b = higher(idx);
		ans += min(abs(a-cur), abs(b-cur));
	}
	printf("%d\n", ans);
}

