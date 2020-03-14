// leetcode_16.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution {
public:
	int threeSumClosest(vector<int>& nums, int target) {
		int size = nums.size();
		int ret = 0;
		bool found = false;
		int currentDiff = INT_MAX;
		sort(nums.begin(), nums.end());//O(nlogn)
		for (int i = 0; i < nums.size() && !found; ++i)//O(n^2)
		{
			int t = target - nums[i];
			int s = 0, e = size - 1;
			while (s != e && s < size && e >= 0 && !found)
			{
				if (s == i) ++s;
				if (e == i) --e;
				if (s == e)
					break;
				if (nums[s] + nums[e] == t)
				{
					found = true;
					ret = target;
				}
				else
				{
					if (currentDiff > abs(nums[s] + nums[e] + nums[i] - target))
					{
						currentDiff = abs(nums[s] + nums[e] + nums[i] - target);
						ret = nums[s] + nums[e] + nums[i];
					}
					if (nums[s] + nums[e] > t)	--e;
					else if (nums[s] + nums[e] < t) ++s;
				}
			}
		}
		return ret;
	}
};
int main()
{
	vector<int> vt = { 0,2,1,-3 };
	Solution s;
	cout << s.threeSumClosest(vt, 1) << endl;
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
