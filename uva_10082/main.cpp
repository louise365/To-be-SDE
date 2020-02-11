#include <iostream>
#include <cstring>
#include <cstdio>
using namespace std;

int main()
{
    char map[100] = "`1234567890-=QWERTYUIOP[]\\ASDFGHJKL;'ZXCVBNM,./\0";
    //cout<<map<<endl;
    char c;
    cin>>noskipws;
    while((c=cin.get())!=EOF)
    {
        if(c == '\n')
            cout<<endl;
        if(c==' ')
            cout<<" ";
        else
        {
            int len = strlen(map);
            for(int i=1;i<len;i++)
                if(map[i] == c)
                    cout<<map[i-1];
        }
    }
    return 0;
}
