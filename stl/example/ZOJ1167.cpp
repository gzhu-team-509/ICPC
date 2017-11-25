/**
 * Trees on the Level
 *
 * 节点存在而其父节点不存在的二叉树是不完整的（根节点除外）
 * 这样的编程风格可能不算很好，因为它在3处地方打印结果，并且容易因为忘记初始化变量而WA。
 * 要记得在下一次接受数据前初始化。
 *
 * 此题的另一个难点是每棵二叉树不多于256个节点，这题的数据给得相当仁慈。
 * 以我的这种映射方式，别说是256个节点，就算是一个节点(1,LLLLLLLLLLLLLLLLLLLLLLL)。
 * 也未必能处理好这个数据。网络上的大神都用其他映射方式来做题。
 *
 * 此题为我敲响警钟：理解好题意，正确地分配空间。
**/
#include <cstring>
#include <cstdio>
using namespace std;

bool complete;
int tree[14000], maxNode;
//! tree[300] 试图用300的数组空间装下256个节点是不可能的，会导致Segment Fault

void init()
{
    memset(tree, 0, sizeof(tree));
    tree[0] = 1; // 根节点的虚拟父节点
    maxNode = 0;
    complete = true;
}

int main()
{
    init(); char ch;
    while (scanf(" %c", &ch) == 1)
    {
        int data = 0;
        if (scanf(" %d", &data) == 1)
        {
            scanf(" %*c");

//!         char pos[10]; scanf("%[^)]", pos);
// 使用局部cstring要注意初始化，尤其是想通过scanf()对它进行初始化时。
            char pos[20] = ""; scanf(" %[^)]", pos);

            scanf(" %*c");

            if (!complete) continue;

            int node = 1;
            for (int i = 0; i < strlen(pos); i++)
            {
                if (pos[i] == 'L') node = node * 2;
                if (pos[i] == 'R') node = node * 2 + 1;
            }
            if (node > maxNode) maxNode = node;
            if (tree[node]) complete = false;
            else tree[node] = data;
        }
        else
        {
            scanf(" %*c");
            if (complete)
            {
                if (maxNode == 0)
                {
                    printf("not complete\n");
                    init();
                    continue;
                }
                for (int i = 1; i <= maxNode; i++)
                    if (tree[i] && !tree[i >> 1]) complete = false;
                if (complete) {
                    printf("%d", tree[1]);
                    for (int i = 2; i <= maxNode; i++)
                    {
                        if (tree[i]) printf(" %d", tree[i]);
                    }
                    printf("\n");
                    init();
                }
                else {
                    printf("not complete\n");
                    init();
                }
            }
            else
            {
                printf("not complete\n");
                init();
            }
        }
    }
}
