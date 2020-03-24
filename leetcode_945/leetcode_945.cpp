// leetcode_945.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <unordered_set>
#include <bitset>
#include <unordered_map>
#include <algorithm>
#include <map>
using namespace std;
class Solution1 {
public:
	int minIncrementForUnique(vector<int>& A) {
		if (A.size() == 0)
			return 0;
		unordered_set<int> st;
		unordered_set<int>::iterator it;
		int ret = 0;
		for (auto i : A) {
			while (st.find(i) != st.end()) {
				++i;
				++ret;
			}
			st.emplace(i);
		}
		return ret;
	}
};

class Solution {
private:
	vector<int> vt;
	int maxV;
	int getNext(int i) {
		if (vt.size()) {
			vector<int>::iterator it = upper_bound(vt.begin(), vt.end(), i);
			if (it == vt.end())
				return maxV++;
			else {
				int ret = *it;
				vt.erase(it);
				return ret;
			}
		}
		else
			return maxV++;
	}
public:
	int minIncrementForUnique(vector<int>& A) {
		if (A.size() == 0)
			return 0;
		bitset< 40001> bt;
		map<int, int> mp;
		map<int, int>::iterator it;
		int ret = 0;
		maxV = 0;
		for (auto i : A) {
			if (!bt.test(i))
				bt.set(i);
			else {
				it = mp.find(i);
				if (it == mp.end())
					mp.emplace(make_pair(i, 1));
				else
					++it->second;
			}
			maxV = max(maxV, i);
		}
		++maxV;
		for (int i = 0; i < maxV; ++i)
			if (!bt.test(i))
				vt.emplace_back(i);
		for (auto i : mp) {
			while (i.second) {
				ret += getNext(i.first) - i.first;
				--i.second;
			}
		}
		return ret;
	}
};

int main()
{
	Solution s;
	vector<int> vt = { 3,2,1,2,1,7};
	s.minIncrementForUnique(vt);
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
