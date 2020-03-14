// leetcode_18.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <unordered_set>
#include <sstream>
using namespace std;

class Solution {
private:
    unordered_set<string> st;
    bool check(vector<int> vt)
    {
        sort(vt.begin(), vt.end());
        stringstream ss;
        string s;
        ss << vt[0] << "|" << vt[1] << "|" << vt[2] << "|" << vt[3];
        ss >> s;
        bool ret = (st.find(s) == st.end());
        if (ret)
            st.emplace(s);
        return ret;
    }
    vector<vector<int>> threeSum(vector<int>& nums, int target, int idx)
    {
        vector<vector<int>> ret;
        for (int i = idx+1; i < nums.size(); ++i)
        {
            if (i == idx) ++i;
            if (i >= nums.size())
                break;
            int t = target - nums[i];
            int s = i+1, e = nums.size() - 1;
            while (s < e && s < nums.size() && e >= 0)
            {
                while ((s == idx || s == i) && s>=0 && s<nums.size())
                    ++s;
                while ((e == idx || e == i) && e>=0 && e<nums.size())
                    --e;
                if (s >= nums.size() || e < 0 || s>=e)
                    break;
                if (nums[s] + nums[e] < t)  ++s;
                else if (nums[s] + nums[e] > t)  --e;
                else
                {
                    vector<int> v = { nums[s],nums[e],nums[i] };
                    ret.emplace_back(v);
                    ++s;
                }
            }
        }
        return ret;
    }
public:
    vector<vector<int>> fourSum(vector<int>& nums, int target) {
        vector<vector<int>> ret;
        if (nums.size() == 0)
            return ret;

        sort(nums.begin(), nums.end());
        for (int i = 0; i < nums.size(); i++)
        {
            if (nums[i] == -1)
                int a = 3;
            vector<vector<int>> t = threeSum(nums, target - nums[i], i);
            for (auto s : t)
            {
                s.insert(s.begin(), nums[i]);
                if (check(s))
                    ret.emplace_back(s);
            }
        }
        return ret;
    }
};
int main()
{
    Solution s;
    vector<int> vt = { -4,-3,-2,-1,0,0,1,2,3,4 };
    s.fourSum(vt,0);
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
