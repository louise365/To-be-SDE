#include <iostream>
#include <string>
using namespace std;

int main()
{
	int map[256] = { 0 };
	string out[4] = { " -- is not a palindrome."," -- is a regular palindrome."," -- is a mirrored string."," -- is a mirrored palindrome." };
	//memset(map, 0 - 1, sizeof(unsigned char) * 256);
	map['A'] = 'A'; map['E'] = '3'; map['H'] = 'H';
	map['I'] = 'I'; map['J'] = 'L'; map['L'] = 'J';
	map['M'] = 'M'; map['O'] = 'O'; map['S'] = '2';
	map['T'] = 'T'; map['U'] = 'U'; map['V'] = 'V';
	map['W'] = 'W'; map['X'] = 'X'; map['Y'] = 'Y';
	map['Z'] = '5'; map['1'] = '1'; map['2'] = 'S';
	map['3'] = 'E'; map['5'] = 'Z'; map['8'] = '8';
	map['0'] = '0';
	string s;
	while (cin >> s)
	{
		int regular = 1;
		int mirror = 1;
		for (int i = 0; i < s.size() / 2; i++)
		{
			if (s[i] != s[s.size() - 1 - i])
			{
				regular = 0;
				break;
			}
		}
		for (int i = 0; i < s.size() / 2; i++)
		{
			int s1 = s[i];
			int s2 = s[s.size() - 1 - i];
			if (map[s[i]] == 0)
			{
				mirror = 0;
				break;
			}
			if (map[s[s.size() - 1 - i]] == 0)
			{
				mirror = 0;
				break;
			}
			if (map[s[s.size() - 1 - i]] != s[i])
			{
				mirror == 0;
				break;
			}
		}
		cout << s << out[mirror * 2 + regular] << endl;
	}
	return 0;
}

