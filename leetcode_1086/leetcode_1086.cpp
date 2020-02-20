// leetcode_1086.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <set>
using namespace std;
struct node
{
	int count;
	multiset<int> score;
};
class Solution {
public:
	vector<vector<int>> highFive(vector<vector<int>>& items) {
		map<int, node>mp;
		map<int, node>::iterator it;
		multiset<int>::iterator sit;
		for (int i = 0; i < items.size(); i++)
		{
			it = mp.find(items[i][0]);
			if (it == mp.end())
			{
				node n;
				n.count = 1;
				n.score.insert(items[i][1]);
				mp.insert(make_pair(items[i][0], n));
			}
			else
			{
				(*it).second.score.insert(items[i][1]);
				if ((*it).second.count < 5)
					(*it).second.count++;
				else
					//maintain top 5 score
					(*it).second.score.erase((*it).second.score.begin());
			}
		}
		vector<vector<int>> ret;
		for (auto m : mp)
		{
			vector<int>vt;
			int sum = 0;
			vt.push_back(m.first);
			for (auto s : m.second.score)
				sum += s;
			vt.push_back(sum / 5);
			ret.push_back(vt);
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
