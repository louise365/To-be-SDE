// leetcode_246.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <unordered_map>
using namespace std;

class Solution {
private:
	unordered_map<char, char> st;
	unordered_map<char, char>::iterator it;
public:
	bool isStrobogrammatic(string num) {
		bool ret = true;
		st.insert(make_pair('6', '9'));
		st.insert(make_pair('9', '6'));
		st.insert(make_pair('0', '0'));
		st.insert(make_pair('1', '1'));
		st.insert(make_pair('8', '8'));
		for (int i = 0; i < (num.size() + 1) / 2; i++)
		{
			it = st.find(num[i]);
			if (it == st.end() || (*it).second != num[num.size() - 1 - i])
			{
				ret = false;
				break;
			}
		}
		return ret;
	}
};
int main()
{
	std::cout << "Hello World!\n";
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
