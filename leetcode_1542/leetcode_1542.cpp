// leetcode_1542.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <set>
using namespace std;

//monotonic queue
class Solution1 {
private:
	struct node
	{
		int val;
		int idx;
		node(int v, int i) :val(v), idx(i) {};
	};
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		vector<int> ret;
		deque<node> st;
		for (int i = 0; i < nums.size(); i++)
		{
			while (st.size() && st.front().idx <= i - k)
				st.pop_front();
			while (st.size() && st.back().val < nums[i])
				st.pop_back();
			if ((!st.empty() && nums[i] <= st.back().val) ||
				st.empty())
				st.emplace_back(node(nums[i], i));
			if (i >= k - 1)
				ret.emplace_back(st.front().val);
		}
		return ret;
	}
};
//multiset -> erase will delte all elements that have same value
class Solution {
public:
	vector<int> maxSlidingWindow(vector<int>& nums, int k) {
		multiset<int> st;
		vector<int> ret;
		for (int i = 0; i < nums.size(); i++)
		{
			st.insert(nums[i]);
			if (i >= k - 1)
			{
				ret.emplace_back(*(st.rbegin()));
				st.erase(st.find(nums[i - k + 1]));
			}
		}
		return ret;
	}
};
int main()
{
	Solution s;
	vector<int> vt = { -7,-8,7,5,7,1,6,0 };
	s.maxSlidingWindow(vt, 4);
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
