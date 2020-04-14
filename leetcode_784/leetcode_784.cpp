// leetcode_784.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <string>
using namespace std;
class Solution {
private:
    string getString(int v) {
        string t;
        t = v;
        return t;
    }
    string getString(char v) {
        string t;
        t = v;
        return t;
    }
public:
    vector<string> letterCasePermutation(string S) {
        vector<string> ret;
        for (int i = 0; i < S.size(); ++i) {
            if (!isalpha(S[i])) {
                if (ret.empty())
                {
                    ret.emplace_back(getString(char(S[i])));
                    continue;
                }
                for (int j = 0; j < ret.size(); ++j) {
                    ret[j] += getString(char(S[i]));
                }
            }
            else {
                if (ret.empty()) {
                    ret.emplace_back(getString(char(tolower(S[i]))));
                    ret.emplace_back(getString(char(toupper(S[i]))));
                    continue;
                }
                int size = ret.size();
                for (int j = 0; j < size; ++j) {
                    ret.emplace_back(ret[j]);
                    ret[j] += getString(char(tolower(S[i])));
                }
                for (int j = size; j < size * 2; ++j) {
                    ret[j] += getString(char(toupper(S[i])));
                }
            }
        }
        return ret;
    }
};
int main()
{
    Solution s;
    s.letterCasePermutation("a1b2");
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
