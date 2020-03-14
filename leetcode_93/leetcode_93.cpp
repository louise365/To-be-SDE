// leetcode_93.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

/*
class Solution {
private:
	unordered_map<int, int> mp;
	vector<string> vt;
	inline int hash(int &s, int &e, int &cnt)
	{
		return s * 120 + e * 12 + cnt;
	}
	inline int check(string &s, int &st,int &ed,int &cnt)
	{
		if (ed - st + 1 == 3 && atoi(s.substr(st, 3).c_str()) > 255)
			return -2;
		unordered_map<int, int>::iterator it = mp.find(hash(st, ed, cnt));
		if (it != mp.end())
			return it->second;
		else
			return -1;
	}
	void resolve(string &s, int cnt)
	{
		if(cnt == 4 && )
	}
public:
	vector<string> restoreIpAddresses(string s) {
		vector<string> ret;
		if (s.empty())
			return ret;
		for (int i = 0; i < s.size(); ++i)
		{
			int idx = i;
		}
	}
};
*/
class Solution {
private:
	bool validate(string& s)
	{
		if (s.size() > 3 || s.size() < 1)
			return false;
		int si = atoi(s.c_str());
		if (si > 255 || si < 0)
			return false;
		if (s.size() >1 && s[0] == '0')
			return false;
		
		return true;
	}
public:
	vector<string> restoreIpAddresses(string s) {
		vector<string> ret;
		if (s.empty())
			return ret;
		int size = s.size();
		for (int i = 0; i < 3 && i < size; ++i)
		{
			if (size - i - 1 > 9)	continue;
			string si = s.substr(0, i + 1);
			if (!validate(si))	continue;
			for (int j = i + 1; j < 6 && j < size && j - i <= 3; ++j)
			{
				if (size - j - 1 > 6)	continue;
				string sj = s.substr(i + 1, j - i);
				if (!validate(sj))	continue;
				for (int m = j + 1; m < 9 && m < size && m - j <= 3; ++m)
				{
					if (size - m - 1 > 3)	continue;
					string sm = s.substr(j + 1, m - j);
					string sn = s.substr(m + 1, size - m);
					if (!validate(sm) || !validate(sn))	continue;
					ret.emplace_back(si + "." + sj + "." + sm + "." + sn);
				}
			}
		}
		return ret;
	}
};

int main()
{
	Solution s;
	s.restoreIpAddresses("010010");
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
