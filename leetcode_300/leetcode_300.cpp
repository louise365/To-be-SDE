// leetcode_300.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <set>
#include <vector>
#include <map>
#include <algorithm>
#include <stack>
using namespace std;

class Solution1 {
private:
	vector<set<int>> vt;
public:
	int lengthOfLIS(vector<int>& nums) {
		if (nums.size() < 2)
			return nums.size();
		set<int> st;
		st.emplace(nums[0]);
		vt.emplace_back(st);
		for (int i = 1; i < nums.size(); i++)
		{
			vector<set<int>>::iterator it = vt.begin();
			while (it != vt.end() && nums[i] > (* it->begin()))
				++it;
			if (it == vt.end())
			{
				set<int> st;
				st.emplace(nums[i]);
				vt.emplace_back(st);
			}
			else
				it->emplace(nums[i]);
		}

		return vt.size();
	}
};
class Solution2 {
private:
	vector<int> vt;
public:
	int lengthOfLIS(vector<int>& nums) {
		if (nums.size() < 2)
			return nums.size();
		vt.emplace_back(nums[0]);
		for (int i = 1; i < nums.size(); i++)
		{
			vector<int>::reverse_iterator rit = vt.rbegin();
			while (rit != vt.rend() && nums[i]<= *rit)
				++rit;
			if (rit == vt.rbegin())
				vt.emplace_back(nums[i]);
			else
			{
				vector<int>::iterator it;
				it = rit == vt.rend() ? vt.begin() : rit.base();
				*it = min(nums[i], *it);
			}
		}
		return vt.size();
	}
};
//dp
class Solution3 {
private:
	vector<int> vt;
public:
	int lengthOfLIS(vector<int>& nums) {
		if (nums.size() < 2)
			return nums.size();
		for (auto i: nums)
		{
			vector<int>::iterator it;
			it = lower_bound(vt.begin(), vt.end(), i);
			if (it == vt.end())
				vt.emplace_back(i);
			else
				*it = min(i, *it);
		}
		return vt.size();
	}
};

//暴力
class Solution4 {
public:
	int lengthOfLIS(vector<int>& nums) {
		if (nums.size() < 2)
			return nums.size();
		vector<int> len(nums.size(), 1);
		int ret = 1;
		for (int i = 0; i < nums.size(); ++i)
		{
			for (int j = 0; j < i; ++j)
			{
				if (nums[i] < nums[j])
					continue;
				else if (nums[i] > nums[j])
				{
					len[i] = max(len[j]+1, len[i]);
					ret = max(len[i], ret);
				}
			}
		}
		return ret;
	}
};


int main()
{
	Solution s;
	vector<int> vt = { 10,9,2,5,3,7,101,18 };
	//vt = { 2,2 };
	cout << s.lengthOfLIS(vt) << endl;
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
