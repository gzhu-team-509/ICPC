> 建立CheatSheet的最终目的是不再需要使用它。

## 基本知识

### 计算

快速幂

### 数学

- **数列** 斐波那契数列
- **数论** 中位数 GCD LCM
- **组合数学** Catalan

### 图论

- **单源图最短路径** Dijkstra
- **最小生成树** Prim Kruskal

### 结构

- **基础结构** 高精度整数 二叉树
- **区间查询** 二叉索引树（Fenwick，树状数组） 线段树（ZWK线段树）
- **优先队列** 左偏树（快速合并）

### 搜索

二分搜索

深度优先搜索 广度优先搜索

## C++

### 函数

- **字符串处理** c-string `atoi() atol() atof()` string `to_string() stoi() stol() stoll() stod()`

### 常用容器类型

Stack, Vector, Map, Mutimap, List, Set, Queue, Priority_Queue, Deque

- 注意Priority_Queue大顶堆与sort()比较函数的区别。
满足Priority_Queue比较函数判定条件的，在合并中作为子树。
满足sort()比较函数判定条件的，在排序中靠前。

### 仿函数

greater<int>() [functional头文件]

### 接口

- **构造器** `Container(n)` `Container(n, elem)` `Container(c)`

- **元素操作** `empty()` `size()` `clear()` `swap()`
顺序访问容器`pop()` `push()` `top()` `front()` `back()` `pop_back()` `pop_front()` `push_back()` `push_front()`
随机访问容器`erase(pos)` `insert(pos, (n,) elem)`

- **随机访问迭代器** `begin()` `end()`

- **向量** `capacity()` `Vector[pos]`

- **链表** `remove() remove_if()` `reverse()` `sort()` `unique()`

- **映射** `make_pair()` `find()` `count()` `Map[Key]`

- **集合** `equal_range()` `find()` `count()`

## Java

### BigInteger

- **常量** ONE TEN ZERO
- **构造函数** `(String val)` `(String val, int radix)` `negate()`
- **四则运算** `add()` `subtract()` `divide()` `divideAndRemainder()` `remainder()` `mod()` `modPow(ex, m)` `pow()`
- **位运算** `and()` `andNot()` `not()` `or()` `xor()` `shiftLeft()` `shiftRight()`
- **比较** `equals()` `compareTo()` `max()` `min()`
- **其他** `abs()` `clearBit(int n)` `flipBit(int n)` `gcd()` `getLowestSetBit()` `isProbablePrime()` `nextProbablePrime()`
- **转换** `doubleValue()` `longValue()` `toString()`

**BigDecimal** 在BigInteger的基础上支持表示小数
