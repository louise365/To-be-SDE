// leetcode_1409.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
class Solution {
public:
	int waysToStep(int n) {
		const int mod = 1000000007;
		if (n == 1)
			return 1;
		if (n == 2)
			return 2;
		if (n == 3)
			return 4;
		//f(n) = f(n-1) + f(n-2) + f(n-3);
		//f(4) = f(3) + f(2) + f(1) = 4+2+1 = 7
		//f(5) = f(4) + f(3) + f(2) = 7 + 4 + 2= 13
		int n1 = 1, n2 = 2, n3 = 4;
		int ret = 0;
		for (int i = 4; i <= n; i++)
		{
			ret = 0;
			ret = (n1 + ret) % mod;
			ret = (n2 + ret) % mod;
			ret = (n3 + ret) % mod;
			n1 = n2 % mod;
			n2 = n3 % mod;
			n3 = ret % mod;
		}
		return ret;
	}
};

int main()
{
	Solution s;
	s.waysToStep(5);
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
