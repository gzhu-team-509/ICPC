/** 
 * 高精度整数 - 完成高精度加减乘除
 *
 * d[MAXL] （d[0]表示当前位数，d[i]表示第i位上的数，每4位压成一个万进制数位）
 * BigNumber(string s)
 * string toString()
 * 
**/
// 参考资料：《算法与实现》P31

const int TEN[4] = {1, 10, 100, 1000};
const int MAXL = 1000;                  // 最大位数

struct BigInteger
{
    int d[MAXL];
}
