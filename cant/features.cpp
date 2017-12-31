// C++11等新标准引入了许多新语法形式，十二分酷炫

// Container 初始化

vector<int> p = {1, 2, 3, 4};
vector<int> p{1, 2, 3, 4};

// Range For
string s; cin >> s;
for (auto c : s)
{
	cout << c << " ";
}
