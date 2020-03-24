// interview_apple_simulate_3_1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
#include <unordered_set>
using namespace std;

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> ret;
        if (s.size() <= 10)
            return ret;
        unordered_map<string,int> mp;
        unordered_set<string> st;
        for (int i = 0; i < s.size(); ++i) {
            string t = s.substr(i, 10);
            if (mp.find(t) == mp.end())
                mp.emplace(make_pair(t, 1));
            else
                st.emplace(t);
        }
        for (auto i : st)
            ret.emplace_back(i);
        return ret;
    }
};
int main()
{
    Solution s;
    s.findRepeatedDnaSequences("AAAAAAAAAAAA");
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
