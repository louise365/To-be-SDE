// leetcode_29.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <algorithm>
using namespace std;

class Solution {
public:
	int divide(int dividend, int divisor) {
		if (dividend == INT_MIN && divisor == -1)
			return INT_MAX;
		int sign1 = (dividend & 0x80000000) ? -1 : 1;
		int sign2 = (divisor & 0x80000000) ? -1 : 1;
		long long ret = 0;
		long long abs_dividend = dividend;
		long long abs_divisor = divisor;
		abs_dividend = abs(abs_dividend);
		abs_divisor = abs(abs_divisor);
		long long cnt = 1;
		while (abs_dividend >= abs_divisor)
		{
			long long abs_divisor_tmp = abs_divisor;
			cnt = 1;
			while (1)
			{
				if (abs_dividend > (abs_divisor_tmp << 1))
				{
					abs_divisor_tmp <<= 1;
					cnt <<= 1;
				}
				else
					break;
			}
			if (abs_divisor_tmp != abs_divisor)
			{
				abs_dividend -= abs_divisor_tmp;
				ret += cnt;
			}
			else
			{
				abs_dividend -= abs_divisor;
				++ret;
			}
		}
		if (sign1 != sign2)
			ret = -ret;
		return (int)ret;
	}
};

int main()
{
	Solution s;
	s.divide(2147483647, 1);
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
