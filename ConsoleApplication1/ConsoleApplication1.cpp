// ConsoleApplication1.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <vector>
#include <bitset>
#include <unordered_map>
#include <algorithm>
using namespace std;

class Solution {
private:
    int gcd(int x, int y) {
        int t = x % y;
        while (t)
            x = y, y = t, t = x % y;
        return y;
    }
public:
    bool hasGroupsSizeX(vector<int>& deck) {
        if (0 == deck.size())
            return false;
        //unordered_map<int, int> mp;
        int mp[10001] = { 0 };
        for (auto i : deck)
            ++mp[i];
        int g = -1;
        for (int i = 1; i < 10001;++i) {
            if (g == -1)
                g = mp[i];
            else
                g = gcd(mp[i], g);
        }
        return g>=2;
    }
};
int main()
{
    vector<int> vt = { 1,1,1,1,1,1,2,2,2,2,2,2,2,2,2,3,3,3,3,3,3,3,3};
    Solution s;
    s.hasGroupsSizeX(vt);
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
