// leetcode_6.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
	string convert(string s, int numRows) {
		numRows = min(numRows, int(s.size()));
		if (numRows == 1)
			return s;
		int n = numRows;
		int m = s.size();
		int cols = 0;
		while (m)
		{
			if (m - n >= 0)
			{
				m -= n;
				cols++;
			}
			if (n > 2)
			{
				if (m - (n - 2) >= 0)
				{
					m -= n - 2;
					cols += n - 2;
				}
				if (m < (n - 2))
				{
					cols += m;
					m = 0;
				}
			}
			else
			{
				if (m < n)
				{
					cols += m;
					m = 0;
				}
			}
		}
		string ret;
		ret.resize(cols * n,' ');
		m = s.size();
		int i = 0, j = 0;//i = col,j = row
		int k = 0;
		while (k<m)
		{
			while (k < m && j < n)
			{
				ret[i + j * cols] = s[k++];
				j++;
			}
			j = n - 2;
			i++;
			while (k < m && j >= 1)
			{
				ret[i + j * cols] = s[k++];
				i++;
				j--;
			}
			j = 0;
		}
		int idx = 0;
		string out;
		for (i = 0; i < ret.size(); i++)
			if (ret[i] != ' ')
				out+=ret[i];
		return out;
	}
};
int main()
{
	Solution s;
	cout << s.convert("ABC", 2) << endl;
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
