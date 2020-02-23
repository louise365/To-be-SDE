// leetcode_311.cpp : 定义控制台应用程序的入口点。
//

#include "stdafx.h"
#include "malloc.h"

int *result	=	0;
int** multiply(int** A, int ASize, int* AColSize, int** B, int BSize, int* BColSize, int* returnSize, int** returnColumnSizes){
	int ARowSize	=	ASize /	(* AColSize);
	//int BRowSize	=	BSize	/	(*BColSize);
	*returnSize = ARowSize * (*BColSize);
	**returnColumnSizes = *BColSize;
	if(result)	free(result);
	result	=	(int*)malloc((*returnSize) * sizeof(int));
	int *a = *A;
	int *b = *B;
	for(int i=0;i<ASize;i++)
	{
		int row = i/(*AColSize);
		int col = i%(*AColSize);
		*(result+i) = 0;
		for(int j=0;j<(*AColSize);j++)
			*(result+i) += a[j+row*(*AColSize)] * b[col + j * (*BColSize)];
	}

	return &result;
}

int _tmain(int argc, _TCHAR* argv[])
{
	int a[6] = {1,0,0,-1,0,3};
	int *_a = (int*)a;
	int b[9] = {7,0,0,0,0,0,0,0,1};
	int *_b = (int*)b;
	int acolsize = 3;
	int bcolsize = 3;
	int retsize;
	int retcolsize;
	int *_retcolsize = &retcolsize;
	int **ret = multiply(&_a,6,&acolsize,&_b,9,&bcolsize,&retsize,&_retcolsize);
	return 0;
}

