// leetcode_994.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <unordered_set>
using namespace std;

class Solution {
private:
	struct node
	{
		int first;
		int second;
		node(int f, int s) :first(f), second(s) {}
	};
	bool isNeighbor(vector<vector<int>>& grid, int x, int y, unordered_set<int>& st)
	{
		int row = grid.size();
		int col = grid[0].size();
		bool ret = false;
		if (x > 0 && grid[y][x - 1] == 1)
		{
			st.emplace((x - 1) * 10 + y);
			ret = true;
		}
		if (x + 1 < col && grid[y][x + 1] == 1)
		{
			st.emplace((x + 1) * 10 + y);
			ret = true;
		}
		if (y > 0 && grid[y - 1][x] == 1)
		{
			st.emplace((x - 0) * 10 + y - 1);
			ret = true;
		}
		if (y + 1 < row && grid[y + 1][x] == 1)
		{
			st.emplace((x - 0) * 10 + y + 1);
			ret = true;
		}
		return ret;
	}
	void setRotten(vector<vector<int>>& grid, int x, int y, unordered_set<int>& st)
	{
		grid[y][x] = 2;
		isNeighbor(grid, x, y, st);
	}
public:
	int orangesRotting(vector<vector<int>>& grid) {
		if (grid.empty())
			return -1;
		unordered_set<int> mp;
		queue<int> st;
		int ret = 0;
		int row = grid.size();
		int col = grid[0].size();
		int count = 0;
		for (int i = 0; i < row; i++)
			for (int j = 0; j < col; j++)
			{
				if (grid[i][j] == 2 && isNeighbor(grid, j, i, mp))
					;
				if (grid[i][j] == 1)
					count++;
			}
		int times = 0;
		while (!mp.empty())
		{
			for (auto i : mp)
				if (grid[i % 10][i / 10] == 1)
					st.emplace(i);
			mp.clear();
			if (st.size())
				times++;
			while (!st.empty())
			{
				int x = st.front() / 10;
				int y = st.front() % 10;
				st.pop();
				setRotten(grid, x, y, mp);
				count--;
			}
		}

		return !count ? times : -1;
	}
};
int main()
{
	Solution s;
	vector<vector<int>> vt;
	vector<int> v;
	v = { 2,2 }; vt.emplace_back(v);
	v = { 1,1 }; vt.emplace_back(v);
	v = { 0,0 }; vt.emplace_back(v);
	v = { 2,0 }; vt.emplace_back(v);
	//vt = { 2,1,1 }; vt.emplace_back(v);
	//v = { 1,1,0 }; vt.emplace_back(v);
	//v = { 0,1,1 }; vt.emplace_back(v);
	cout << s.orangesRotting(vt) << endl;
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
