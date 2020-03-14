// leetcode_820.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;

class Solution {
private:
	struct TreeNode
	{
		TreeNode* map[27];
		TreeNode* next;
		bool empty;
		bool printed;
		TreeNode()
		{
			memset(map, 0, sizeof(TreeNode*) * 26);
			next = 0;
			empty = true;
			printed = false;
		}
	};
	void buildTree(string word, TreeNode* head)
	{
		if (word.empty())
			return;
		string::reverse_iterator rit = word.rbegin();
		while (rit != word.rend())
		{
			if (head->map[*rit - 'a'])
			{
				head = head->map[*rit - 'a'];
				rit++;
			}
			else
			{
				head->map[*rit - 'a'] = new TreeNode();
				head->empty = false;
			}
		}
	}
	bool validNode(string word, int& len, TreeNode* head)
	{
		if (word.empty())
			return false;
		bool ret = false;
		string::reverse_iterator rit = word.rbegin();
		len = 0;
		while (rit != word.rend())
		{
			if (head->map[*rit - 'a'])
			{
				head = head->map[*rit - 'a'];
				rit++;
				len++;
			}
		}
		ret = head->empty & !head->printed;
		if (ret)
			head->printed = true;
		return ret;
	}
	TreeNode* head;
public:
	int minimumLengthEncoding(vector<string>& words) {

		if (words.empty())
			return 0;
		int ret = 0;
		head = new TreeNode();
		for (auto w : words)
			buildTree(w, head);
		for (auto w : words)
		{
			int len = 0;
			if (validNode(w, len, head))
				ret += len + 1;
		}
		return ret;
	}
};
int main()
{
	Solution s;
	vector<string> vt;
	vt.emplace_back("time");
	vt.emplace_back("me");
	vt.emplace_back("bell");
	s.minimumLengthEncoding(vt);
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
