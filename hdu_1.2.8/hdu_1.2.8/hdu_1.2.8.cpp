// hdu_1.2.8.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"

void returnProvince(char *in, char *out)
{
	if(in[0] == '3' && in[1] == '3')
		memcpy(out,"Zhejiang\0",9);
	if(in[0] == '1' && in[1] == '1')
		memcpy(out,"Beijing\0",8);
	if(in[0] == '7' && in[1] == '1')
		memcpy(out,"Taiwan\0",7);
	if(in[0] == '8' && in[1] == '1')
		memcpy(out,"Hong Kong\0",10);
	if(in[0] == '8' && in[1] == '2')
		memcpy(out,"Macao\0",6);
	if(in[0] == '5' && in[1] == '4')
		memcpy(out,"Tibet\0",6);
	if(in[0] == '2' && in[1] == '1')
		memcpy(out,"Liaoning\0",9);
	if(in[0] == '3' && in[1] == '1')
		memcpy(out,"Shanghai\0",9);
}

int _tmain(int argc, _TCHAR* argv[])
{

	int n;
	scanf("%d",&n);
	while(n--)
	{
		char input[19],out[20],year[5],month[3],day[3];
		scanf("%s",input);
		returnProvince(input,out);
		memcpy(year,input+6,4*sizeof(char));
		year[4] = '\0';
		memcpy(month,input+6+4,2*sizeof(char));
		month[2] = '\0';
		memcpy(day,input+6+4+2,2*sizeof(char));
		day[2] = '\0';

		printf("He/She is from %s,and his/her birthday is on %s,%s,%s based on the table.\n",
			out,month,day,year);
	}
	return 0;
}

