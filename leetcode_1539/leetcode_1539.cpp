// leetcode_1539.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
using namespace std;

class Solution1 {
public:
	vector<vector<int>> findContinuousSequence(int target) {
		vector<vector<int>> ret;
		int n = target / 2;
		for (int i = 1; i <= n; i++)
		{
			int remain = target;
			int j = i;
			vector<int> vt;
			while (1)
			{
				if (j > remain)
					break;
				vt.emplace_back(j);
				remain -= j;
				j++;
			}
			if (!remain)
				ret.emplace_back(vt);
		}
		return ret;
	}
};

class Solution2 {
public:
	vector<vector<int>> findContinuousSequence(int target) {
		vector<vector<int>> ret;
		int l = 1, sum = 3, r = 2;
		int n = (target + 1) / 2;
		while (r <= n)
		{
			if (sum < target)
				sum += ++r;
			else if (sum > target)
				sum -= l++;
			else
			{
				vector<int> vt;
				for (int i = l; i <= r; i++)
					vt.emplace_back(i);
				ret.emplace_back(vt);
				sum -= l++;
			}
		}
		return ret;
	}
};
class Solution {
public:
	vector<vector<int>> findContinuousSequence(int target) {
		vector<vector<int>> ret;
		int n = 3;
		while (1)
		{
			if ((n - 1) * n >= target * (n - 2))
				break;
			if (target % n == 0)
			{
				vector<int > vt;
				int a = target / n - ((n - 1) >> 1);
				for (int i = 0; i < n; i++)
					vt.emplace_back(a + i);
				if (ret.empty())
					ret.emplace_back(vt);
				else
					ret.insert(ret.begin(), vt);
			}
			n += 2;
		}
		return ret;
	}
};
int main()
{
	Solution s;
	s.findContinuousSequence(10);
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
