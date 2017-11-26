/* Trees Made to Order - Catalan，递归
 *
 * 计数问题要保持清醒头脑，从0开始计数使得整除“/”和取模“%”运算保持清楚的意义。
 * 偏移计数法（寻址计数法）与整除取模运算，配合形态种类能写出简洁的代码。
**/
#include <iostream>
using namespace std;

int h[20]; // Catalan，具有n个节点的二叉树的形态数
int S[20]; // 具有n个节点的第一棵二叉树的编号

void init()
{   // 计算Catalan数
    h[0] = 1; h[1] = 1;
    S[0] = 0; S[1] = 1;
    for (int i = 2; i < 20; i++)
    {
        for (int j = 0, k = i - 1; k >= 0; j++, k--) h[i] += h[j] * h[k];
        S[i] = S[i - 1] + h[i - 1];
    }
}

// 输出编号为idx的二叉树
void outTree(int idx)
{
    if (idx == 1) printf("X");
    else
    {
        // 确定二叉树节点的数量
        int tot = 0;
        while (S[tot + 1] <= idx) tot++;
        idx -= S[tot];

        // 确定左右子树节点的数量
        int lf, rt;
        for (blf = 0, rt = tot - 1; h[lf] * h[rt] <= idx; lf++, rt--)
        {
            idx -= h[lf] * h[rt];
        }

        // 确定左右子树节点的序号
        int lfidx, rtidx;
        lfidx = idx / h[rt] + S[lf];
        rtidx = idx % h[rt] + S[rt];

        // 输出左树
        if (lfidx)
        {
            printf("(");
            outTree(lfidx);
            printf(")");
        }

        // 输出根
        printf("X");

        // 输出右树
        if (rtidx)
        {
            printf("(");
            outTree(rtidx);
            printf(")");
        }
    }
}

int main()
{
    init(); // for (int i = 0; i < 20; i++) printf("%d\n", S[i]);

    int n;
    while (cin >> n && n) outTree(n), printf("\n");
}
