// leetcode_307.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//comment: to use segment tree is 4 times of the data is needed; fenw tree

#include <iostream>
#include <vector>
using namespace std;

class NumArray1 {
private:
	struct TreeNode
	{
		int left, right;
		int value;
		TreeNode() {};
		TreeNode(int l, int r) :left(l), right(r)
		{
			value = 0;
		}
	};
	vector<TreeNode> seg;
	int size;
	int query(int idx, int l, int r)
	{
		int& left = seg[idx].left;
		int& right = seg[idx].right;
		if (l == left && r == right)
			return seg[idx].value;
		int mid = left + ((right - left) >> 1);
		int ret = 0;
		if (l <= mid && r <= mid)
			ret += query(idx << 1, l, r);
		if (l <= mid && r > mid)
		{
			ret += query(idx << 1, l, mid);
			ret += query((idx << 1) + 1, mid + 1, r);
		}
		if (l > mid)
			ret += query((idx << 1) + 1, l, r);
		return ret;
	}
	int updateTree(int idx, int i, int v)
	{
		if (seg[idx].left == seg[idx].right && seg[idx].right == i)
		{
			int t = v - seg[idx].value;
			seg[idx].value = v;
			return t;
		}
		int& left = seg[idx].left;
		int& right = seg[idx].right;
		int mid = left + ((right - left) >> 1);
		int t;
		if (i <= mid)
			t = updateTree(idx << 1, i, v);
		else
			t = updateTree((idx << 1) + 1, i, v);
		seg[idx].value += t;
		return t;
	}
	void build(int idx, int l, int r, vector<int>& nums)
	{
		seg[idx].left = l;
		seg[idx].right = r;
		if (l == r)
		{
			seg[idx].value = nums[l];
			return;
		}
		int mid = l + ((r - l) >> 1);
		build(idx << 1, l, mid, nums);
		build((idx << 1) + 1, mid + 1, r, nums);
		seg[idx].value = seg[idx << 1].value + seg[(idx << 1) + 1].value;
	}
	void refine(int& idx)
	{
		if (idx < 0)
			idx = 0;
		if (idx > size - 1)
			idx = size - 1;
	}
public:
	NumArray1(vector<int>& nums) {
		if (nums.empty())
			return;
		size = nums.size();
		seg.resize(size_t(nums.size() << 2));
		build(1, 0, nums.size() - 1, nums);
	}

	void update(int i, int val) {
		if (i<0 || i>size - 1)
			return;
		updateTree(1, i, val);
	}

	int sumRange(int i, int j) {
		refine(i), refine(j);
		return query(1, i, j);
	}
};

class NumArray {
private:
	vector<int> *numsRef;
	vector<int> ct;
	int size;
	inline int lowbit(int x)
	{
		return x & -x;
	}
	void updateTree(int idx, int val)
	{
		int newVal = val - (*numsRef)[idx];
		(*numsRef)[idx] = val;
		++idx;
		while (idx <= size)
		{
			ct[idx] += newVal;
			idx += lowbit(idx);
		}
	}
	int query(int idx)
	{
		++idx;
		int ret = 0;
		while (idx)
		{
			ret += ct[idx];
			idx -= lowbit(idx);
		}
		return ret;
	}
public:
	NumArray(vector<int>& nums) {
		if (nums.empty())
			return;
		size = nums.size();
		numsRef = &nums;
		//numsRef.resize(size,0);
		ct.resize(size + 1, 0);
		for (int i = 0; i < nums.size(); i++)
			updateTree(i, nums[i]);
	}

	void update(int i, int val) {
		updateTree(i, val);
	}

	int sumRange(int i, int j) {
		return query(j) - query(i) + (*numsRef)[i];
	}
};

int main()
{
	vector<int> vt = { -28,-39,53,65,11,-56,-65,-39,-43,97 };
	NumArray s(vt);
	cout << s.sumRange(5, 6) << endl;
	s.update(9, 27);
	cout << s.sumRange(2, 3) << endl;
	cout << s.sumRange(6, 7) << endl;
	s.update(1, -82);
	s.update(3, -72);
	cout << s.sumRange(3, 7) << endl;
	cout << s.sumRange(1, 8) << endl;
	s.update(5, -13);
	s.update(4, -67);
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

