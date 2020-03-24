// interview_apple_simulate_2_1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_map>
#include <queue>
using namespace std;

class Solution {
private:
    struct node {
        int val;
        int cnt;
        node(int v, int c) :val(v), cnt(c) {}
    };
    static bool cmp(const node a, const node b) {
        return a.cnt > b.cnt;
    }
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        unordered_map<int, int> mp;
        unordered_map<int, int>::iterator it;
        for (auto i : nums) {
            it = mp.find(i);
            if (it == mp.end())
                mp.emplace(make_pair(i, 1));
            else
                ++it->second;
        }
        vector<node> vt;
        for (auto i : mp)
            vt.emplace_back(node(i.first,i.second));
        sort(vt.begin(), vt.end(),cmp);
        vector<int> ret;
        for (int i = 0; i < k && i < vt.size(); ++i)
            ret.emplace_back(vt[i].val);
        return ret;
    }
};
int main()
{
    Solution s;
    vector<int> vt = { 1,2,2,3 };
    s.topKFrequent(vt,1);
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
