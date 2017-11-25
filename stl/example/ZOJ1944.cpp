/**
 * Tree Recovery
 *
 * substr()函数返回从pos开始连续n个字符组成的字符串。
 * 认真思考后想一想，其实《算法设计与分析》关于这题的内容没有一句废话。
**/
#include <iostream>
#include <string>
using namespace std;

// 给出先序遍历和中序遍历求后序遍历
void postOrder(string pre, string in, string &post)
{
    if (pre == "" && in == "") return;

    // 利用先序遍历定位根节点的位置
    int pos = in.find(pre[0]);

    // 后序遍历左子树
    postOrder(pre.substr(1, pos), in.substr(0, pos), post);

    // 后序遍历右子树
    postOrder(pre.substr(pos + 1), in.substr(pos + 1), post);

    // 后序遍历访问根节点
    post += pre[0];
}

// 给出中序遍历和后续遍历求先序遍历
void preOrder(string &pre, string in, string post)
{
    if (in == "" && post == "") return;

    // 利用后序遍历在中序遍历中定位根节点的位置
    int pos = in.find(post[post.size() - 1]);

    // 先序遍历访问根节点
    pre += post[post.size() - 1];

    // 先序遍历左子树
    preOrder(pre, in.substr(0, pos), post.substr(0, pos));

    // 先序遍历右子树
    preOrder(pre, in.substr(pos + 1),
            post.substr(pos, post.size() - pos - 1));
}

int main()
{
    string pre, in;
    while (cin >> pre >> in)
    {
        string post;
        postOrder(pre, in, post);
        cout << post << endl;
    }
}
