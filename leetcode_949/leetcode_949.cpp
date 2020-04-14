// leetcode_949.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

class Solution {
public:
	string largestTimeFromDigits(vector<int>& A) {
		int maxV = -1;
		for (int i = 0; i < A.size(); ++i) {
			for (int j = 0; j < A.size(); ++j) {
				if (i == j)
					continue;
				for (int m = 0; m < A.size(); ++m) {
					if (m == i || m == j)
						continue;
					for (int n = 0; n < A.size(); ++n) {
						if (n == i || n == j || n == m)
							continue;
						int timestamp = (A[i] * 10 + A[j]) * 60 + (A[m] * 10 + A[n]);
						if(timestamp <= 23*60 + 59)
							maxV = max(maxV, timestamp);
					}
				}
			}
		}
		string ret;
		if (maxV == -1)
			return ret;
		else {
			ret = to_string(maxV / 60 / 10);
			ret += to_string(maxV / 60 % 10);
			ret += ":";
			ret = to_string(maxV % 60 / 10);
			ret += to_string(maxV % 60 % 10);
		}
		return ret;
	}
};
int main()
{
	Solution s;
	vector<int> vt = { 1,2,3,4 };
	s.largestTimeFromDigits(vt);
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
