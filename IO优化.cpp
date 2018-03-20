#pragma GCC optimize("unroll-loops")

#pragma comment(linker, "/STACK:16777216")

#include <bits/stdc++.h>
using namespace std;

template<typename T = int>
inline void read(T& val) {
	val = 0; T sign = 1; char ch;
	for (ch = getchar(); ch < '0' || ch > '9'; ch = getchar())
		if (ch == '-') sign = -1;
	for (; ch >= '0' && ch <= '9'; ch = getchar())
		val = val * 10 + ch - '0';
	val *= sign;
}

// 内存错误调试工具
// 断言机制
// DrMemory
