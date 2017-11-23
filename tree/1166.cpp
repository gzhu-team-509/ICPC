/**
 * HDU1166 - 敌兵布阵
**/
#include <cstdio>
#include <cstring>
#define sfi(a) scanf("%d", &a);
#define sfs(a) scanf("%s", a);

const int LEVEL = 17; // 树的层数
const int INDEX = 1 << (LEVEL - 1);
int tree[1 << (LEVEL + 1)];

void build();
void show();
void update(int, int);
int query(int, int);

int main()
{
    int t; sfi(t); // 测试用例的数量
    for (int kase = 1; kase <= t; kase++)
    {
        // memset(tree, 0, sizeof(tree));

        int n; sfi(n); // 工兵营地的数量
        for (int i = 1; i <= n; i++) sfi(tree[INDEX + i]);

        build(); // 建树

        printf("Case %d:\n", kase);
        while (true)
        {
            char cmd[10]; sfs(cmd);

            if (cmd[0] == 'A') {
                int i, j; sfi(i); sfi(j);
                update(i, j);
            }
            if (cmd[0] == 'S') {
                int i, j; sfi(i); sfi(j);
                update(i, -j);
            }
            if (cmd[0] == 'Q') {
                int i, j; sfi(i); sfi(j);
                printf("%d\n", query(i - 1, j + 1));
            }
            if (cmd[0] == 'E') break;
        }
    }
}

// 建树
void build()
{
    for (int level = LEVEL; level; --level)
    {
        for (int end = 1 << level, head = end >> 1; head < end; head++)
            tree[head >> 1] += tree[head];
    }
}

// 打印树
void show()
{
    for (int level = 1; level <= LEVEL; level++)
    {
        for (int end = 1 << level, head = end >> 1; head < end; head++)
            if (head ^ (1 << (level - 1))) printf(" %d", tree[head]);
            else printf("%d", tree[head]);
        printf("\n");
    }
}

// 将节点node的值增加diff
void update(int node, int diff)
{
    for (node += INDEX; node; node >>= 1) tree[node] += diff;
}

// 查询开区间(left, right)内元素的和
// left, right ∈ [1, 2^N - 2]
int query(int left, int right)
{
    int tot = 0;
    for (left += INDEX, right += INDEX; left ^ right ^ 1; left >>= 1, right >>= 1)
    {
        if (~left & 1) tot += tree[left + 1];
        if (right & 1) tot += tree[right - 1];
    }
    return tot;
}
