// PAT_BASIC_1002.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include <iostream>
#include <string>
using namespace std;

int _tmain(int argc, _TCHAR* argv[])
{
	string s;
    while(cin>>s)
    {
		int input[10] = {0};
        _Longlong count = 0;

        for(int i=0;i<s.size();i++)
			count += s[i] - '0';
        string s = to_string(count);
        for(int i=0;i<s.size();i++)
		{
			if(s[i] == '0')
				cout<<"ling";
			else if(s[i] == '1')
				cout<<"yi";
			else if(s[i] == '2')
				cout<<"er";
			else if(s[i] == '3')
				cout<<"san";
			else if(s[i] == '4')
				cout<<"si";
			else if(s[i] == '5')
				cout<<"wu";
			else if(s[i] == '6')
				cout<<"liu";
			else if(s[i] == '7')
				cout<<"qi";
			else if(s[i] == '8')
				cout<<"ba";
			else if(s[i] == '9')
				cout<<"jiu";
			if(i!=s.size()-1)
				cout<<" ";
			else
				cout << endl;
		}
    }
    return 0;
}

