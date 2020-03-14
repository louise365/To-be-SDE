// leetcode_17.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
private:
	struct node
	{
		int idx;
		int cnt;
		int mod;
		char o[4];
		node(int n)
		{
			idx = 0;
			if (n == 2) o[0] = 'a', o[1] = 'b', o[2] = 'c', o[3] = '\0', cnt = 3;
			if (n == 3) o[0] = 'd', o[1] = 'e', o[2] = 'f', o[3] = '\0', cnt = 3;
			if (n == 4) o[0] = 'g', o[1] = 'h', o[2] = 'i', o[3] = '\0', cnt = 3;
			if (n == 5) o[0] = 'j', o[1] = 'k', o[2] = 'l', o[3] = '\0', cnt = 3;
			if (n == 6) o[0] = 'm', o[1] = 'n', o[2] = 'o', o[3] = '\0', cnt = 3;
			if (n == 7) o[0] = 'p', o[1] = 'q', o[2] = 'r', o[3] = 's', cnt = 4;
			if (n == 8) o[0] = 't', o[1] = 'u', o[2] = 'v', o[3] = '\0', cnt = 3;
			if (n == 9) o[0] = 'w', o[1] = 'x', o[2] = 'y', o[3] = 'z', cnt = 4;
			mod = 1;
		}
		char get(int &t)
		{
			char ret = o[t/mod];
			t %= mod;
			return ret;
		}
	};
public:
	vector<string> letterCombinations(string digits) {
		vector<string> ret;
		int size = digits.size();
        if(!size)
            return ret;
		vector<node*> vt;
		int count = 1;
		for (int i = 0; i < size; ++i)
		{
			vt.emplace_back(new node(digits[i] - '0'));
			count *= vt[i]->cnt;
		}
		int mod = vt[vt.size()-1]->cnt;
		for (int i = vt.size()-2; i >=0;--i)
		{
			vt[i]->mod = mod;
			mod = vt[i]->mod * vt[i]->cnt;
		}
		int cnt = 0;
		while (cnt<count)
		{
			string t;
			int c = cnt;
			for (int i = 0; i < vt.size(); ++i)
				t += vt[i]->get(c);
			ret.emplace_back(t);
			cnt++;
		}
		return ret;
	}
};
int main()
{
	Solution s;
	s.letterCombinations("23");
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
