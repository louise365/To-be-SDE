#include <iostream>
#include <cstdio>
using namespace std;

int main()
{
    int flag = 1;
    char c;
    while(scanf("%c",&c)!=EOF)
    {
        if(c == '"')
        {
            if(flag)
                printf("``");
            else
                printf("''");
            flag = !flag;
        }
        else
            printf("%c",c);
    }
    return 0;
}
