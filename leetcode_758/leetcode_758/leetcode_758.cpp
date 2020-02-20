// leetcode_758.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;

struct node
{
	string::size_type s, e;
	node(string::size_type a, string::size_type b) :s(a), e(b) {}
	friend bool operator <(node a, node b)
	{
		if (a.s == b.s)
			return a.e < b.e;
		else
			return a.s < b.s;
	}
};

class Solution1 {
public:
	static const int len = 502;
	string boldWords(vector<string>& words, string S) {
		bool mark[len] = { false };
		for (auto w : words)
		{
			string t = S;
			string::size_type pos;
			int idx = 0;
			while ((pos = t.find(w)) != string::npos)
			{
				memset(mark + pos + idx + 1, true, w.size());
				t = t.substr(pos + 1);
				idx += pos + 1;
			}
		}
		string out;
		for (int i = 0; i < len; i++)
		{
			if ((i - 1) >= 0 && (i - 1) < S.size())
				out += S[i - 1];
			if (i < len - 1)
			{
				if (mark[i] == true && mark[i + 1] == false)
					out += "</b>";
				if (mark[i] == false && mark[i + 1] == true)
					out += "<b>";
			}
		}
		return out;
	}
};

struct Trie
{
	string::size_type len;
	//vector<Trie*> child;
	Trie *child[26];
	Trie() {
		//child = vector<Trie*>(26); //VS2015 does not support Trie *t = t->child[i]; when child is vector
		reset();
	}
	void reset()
	{
		memset(child, 0, 26 * sizeof(Trie *));
		len = 0;
	}
	Trie(int n)
	{
		reset();
		len = n;
	}
};

class Solution {
public:
	string boldWords(vector<string>& words, string S) {
		Trie root(0);
		root.reset();
		for (auto w : words)
			add(&root, w);
		string out;
		for (auto i = 0; i < S.size(); )
		{
			auto idx = i;
			auto len = find(&root, S, idx);
			if (len == 0)
			{
				out += S[i++];
				continue;
			}
			auto len2 = len;
			while (len != 0 && idx + len < S.size())
			{
				idx += len;
				len = find(&root, S, idx);
				len2 += len;
			}
			out = out + "<b>" + S.substr(i, len2) + "</b>";
			i += len2;
		}
		return out;
	}
	void add(Trie *root, string word)
	{
		for (auto i = 0; i < word.size(); i++)
		{
			if (root->child[word[i] - 'a'] == NULL)
			{
				root->child[word[i] - 'a'] = new Trie();
				root->child[word[i] - 'a']->reset();
				root->child[word[i] - 'a']->len = (i == word.size() - 1)?word.size():0;
			}
			root = root->child[word[i] - 'a'];
		}
	}
	string::size_type find(Trie *root, string s, int n)
	{
		string::size_type len = 0;
		//for (string::size_type i = n; i < s.size(); i++)
		{
			Trie *t = root;
			auto idx = n;
			while (idx < s.size() && t->child[s[idx] - 'a'])
			{
				t = t->child[s[idx++] - 'a'];
			}
			len = max(len, t->len);
		}
		return len;
	}
};

int main()
{
	Solution s;
	vector<string> vt;
	//["ccb", "b", "d", "cba", "dc"]
	//"eeaadadadc"
	string S = "aabcd";
	vt = { "ab", "bc" };
	S = "eeaadadadc";
	vt = { "ccb", "b", "d", "cba", "dc" };
	//["b", "dee", "a", "ee", "c"]
	//"cebcecceab"
	vt = { "b", "dee", "a", "ee", "c" };
	S = "cebcecceab";
	cout << s.boldWords(vt, S) << endl;
	system("pause");
	return 0;
}

