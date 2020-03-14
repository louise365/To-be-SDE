// leetcode_322.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
using namespace std;

class Solution {
private:
	int minVal;
	bool change(vector<int>& c, int idx, int count, int& nums)
	{
		if (idx < 0)
			return false;
		if (c[idx] > count)
		{
			idx = upper_bound(c.begin(), c.end(), count) - c.begin() - 1;
			return change(c, idx, count, nums);
		}
		else
		{
			if (count % c[idx] == 0)
			{
				//minVal = min(minVal, nums + count / c[idx]);
				minVal = nums + count / c[idx];
				//nums = minVal;//key point
				return true;
			}
			bool flag = false;
			for (int i = count / c[idx]; i >= 0; --i)
			{
				int t = nums + i;
				if (t >= minVal)
					break;
				flag |= change(c, idx - 1, count - c[idx] * i, t);
			}
			//if (flag)
				//nums = minVal;

			return flag;
		}
	}
public:
	int coinChange(vector<int>& coins, int amount) {
		if (coins.empty() || amount < 0)
			return -1;
		if (amount == 0)
			return 0;
		sort(coins.begin(), coins.end());
		while (!coins.empty() && *coins.begin() <= 0)
			coins.erase(coins.begin());
		if (coins.empty() || coins[0] > amount)
			return -1;
		int nums = 0;
		minVal = INT_MAX;
		if (change(coins, coins.size() - 1, amount, nums))
			return minVal;
		else
			return -1;
	}
};

class Solution1 {
public:
	int coinChange(vector<int>& coins, int amount) {
		const int MAXV = amount + 1;
		vector<int> dp(MAXV, MAXV);
		dp[0] = 0;

		for (int i = 0; i <= amount; ++i)
		{
			for (int j = 0; j < coins.size(); ++j)
			{
				if (i < coins[j])
					continue;
				dp[i] = min(dp[i], dp[i - coins[j]] + 1);
			}
			//dp[i] = dp[i] == MAXV ? 0 : dp[i];
		}
		return dp[amount] == MAXV ? -1 : dp[amount];
	}
};
int main()
{
	Solution s;
	vector<int> vt;
	vt = { 186,419,83,408 };
	cout << s.coinChange(vt, 6249) << endl;
	vt = { 3 };
	cout << s.coinChange(vt, 2) << endl;
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
