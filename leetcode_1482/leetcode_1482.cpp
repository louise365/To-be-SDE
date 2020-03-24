// leetcode_1482.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <stack>
using namespace std;
//dictionary tree
class Solution {
private:
	struct dtree {
		dtree* d[26];
		dtree()
		{
			memset(d, 0, sizeof(dtree*) * 26);
		}
	};
	dtree* root;
	//check whether the prefix has been covered
	inline bool checkEnd(dtree*& n)
	{
		bool flag = true;
		for (int i = 0; i < 26; ++i)
			if (n->d[i])
			{
				flag = false;
				break;
			}
		return flag;
	}
	void GetString(dtree* n, string s, vector<string>& vt)
	{
		bool flag = true;
		for (int i = 0; i < 26; ++i)
		{
			if (n->d[i])
			{
				flag = false;
				string t = s;
				t.push_back(i + 'a');
				GetString(n->d[i], t, vt);
			}
		}
		if (flag)
			vt.emplace_back(s);
	}
	void Rebuild(dtree*& n)
	{
		vector<string> vt;
		GetString(n, "", vt);
		for (auto v : vt)
			buildRoot(root, v, 0);
		memset(n->d, 0, sizeof(dtree*) * 26);
	}
	void buildRoot(dtree*& n, string& s, int idx)
	{
		if (idx >= s.size())
			return;
		n->d[s[idx] - 'a'] = new dtree();
		buildRoot(n->d[s[idx] - 'a'],s,idx+1);
	}
	void build(dtree*& n, string& s, int idx)
	{
		if (idx >= s.size())   return;
		if (idx == s.size() - 1 && n->d[s[idx] - 'a'])
		{
			//need to break the tree
			if (checkEnd(n->d[s[idx] - 'a']))    return;
			else {
				Rebuild(n->d[s[idx] - 'a']);
				//memset(n->d[s[idx] - 'a']->d, 0, sizeof(dtree*) * 26);
			}
			return;
		}
		if (idx < s.size())
		{
			if (!n->d[s[idx] - 'a'])
			{
				if (checkEnd(n))//build new prefix and counter++
					buildRoot(root, s, idx);
				else
				{
					n->d[s[idx] - 'a'] = new dtree();
					buildRoot(n->d[s[idx] - 'a'], s, idx + 1);
				}
			}
			else
				build(n->d[s[idx] - 'a'], s, idx + 1);
		}
	}
	void count(dtree*& n, string& s, int idx, int& cnt)
	{
		if (idx >= s.size())   return;
		if (idx == s.size() - 1 && n->d[s[idx] - 'a'])
		{
			++cnt;
			return;
		}
		if (idx < s.size() -1)
		{
			if (!n->d[s[idx] - 'a'])
				return;
			else
			{
				if (checkEnd(n->d[s[idx] - 'a']))
					count(root,s,idx+1,++cnt);
				else
					count(n->d[s[idx] - 'a'], s, idx + 1, cnt);
			}	
		}
	}
	bool compareString(string& s1, string& s2)
	{
		int size = min(s1.size(), s2.size());
		for (int i = 0; i <= size; ++i)
			if (s1[i] > s2[i])
				return true;
		return false;
	}
public:
	string longestWord(vector<string>& words) {
		if (words.size() < 2)
			return "";
		int ret = 0;
		string rets;
		root = new dtree();
		buildRoot(root, words[0],0);
		for (int i = 1; i < words.size(); ++i)
		{
			string& s = words[i];
			transform(s.begin(), s.end(), s.begin(), tolower);
			build(root, s, 0);
		}
		for (auto s : words)
		{
			int cnt = 0;
			count(root, s, 0, cnt);
			if (cnt < 2)
				continue;
			if (cnt > ret)
			{
				ret = cnt;
				rets = s;
			}
			else if (cnt == ret && rets > s)// compareString(rets, s))
				rets = s;
		}
		return rets;
	}
};
int main()
{
	Solution s;
	vector<string> vt;
	//vt = { "dog" ,"dogwalker","walker" };
	vt = { "dogwalker" ,"dogtalker","dog","walker","talker" };
	cout << s.longestWord(vt) << endl;
	
	
	//cout << s.longestWord(vt) << endl;
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
