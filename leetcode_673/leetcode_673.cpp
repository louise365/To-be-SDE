// leetcode_673.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <set>

using namespace std;

class Solution1 {
private:
	vector<multiset<int>> vt;
public:
	int findNumberOfLIS(vector<int>& nums) {
		if (nums.size() < 2)
			return nums.size();
		multiset<int> st;
		st.emplace(nums[0]);
		vt.emplace_back(st);
		//int count = 0;
		for (int i = 1; i < nums.size(); i++)
		{
			vector<multiset<int>>::reverse_iterator rit = vt.rbegin();
			if (nums[i] > * (rit->rbegin()))
			{
				multiset<int> st;
				st.emplace(nums[i]);
				vt.emplace_back(st);
			}
			else// if (nums[i] < *(rit->rbegin()))
			{
				//check previous entry of vt
				if (nums[i] < *(rit->begin()))
				{
					//if no previous,insert to current
					while (rit != vt.rend() && nums[i] < *(rit->begin()))
						rit++;
					vector<multiset<int>>::iterator it;
					if (rit == vt.rend())
						it = vt.begin();
					else
						it = rit.base();
					//if (it->find(nums[i]) == it->end())
					it->emplace(nums[i]);
				}
				else// if(nums[i] >= *(rit->begin()))
				{
					//no exists, insert new one in current index of vt
					//if (rit->find(nums[i]) == rit->end())
					rit->emplace(nums[i]);
				}
			}
		}

		return vt.size();
	}
};
class Solution2 {
private:
	vector<int> vt;
public:
	int findNumberOfLIS(vector<int>& nums) {
		if (nums.size() < 2)
			return nums.size();
		vt.emplace_back(nums[0]);
		int ret = 1;
		int maxLen = 1;
		for (int i = 1; i < nums.size(); i++)
		{
			vector<int>::iterator it;
			it = lower_bound(vt.begin(), vt.end(), nums[i]);
			if (it == vt.end())
				vt.emplace_back(nums[i]);
			else
			{
				*it = min(nums[i], *it);

			}
		}
		return ret;
	}
};

class Solution3 {
public:
	int findNumberOfLIS(vector<int>& nums) {
		if (nums.size() < 2)
			return nums.size();
		vector<int> len(nums.size(), 1);
		vector<int> count(nums.size(), 1);
		int ret = 0;
		int maxLen = 1;
		for (int i = 0; i < nums.size(); ++i)
		{
			for (int j = 0; j < i; ++j)
			{
				if (nums[i] <= nums[j])
					continue;
				else
				{
					if (len[j] + 1 > len[i])
					{
						len[i] = len[j] + 1;
						count[i] = count[j];
					}
					else if (len[j] + 1 == len[i])
						count[i] += count[j];
				}
			}
			if (maxLen < len[i])
			{
				maxLen = len[i];
				ret = count[i];
			}
			else if (maxLen == len[i])
				ret += count[i];
		}
		return ret;
	}
};
class Solution {
public:
	int findNumberOfLIS(vector<int>& nums) {
		if (nums.size() < 2)
			return nums.size();
		vector<int> len(nums.size(), 1);
		vector<int> count(nums.size(), 1);
		int ret = 0;
		int maxLen = 1;
		for (int i = 0; i < nums.size(); ++i)
		{
			for (int j = 0; j < i; ++j)
			{
				if (nums[i] <= nums[j])
					continue;
				else
				{
					if (len[j] + 1 > len[i])
					{
						len[i] = len[j] + 1;
						count[i] = count[j];
					}
					else if (len[j] + 1 == len[i])
						count[i] += count[j];
				}
			}
			if (maxLen < len[i])
			{
				maxLen = len[i];
				ret = count[i];
			}
			else if (maxLen == len[i])
				ret += count[i];
		}
		return ret;
	}
};
int main()
{
	Solution s;
	vector<int> vt = { 1,2,4,3,5,4,7,2 };
	//vt = { 2, 2, 2 };
	s.findNumberOfLIS(vt);
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
