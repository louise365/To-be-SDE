// leetcode_1462.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <stack>
using namespace std;
class CQueue {
private:
	stack<int>s[2];
	int idx;
	bool direction;
	void transport()
	{
		while (!s[idx].empty())
		{
			s[1 - idx].push(s[idx].top());
			s[idx].pop();
		}
		idx = 1 - idx;
		direction = !direction;
	}
public:
	CQueue() {
		idx = 0;
		direction = true;
	}

	void appendTail(int value) {
		if (!direction)
			transport();
		s[idx].push(value);
	}

	int deleteHead() {
		int ret = -1;
		if (direction)
			transport();

		if (s[idx].empty())
			ret = -1;
		else
		{
			ret = s[idx].top();
			s[idx].pop();
		}
		
		return ret;
	}
};

int main()
{
	CQueue s;
	s.appendTail(3);
	cout << s.deleteHead() << endl;
	cout << s.deleteHead() << endl;
	cout << s.deleteHead() << endl;
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
