// leetcode_365.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>
using namespace std;

//z = ax+by,d=gcd(x,y)
//z%d == 0

class Solution1 {
private:
	struct pair_hash {
		inline size_t operator()(const pair<int, int>& p) const {
			return p.first * 10001 + p.second;
		}
	};
	unordered_set<pair<int, int>, pair_hash> st;
	int x, y, z;
	pair<int, int> getCombination(int a, int b, int i)
	{
		pair<int, int> p;
		//1, empty;2,fill;3,fill to another;4, no op
		//a loop, b = 1
		if (i == 1)
			p.first = 0, p.second = 0;
		if (i == 17)
			p.first = 0, p.second = 0;
		if (i == 2)
			p.first = x, p.second = 0;
		if (i == 18)
			p.first = x, p.second = 0;
		if (i == 3)
			p.first = (a + b) > y ? a + b - y : 0, p.second = 0;
		if (i == 19)
			p.first = a > y ? a - y : 0, p.second = min(y, a);
		if (i == 4)
			p.first = a, p.second = 0;
		if (i == 20)
			p.first = a, p.second = 0;
		//a loop, b = 2
		if (i == 5)
			p.first = 0, p.second = y;
		if (i == 21)
			p.first = 0, p.second = y;
		if (i == 6)
			p.first = x, p.second = y;
		if (i == 22)
			p.first = x, p.second = y;
		if (i == 7)
			p.first = a + b > y ? a + b - y : 0, p.second = y;
		if (i == 23)
			p.first = a, p.second = y;
		if (i == 8)
			p.first = a, p.second = y;
		if (i == 24)
			p.first = a, p.second = y;
		//a loop, b = 3
		if (i == 9)
			p.first = b > x ? x : b, p.second = b > x ? b - x : 0;
		if (i == 25)
			p.first = 0, p.second = a + b > x ? a + b - x : 0;
		if (i == 10)
			p.first = x, p.second = b;
		if (i == 26)
			p.first = x, p.second = a + b > x ? a + b - x : 0;
		if (i == 11)
		{
			int _a = a + b > y ? a + b - y : 0; int _b = min(y, a + b);
			p.first = min(x, _a + _b), p.second = _a + _b > x ? _a + _b - x : 0;
		}
		if (i == 27)
		{
			int _a = min(x, a + b); int _b = a + b > x ? a + b - x : 0;
			p.first = _a + _b > y ? _a + _b - y : 0, p.second = min(_a + _b, y);
		}
		if (i == 12)
			p.first = min(x, a + b), p.second = a + b > x ? a + b - x : 0;
		if (i == 28)
			p.first = min(x, a + b), p.second = a + b > x ? a + b - x : 0;
		//a loop, b = 4
		if (i == 13)
			p.first = 0, p.second = b;
		if (i == 29)
			p.first = 0, p.second = b;
		if (i == 14)
			p.first = x, p.second = b;
		if (i == 30)
			p.first = x, p.second = b;
		if (i == 15)
			p.first = a + b > y ? a + b - y : 0, p.second = min(y, a + b);
		if (i == 31)
			p.first = a + b > y ? a + b - y : 0, p.second = min(y, a + b);
		if (i == 16)
			p.first = a, p.second = b;
		if (i == 32)
			p.first = a, p.second = b;
		return p;
	}

	bool resolve(int a, int b, int z)
	{
		bool ret = false;
		unordered_set<pair<int, int>, pair_hash>::iterator it;
		it = st.find(make_pair(a, b));
		if (it == st.end())
		{
			if (a == z || b == z || a + b == z || abs(a - b) == z)
				return true;
			st.insert(make_pair(a, b));
			for (int i = 1; i <= 32; i++)
			{
				pair<int, int> p = getCombination(a, b, i);
				if (!ret && st.find(p) == st.end())
					ret |= resolve(p.first, p.second, z);
			}
			return ret;
		}
		else
			return false;
	}
public:
	bool canMeasureWater(int x, int y, int z) {
		this->x = x; this->y = y; this->z = z;
		return resolve(x, y, z);
	}
};

class Solution {
private:
	int gcd(int a, int b)
	{
		while (b)
		{
			int t = a % b;
			a = b;
			b = t;
		}
		return a;
	}
public:
	bool canMeasureWater(int x, int y, int z) {
		if (x == z || y == z || x + y == z)
			return true;
		if (x + y < z)
			return false;
		return z % gcd(x, y) == 0;
	}
};
int main()
{
	Solution s;
	s.canMeasureWater(100, 20, 123);
	s.canMeasureWater(104597, 104623, 123);
	std::cout << "Hello World!\n";
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
