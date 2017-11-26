/**
 * 棋盘覆盖问题
 *
 * 采用分治策略来棋盘覆盖问题是最优时间复杂度的解
 * 《算法设计与分析》 P68
**/
#include <cstring>
#include <cmath>
#include <iostream>
using namespace std;

int board[1025][1025];

int tile; // L形骨牌的编号

void init()
{
    memset(board, 0, sizeof(board));
    tile = 1;
}

// tr, tc 棋盘左上角的坐标
// dr, dc 特殊棋子的位置
// size 棋盘的行数或者列数
void make(int tr, int tc, int dr, int dc, int size)
{
    if (size == 1) return;

    int t = tile++;   // 特殊骨牌的编号
    int s = size / 2; // 子棋盘的大小

    // 处理左上角棋盘
    if (dr < tr + s && dc < tc + s) {
        make(tr, tc, dr, dc, s);
    }
    else {
        int dr = tr + s - 1, dc = tc + s - 1;
        board[dr][dc] = t;
        make(tr, tc, dr, dc, s);
    }

    // 处理右上角棋盘
    if (dr < tr + s && dc >= tc + s) {
        make(tr, tc + s, dr, dc, s);
    }
    else {
        int dr = tr + s - 1, dc = tc + s;
        board[dr][dc] = t;
        make(tr, tc + s, dr, dc, s);
    }

    // 处理左下角棋盘
    if (dr >= tr + s && dc < tc + s) {
        make(tr + s, tc, dr, dc, s);
    }
    else {
        int dr = tr + s, dc = tc + s - 1;
        board[dr][dc] = t;
        make(tr + s, tc, dr, dc, s);
    }

    // 处理右下角棋盘
    if (dr >= tr + s && dc >= tc + s) {
        make(tr + s, tc + s, dr, dc, s);
    }
    else {
        int dr = tr + s, dc = tc + s;
        board[dr][dc] = t;
        make(tr + s, tc + s, dr, dc, s);
    }
}

int main()
{
    int k;
    while (cin >> k)
    {
        int x, y; cin >> x >> y;
        init();

        int size = pow(2, k);
        make(0, 0, x, y, size);

        for (int i = 0; i < size; i++) {
            for (int j = 0; j < size; j++) {
                if (j) cout << '\t';
                cout << board[i][j];
            }
            cout << endl;
        }
    }
}
