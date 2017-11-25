/**
 * Trees on the Level
 *
 * 节点存在而其父节点不存在的二叉树是不完整的（根节点除外）
**/
#include <cstring>
#include <cstdio>
using namespace std;

bool complete;
int tree[260], maxNode;

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
        if (scanf("%d", &data) == 1)
        {
            scanf("%*c");

//!         char pos[10]; scanf("%[^)]", pos);
// 使用局部cstring要注意初始化，尤其是想通过scanf()对它进行初始化时。
            char pos[10] = "\0"; scanf("%[^)]", pos);

            scanf("%*c");

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
            scanf("%*c");
            if (complete)
            {
                for (int i = 2; i <= maxNode; i++)
                    if (tree[i] && !tree[i >> 1]) complete = false;
                if (complete) {
                    printf("%d", tree[1]);
                    for (int i = 1; i <= maxNode; i++)
                    {
                        if (tree[i]) printf(" %d", tree[i]);
                    }
                    printf("\n");
                }
                else {
                    printf("not complete\n");
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
