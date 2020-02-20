// leetcode_170.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <set>
using namespace std;
class TwoSum {
private:
	multiset<int> st;
public:
	/** Initialize your data structure here. */
	TwoSum() {

	}

	/** Add the number to an internal data structure.. */
	void add(int number) {
		st.insert(number);
	}

	/** Find if there exists any pair of numbers which sum is equal to the value. */
	bool find(int value) {
		if (st.size() < 2)
			return false;
		multiset<int>::iterator it = st.begin();
		multiset<int>::reverse_iterator rit = st.rbegin(), rit_p = st.rbegin();
		rit_p++;
		bool ret = false;
		while (it != rit_p.base() && it!=st.end() && rit!=st.rend())
		{
			if (*it + *rit == value)
			{
				ret = true;
				break;
			}
			else if (*it + *rit < value)
				it++;
			else
			{
				rit++;
				rit_p++;
			}
		}
		return ret;
	}
};
int main()
{
	TwoSum s;
	s.add(1);
	s.add(2);
	s.add(2);
	s.add(3);
	s.find(6);
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
