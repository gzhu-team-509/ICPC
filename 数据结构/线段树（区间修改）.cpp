// 清空树，建树，修改和查询
const int maxN = 100100;
struct SegmentTreeNode{
	int l, r;
	long long val, vmx, vmn;
	long long lazy;
} node[maxN<<2];

void init()
{
	memset(node, 0, sizeof(node));
}

void build(int rt, int l, int r, long long *arr)
{
	node[rt].l = l, node[rt].r = r;
	node[rt].lazy = 0;
	if (l==r)
	{
		node[rt].val = node[rt].vmx = node[rt].vmn = arr[l];
	}
	else
	{
		int mid = (l+r)/2;
		build(rt<<1, l, mid, arr);
		build(rt<<1|1, mid+1, r, arr);
		node[rt].val = node[rt<<1].val + node[rt<<1|1].val;
		node[rt].vmx = max(node[rt<<1].vmx, node[rt<<1|1].vmx);
		node[rt].vmn = min(node[rt<<1].vmn, node[rt<<1|1].vmn);
	}
}
 
void pushdown(int rt)
{
	if (node[rt].lazy) {
		node[rt].val += node[rt].lazy*(node[rt].r-node[rt].l+1);
		node[rt].vmx += node[rt].lazy;
		node[rt].vmn += node[rt].lazy;
		node[rt<<1].lazy += node[rt].lazy;
		node[rt<<1|1].lazy += node[rt].lazy;
	}
	node[rt].lazy = 0;
}

long long query(int rt, int l, int r)
{
	if (node[rt].l==l&&node[rt].r==r)
		return node[rt].val + node[rt].lazy*(node[rt].r-node[rt].l+1);
	pushdown(rt);
	int mid = (node[rt].l+node[rt].r)/2;
	if (r<=mid)
		return query(rt<<1, l, r);
	else if(mid<l)
		return query(rt<<1|1, l, r);
	else
		return query(rt<<1, l, mid) + query(rt<<1|1, mid+1, r);
}

long long query_max(int rt, int l, int r)
{
	if (node[rt].l==l&&node[rt].r==r) 
		return node[rt].vmx + node[rt].lazy;
	pushdown(rt);
	int mid = (node[rt].l+node[rt].r)/2;
	if (r<=mid)
		return query_max(rt<<1, l, r);
	else if(mid<l)
		return query_max(rt<<1|1, l, r);
	else
		return max(query_max(rt<<1, l, mid), query_max(rt<<1|1, mid+1, r));
}

long long query_min(int rt, int l, int r)
{
	if (node[rt].l==l&&node[rt].r==r)
		return node[rt].vmn + node[rt].lazy;
	pushdown(rt);
	int mid = (node[rt].l+node[rt].r)/2;
	if (r<=mid)
		return query_min(rt<<1, l, r);
	else if(mid<l)
		return query_min(rt<<1|1, l, r);
	else
		return min(query_min(rt<<1, l, mid), query_min(rt<<1|1, mid+1, r));
}

void update(int rt, int l, int r, int diff)
{
	if (l<=node[rt].l&&node[rt].r<=r) {
		node[rt].lazy += diff;
		return;
	}
	int mid = (node[rt].l+node[rt].r)/2;
	if (r<=mid) {
		update(rt<<1, l, r, diff);
	} 
	else if (mid<l) {
		update(rt<<1|1, l, r, diff);
	}
	else {
		update(rt<<1, l, r, diff);
		update(rt<<1|1, l, r, diff);
	}
	node[rt].val = query(rt<<1, node[rt].l, mid) + query(rt<<1|1, mid+1, node[rt].r);
	node[rt].vmx = max(query_max(rt<<1, node[rt].l, mid), query_max(rt<<1|1, mid+1, node[rt].r)); 
	node[rt].vmn = min(query_min(rt<<1, node[rt].l, mid), query_min(rt<<1|1, mid+1, node[rt].r)); 
}
