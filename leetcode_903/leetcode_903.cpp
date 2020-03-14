// leetcode_903.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
#include <vector>
using namespace std;
//n = 5, f(D) = 5/4 + 4/3+3/2+2/1 = 10, f(DD5) = 5 * f(D4), 4 * f(D3), 3 *f(D2)
//f(DI5) = 1*f(D4), 2 *f(D3),3 * f(D2)
class Solution {
public:
	int numPermsDISequence(string S) {
		int n = S.size();
		int ret = 0;
		vector<int> increase(n + 1, 0), decrease(n + 1, 0),counter(n+1,1);
		decrease[1] = n - 1;
		for (int i = 2; i <= n; i++)
			decrease[i] = decrease[i - 1] + i - 1;
		for (int i = n - 1; i >= 1; i--)
			increase[i] = n - i + increase[i+1];
		int low = 1, high = n;
		for (int i = 0; i < n; i++)
		{
			vector<int>* add;
			if (S[i] == 'D')
				add = &decrease;
			else
				add = &increase;
			counter[]
		}
		return ret;
	}
};
int main()
{
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
