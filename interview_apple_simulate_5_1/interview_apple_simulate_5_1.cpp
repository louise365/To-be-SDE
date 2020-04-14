// interview_apple_simulate_5_1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
private:
    bool isValid(string s) {
        if (s.size() == 1)
            return true;
        char c = s[0];
        for (int i = 1; i < s.size(); ++i) {
            if (s[i] != c + 1)
                return false;
            else
                ++c;
        }
        return true;
    }
public:
    vector<vector<string>> groupStrings(vector<string>& strings) {
        vector<vector<string>> ret;
        unordered_map<int, vector<string>> mp;
        if (strings.empty())
            return ret;
        for (auto s : strings) {
            if (isValid(s))
                mp[s.size()].emplace_back(s);
        }
        unordered_map<int, vector<string>>::iterator it;
        vector<string>::iterator it1;
        for (it = mp.begin(); it != mp.end(); ++it) {
            vector<string> tmp;
            for (it1 = it->second.begin(); it1 != it->second.end(); ++it1) {
                tmp.emplace_back(*it1); 
            }
            ret.emplace_back(tmp);
        }
        return ret;
    }
};
int main()
{
    Solution s;
    vector<string> vt = { "abc","bcd","acef","xyz","az","ba","a","z" };
    s.groupStrings(vt);
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

