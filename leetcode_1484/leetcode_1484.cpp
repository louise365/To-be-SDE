// leetcode_1484.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <algorithm>
using namespace std;
class Solution1 {
public:
	int fib(int n) {
		if (n == 0)
			return 0;
		if (n == 1)
			return 1;
		double sqrt5 = sqrt(5);
		double s1 = (1.0 + sqrt5) / 2.0;
		double s2 = (1.0 - sqrt5) / 2.0;
		double ret = 1.0 / sqrt5 * (pow(s1, n * 1.0) - pow(s2, n * 1.0));
		return (unsigned long long)(ret) % 1000000007;
	}
};

class Solution {
public:
	int fib(int n) {
		if (n == 0)
			return 0;
		if (n == 1)
			return 1;
		int n1 = 0;
		int n2 = 1;
		for (int i = 2; i <= n; i++)
		{
			int t = n2;
			n2 = (n1 + n2) % 1000000007;
			n1 = t;
		}
		return n2;
	}
};

int main()
{
	Solution s;
	s.fib(100);
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
