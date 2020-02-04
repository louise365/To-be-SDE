// leetcode_705.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <iostream>
#include <unordered_set>
using namespace std;
class MyHashSet {
public:
	/** Initialize your data structure here. */
	MyHashSet() {
		
	}

	void add(int key) {
		st.insert(key);
	}

	void remove(int key) {
		st.erase(st.find(key));
	}

	/** Returns true if this set contains the specified element */
	bool contains(int key) {
		return st.find(key) != st.end();
	}
private:
	unordered_set<int> st;
};
int main()
{

    return 0;
}

