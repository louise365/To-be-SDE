// leetcode_414.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

class Solution {
public:
    int thirdMax(vector<int>& nums) {
        long long n[3] = { LONG_MIN,LONG_MIN,LONG_MIN };
        for (int i = 0; i < nums.size(); ++i) {
            if (n[0] < nums[i]) {
                n[2] = n[1];
                n[1] = n[0];
                n[0] = nums[i];
            }
            else if (n[1] < nums[i] && n[0] > nums[i]) {
                n[2] = n[1];
                n[1] = nums[i];
            }
            else if (n[2] < nums[i] && nums[i] < n[1]) {
                n[2] = nums[i];
            }
        }
        if (n[2] == LONG_MIN)
            return n[0];
        else
            return n[2];
    }
};
class Solution1 {
private:
    static bool cmp(const int& a, const int& b) {
        return a > b;
    }
public:
    int thirdMax(vector<int>& nums) {
        set<int> n;
        for (int i = 0; i < nums.size() && i < 3; ++i) {
            n.emplace(nums[i]);
        }
        if (nums.size() < 3)
            return *n.rbegin();
        for (int i = 3; i < nums.size(); ++i) {
            n.emplace(nums[i]);
            if(n.size()>3)
                n.erase(n.begin());
        }
        return n.size()==3? *n.begin():*n.rbegin();
    }
};
int main()
{
    Solution s;
    vector<int> vt = { -2147483648,1,1 };
    s.thirdMax(vt);
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
