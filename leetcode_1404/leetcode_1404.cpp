// leetcode_1404.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <algorithm>
#include <string>
using namespace std;
class Solution {
public:
	int reverseBits(int num) {
		int dp1[32] = { 0 };
		int dp2[32] = { 0 };
		int count = 0;
		int n = num;
		while (count < 32)
		{
			if (count == 0)
				dp1[count] = n % 2;
			else
				dp1[count] = n % 2 ? dp1[count - 1] + 1 : 0;
			count++;
			n >>= 1;
		}
		n = num;
		int idx = 31;
		while (idx >= 0)
		{
			if (idx == count)
				dp2[idx] = (n & (1 << idx)) >> idx;
			else
				dp2[idx] = ((n & (1 << idx)) >> idx) ? dp2[idx + 1] + 1 : 0;
			idx--;
		}

		int ret = 1;
		for (int i = 0; i < 32; i++)
		{
			if (i == 0)
				ret = max(ret, dp2[i + 1] + 1);
			else if (i == 31)
				ret = max(ret, dp1[i - 1] + 1);
			else
			{
				if (num & (1 << i))
					ret = max(max(dp1[i], dp2[i]), ret);
				else
					ret = max(dp1[i - 1] + dp2[i + 1] + 1, ret);
			}
		}
		return ret;
	}
};
int main()
{
	Solution s;
	s.reverseBits(2147483646);
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
