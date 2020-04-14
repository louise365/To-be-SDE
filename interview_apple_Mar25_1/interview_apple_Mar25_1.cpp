#include <stdio.h>

// To execute C, please define "int main()"

int main() {
	for (int i = 0; i < 5; i++) {
		printf("Hello, World\n");
	}
	return 0;
}

/* write a function that takes 2 char* inputs and returns true or false based on if the second string is a substring of the first

{a,a,b,c}
{a,b}
true

{a,a,b,c}
{a,c}
false

strlen

*/
bool validSubstring(char* str1, char* str2) {
	if (!str1 || !str2)
		return false;
	int size1 = strlen(str1);
	int size2 = strlen(str2);
	//O(n^2)
	bool ret = true;
	for (int i = 0; i < size1; ++i) {
		ret = true;
		for (int j = i; j < size2 && i + j < size1; ++j) {
			if (str1[i + j] != str2[j]) {
				ret = false;
				break;
			}
			if (j == size2)
				return true;
		}
		if (ret)
			break;
	}
	return ret;
}