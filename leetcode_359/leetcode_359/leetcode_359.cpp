// leetcode_359.cpp : Defines the entry point for the console application.
//

#include "stdafx.h"
#include <string>
#include <unordered_map>
using namespace std;
class Logger {
private:
	unordered_map<string, int> mp;
	unordered_map<string, int>::iterator it;
public:
	/** Initialize your data structure here. */
	Logger() {

	}

	/** Returns true if the message should be printed in the given timestamp, otherwise returns false.
	If this method returns false, the message will not be printed.
	The timestamp is in seconds granularity. */
	bool shouldPrintMessage(int timestamp, string message) {
		it = mp.find(message);
		bool ret = false;
		if (it == mp.end())
		{
			mp.insert(make_pair(message, timestamp));
			ret = true;
		}
		else
		{
			if ((timestamp - (*it).second) > 10)
			{
				(*it).second = timestamp;
				ret = true;
			}
			else
				ret = false;
		}
		return ret;
	}
};

/**
* Your Logger object will be instantiated and called as such:
* Logger* obj = new Logger();
* bool param_1 = obj->shouldPrintMessage(timestamp,message);
*/
int main()
{
    return 0;
}

