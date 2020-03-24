// interview_apple_simulate_2_2.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <string>
#include <unordered_set>
using namespace std;
class Solution {
private:
	int gcd(int a, int b) {
		int t = a % b;
		while (t)
			a = b, b = t, t = a % b;
		return b;
	}
	bool checkRepeat(int numerator, int denominator) {
		int t = gcd(numerator, denominator);
		int d = denominator;
		denominator /= t;
		while (denominator % 2 == 0)
			denominator /= 2;
		while (denominator % 5 == 0)
			denominator /= 5;
		if (denominator != 1)
			return true;
		else
			return false;
	}
public:
	string fractionToDecimal(int numerator, int denominator) {
		if (numerator % denominator == 0)
			return to_string(numerator / denominator);
		bool isRepeat = checkRepeat(numerator, denominator);
		if (!isRepeat) {
			string ret = to_string(numerator * 1.0 / denominator);
			while (*ret.rbegin() == '0') 
				ret.erase(ret.rbegin().base()-1);
			return ret;
		}
			
		string ret;
		double t = numerator * 1.0 / denominator;
		ret = to_string(int(t)) + ".(";
		int size = ret.size();
		unordered_set<int> st;
		unordered_set<int>::iterator it;
		t = (t - int(t)) * 10;
		while (1) {
			it = st.find(int(t));
			if (it == st.end()) {
				st.emplace(int(t));
				ret += to_string(int(t));
				t = (t - int(t)) * 10;
			}
			else {
				ret += ")";
				break;
			}
		}
		return ret;
	}
};
int main()
{
	Solution s;
//	cout << s.fractionToDecimal(1, 2) << endl;
	//cout << s.fractionToDecimal(2, 1) << endl;
	//cout << s.fractionToDecimal(0, 2) << endl;
	cout << s.fractionToDecimal(1, 333) << endl;
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
