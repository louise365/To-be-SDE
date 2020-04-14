// leetcode_506.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
private:
    static bool cmp(const int& a, const int& b) {
        return a > b;
    }
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        vector<string> ret;
        if (nums.size() == 0)
            return ret;
        vector<int> copy = nums;
        //vector<int> idx(nums.size());
        ret.resize(nums.size());
        sort(copy.begin(), copy.end(),cmp);
        for (int i = 0; i <nums.size(); ++i)
        {
            int idx = find(copy.begin(), copy.end(), nums[i]) - copy.begin();
            if (idx == 0)
                ret[i] = "Gold Medal";
            else if (idx == 1)
                ret[i] = "Silver Medal";
            else if (idx == 2)
                ret[i] = "Bronze Medal";
            else
                ret[i] = to_string(idx+1);
        }
        return ret;
    }
};
class Solution {
public:
    vector<string> findRelativeRanks(vector<int>& nums) {
        vector<string> ret;
        int maxv = 0;
        for (auto i : nums)
            maxv = max(maxv, i);
        vector<int> vt(maxv + 1,-1);
        ret.resize(nums.size());
        for (int i = 0;i<nums.size();++i)
            vt[nums[i]] = i;
        int count = 1;
        while (maxv) {
            if (vt[maxv] != -1) {
                if (count == 1)
                    ret[vt[maxv]] = "Gold Medal";
                else if (count == 2)
                    ret[vt[maxv]] = "Silver Medal";
                else if (count == 3)
                    ret[vt[maxv]] = "Bronze Medal";
                else
                    ret[vt[maxv]] = to_string(count);
                ++count;
            }
            --maxv;
        }
        return ret;
    }
};

int main()
{
    Solution s;
    vector<int> vt = { 10,3,8,9,4};
    s.findRelativeRanks(vt);
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
