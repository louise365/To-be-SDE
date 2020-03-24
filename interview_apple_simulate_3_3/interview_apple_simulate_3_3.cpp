// interview_apple_simulate_3_3.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <bitset>
using namespace std;
class Solution {
public:
	int firstMissingPositive(vector<int>& nums) {
		bool flag = false;
		for (auto i : nums)
			if (i == 1)
				flag = true;
		if (!flag)
			return 1;
		if (nums.size() == 1)
			return 2;
		nums.emplace_back(-1);
		for (auto& i : nums)
			if (i <= 0 || i > nums.size())
				i = -1;
		for (auto &i : nums) {
			int t = i;
			if (i > 0)
				i = -1;
			while (t > 0 && nums[t] != 0) {
				int tt = t;
				t = nums[t];
				nums[tt] = 0;
			}
		}
		int ret = 0;
		for (int i = 1; i < nums.size(); ++i) {
			if (nums[i] < 0)
			{
				ret = i;
				break;
			}
		}
		return ret?ret:nums.size();
	}
};
int main()
{
	Solution s;
	vector<int> vt = { 1,2,0 };
	cout << s.firstMissingPositive(vt) << endl;
	vt = { 3,4,-1,1 };
	cout << s.firstMissingPositive(vt) << endl;
	vt = {7,8,9,11,12};
	cout << s.firstMissingPositive(vt) << endl;
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
