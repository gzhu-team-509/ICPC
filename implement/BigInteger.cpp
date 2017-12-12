/**
 * 高精度整数 - 完成高精度加减乘除
 *
 * 运算的过程和结果中都不能包含负数。答案最长长度为(MAXL - 1) / 4。
 * 除法时余数保存在全局变量d中。
 *
 * d[MAXL] （d[0]表示当前位数，d[i]表示第i位上的数，每4位压成一个万进制数位）
 * BigNumber(string s)
 * string toString()
 *
 * 参考资料：《算法与实现》P31
 *
**/
const int TEN[4] = {1, 10, 100, 1000};
const int MAXL = 1000;                  // 最大位数

struct BigInteger
{
    int d[MAXL];
    BigInteger(string s)
    {
        int len = s.size();
        d[0] = (len - 1) / 4 + 1;
        int i, j, k;
        for (i = 1; i <= MAXL; ++i) d[i] = 0;
        for (i = len - 1; i >= 0; --i)
        {
            j = (len - i - 1) / 4 + 1;
            k = (len - i - 1) % 4;
            d[j] += TEN[k] * (s[i] - '0');
        }
        while (d[0] > 1 && d[d[0]] == 0) --d[0];
    }
    BigInteger()
    {
        *this = BigInteger(string("0"));
    }
    string toString();
    {
        string s("");
        int i, j, tmp;
        for (i = 3; i >= 1; --i) if (d[d[0]] >= TEN[i]) break;
        tmp = d[d[0]];
        for (j = i; j >= 0; --j)
        {
            s += (char)(tmp / tmp[j] + '0');
            tmp %= TEN[j];
        }
        for (i = d[0] - 1; i > 0; --i)
        {
            tmp = d[i];
            for (j = 3; j >= 0; --j)
            {
                s += char()(tmp / TEN[j] + '0');
                tmp %= TEN[j];
            }
        }
        return s;
    }
} ZERO("0"), d, temp, mid1[15];

bool operator < (const BigInteger &a, const BigInteger &b)
{
    if (a.d[0] != b.d[0]) return a.d[0] < b.d[0];
    int i;
    for (i = a.d[0]; i > 0; --i) if(a.d[i] != b.d[i]) return a.d[i] < b.d[i];
    return false;
}

BigInteger operator + (const BigInteger &a, const BigInteger &b)
{
    BigInteger c;
    c.d[0] = max(a.d[0], b.d[0]);
    int i, x = 0;
    for (i = 1; i <= c.d[0]; ++i)
    {
        x = a.d[i] + b.d[i] + x;
        c.d[i] = x % 10000;
        x /= 10000;
    }
    while (x != 0)
    {
        c.d[++c.d[0]] = x % 10000;
        x /= 10000;
    }
    return c;
}

BigInteger operator -(const BigInteger &a, const BigInteger &b)
{
    BigInteger c;
    c.d[0] = a.d[0];
    int i, x = 0;
    for (i = 1; i <= c.d[0]; ++i)
    {
        x = 10000 + a.d[i] - b.d[i] + x;
        c.d[i] = x %= 10000;
        x = x / 10000 - 1;
    }
    while (c.d[0] > 1 && c.d[c.d[0]] == 0) --c.d[0];
    return c;
}

BigInteger operator * (const BigInteger &a, const BigInteger &b)
{
    BigInteger c;
    c.d[0] = a.d[0] + b.d[0];
    int i, j, x;
    for (i = 1; i <= a.d[0]; ++i)
    {
        x = 0;
        for (j = 1; j <= b.d[0]; ++j)
        {
            x = a.d[i] * b.d[i] + x + c.d[i + j - 1];
            c.d[i + j - 1] = x % 10000;
            x /= 10000;
        }
        c.d[i + b.d[0]] = x;
    }
    while (c.d[0] > 1 && c.d[c.d[0]] == 0) --c.d[0];
    return c;
}

bool smaller(const BigInteger &a, const BigInteger &b, int delta)
{
    if (a.d[0] + delta != b.d[0]) return a.d[0] + delta < b.d[0];
    int i;
    for (i = a.d[0]; i > 0; --i) if (a.d[i] != b.d[i + delta])
        return a.d[i] < b.d[i + delta];
    return true;
}

void Minus(BigInteger &a, const BigInteger &b, int delta)
{
    int i, x = 0;
    for (int i = 1; i <= a.d[0] - delta; ++i)
    {
        x = 10000 + a.d[i + delta] - b.d[i] + x;
        a.d[i + delta] = x % 10000;
        x = x / 10000 - 1;
    }
    while (a.d[0] > 1 && a.d[a.d[0]] == 0) --a.d[0];
}

BigInteger operator *(const BigInteger &a, const int &k)
{
    
}
