// leetcode_703.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <vector>
#include <iostream>
#include <algorithm>
#include <map>
#include <set>
using namespace std;
class KthLargest {
public:
	KthLargest(int k, vector<int>& nums) {
		this->k = k;
		for (int i = 0; i < nums.size(); i++)
			add(nums[i]);
	}
	int add(int val) {
		st.insert(val);
		if (st.size() > k)
			st.erase(st.begin());
		return *(st.begin());
	}
private:
	multiset<int> st;
	int k;
};

class KthLargest1 {
public:
	KthLargest1(int k, vector<int>& nums){
		this->k = k;
		map<int, int>::iterator it;
		for (int i = 0; i < nums.size(); i++)
		{
			it = st.find(nums[i]);
			if (it == st.end())
				st.insert(make_pair(nums[i], 1));
			else
				(*it).second++;
		}	
	}
	
	int add(int val) {
		map<int,int>::iterator it = st.find(val);
		if (it != st.end())
			(*it).second++;
		else
			st.insert(make_pair(val, 1));
		map<int,int>::reverse_iterator rit = st.rbegin();
		int n = k;
		while (1)
		{
			if (n > (*rit).second)
			{
				n -= (*rit).second;
				rit++;
			}
			else
				break;
		}
			
		return (*rit).first;
	}
private:
	map<int,int> st;
	int k;
};


int main()
{
	vector<int> v = {4,5,8,2};
	KthLargest s(3,v);
	cout << s.add(3) << endl;
	cout << s.add(5) << endl;
	cout << s.add(10) << endl;
	cout << s.add(9) << endl;
	cout << s.add(4) << endl;
    return 0;
}

