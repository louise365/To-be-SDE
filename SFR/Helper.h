#pragma once
#include <string>
using namespace std;
#define PI 3.1415926
int* readFromCSV(string filePath, int& width, int& height) {
	FILE* fp = fopen(filePath.c_str(), "r");
	if (!fp)
		return 0;
	int* ret = 0;
	fscanf(fp, "%d %d\n", &width, &height);
	if (width > 0 && height > 0) {
		ret = (int*)malloc(width * height * sizeof(int));
		if (ret) {
			int count = width * height;
			for (int i = 0; i < count; ++i)
				fscanf(fp, "%d", ret + i);
		}
	}
	fclose(fp);
	return ret;
}

int GetMaxIndex(double* data, int dataLen)
{
	int i;
	double max0 = data[0];
	int maxIndex = 0;

	for (i = 0; i < dataLen; i++)
	{
		if (data[i] >= max0)
		{
			max0 = data[i];
			maxIndex = i;
		}
	}
	return(maxIndex);
}

//从数据中得到最小值的位置
int GetMinIndex(double* data, int dataLen)
{
	int i;
	double min0 = data[0];
	int minIndex = 0;

	for (i = 0; i < dataLen; i++)
	{
		if (data[i] <= min0)
		{
			min0 = data[i];
			minIndex = i;
		}
	}
	return(minIndex);
}

//CW 90degree
int Rotatev(double* img, int width, int height)
{
	if ((img == NULL) || (width <= 0) || (height <= 0))
	{
		return(0);
	}
	int i, j, rflag = 0;

	if (width > height)  //如果宽大于高,则刀口图像转置,使宽小于高
	{
		double* buf = NULL;
		buf = (double*)malloc(sizeof(double) * width * height);
		if (buf == NULL)
		{
			return(0);
		}
		memset(buf, 0, sizeof(double) * width * height);

		for (i = 0; i < height; i++)
		{
			for (j = 0; j < width; j++)
			{
				buf[j * height + i] = img[i * width + j];              //转置
			}
		}
		memcpy(img, buf, sizeof(double) * width * height);
		free(buf);
		buf = NULL;
		rflag = 1;
	}
	return(rflag);
}

/*******************************5点平滑处理*************************************/
/*
y[-2] = 1/70 * (69 * y[-2] + 4 * y[-1] - 6 * y[1] - y[2])
y[-1] = 1/30 * (2 * y[-2] + 27 * y[-1] +12 * y[0] - 8 * y[1] + 2 * y[2])
y[0]  = 1/35 * (-3 * y[-2] + 12 * y[-1] + 17 * y[0] + 12 * y[1] - 3 * y[2])
y[1] = ...
y[2] = ...
*/
void Smooth5Dot(double* y, int dataLen, int count)
{
	if ((y == NULL) || (dataLen < 5))
	{
		return;
	}

	int i = 0, j = 0;
	double outData[512] = { 0 };

	for (j = 0; j < count; j++)
	{
		outData[0] = 69.0 * y[0] + 4.0 * y[1] - 6.0 * y[2] + 4.0 * y[3] - y[4];
		outData[0] = outData[0] / 70.0;
		outData[1] = 2.0 * (y[0] + y[4]) + 27.0 * y[1] + 12.0 * y[2] - 8.0 * y[3];
		outData[1] = outData[1] / 35.0;
		for (i = 2; i <= dataLen - 3; i++)
		{
			outData[i] = -3.0 * y[i - 2] + 12.0 * y[i - 1] + 17.0 * y[i];
			outData[i] = (outData[i] + 12.0 * y[i + 1] - 3.0 * y[i + 2]) / 35.0;
		}
		outData[dataLen - 2] = 2.0 * y[dataLen - 5] - 8.0 * y[dataLen - 4] + 12.0 * y[dataLen - 3];
		outData[dataLen - 2] = (outData[dataLen - 2] + 27.0 * y[dataLen - 2] + 2.0 * y[dataLen - 1]) / 35.0;
		outData[dataLen - 1] = -y[dataLen - 5] + 4.0 * y[dataLen - 4] - 6.0 * y[dataLen - 3];
		outData[dataLen - 1] = (outData[dataLen - 1] + 4.0 * y[dataLen - 2] + 69.0 * y[dataLen - 1]) / 70.0;

		for (i = 0; i < dataLen; i++)
		{
			y[i] = outData[i];
		}
	}
}

void Smooth5Dot_2(double* pData, int dataLen)
{
	if ((pData == NULL) || (dataLen < 5))
	{
		return;
	}

	int i = 0;
	double* pTempBuf = NULL;
	pTempBuf = (double*)malloc(sizeof(double) * dataLen);
	memset(pTempBuf, 0, sizeof(double) * dataLen);

	pTempBuf[0] = (3 * pData[0] + 2 * pData[1] + pData[2] - pData[4]) / 5;
	pTempBuf[1] = (4 * pData[0] + 3 * pData[1] + 2 * pData[2] + pData[3]) / 10;
	for (i = 2; i < dataLen - 2; i++)
	{
		pTempBuf[i] = (pData[i - 1] + pData[i - 2] + pData[i] + pData[i + 1] + pData[i + 2]) / 5;
	}
	pTempBuf[dataLen - 2] = (pData[dataLen - 4] + 2 * pData[dataLen - 3] + 3 * pData[dataLen - 2] + 4 * pData[dataLen - 1]) / 10;
	pTempBuf[dataLen - 1] = (3 * pData[dataLen - 1] + 2 * pData[dataLen - 2] + pData[dataLen - 3] - pData[dataLen - 5]) / 5;

	memcpy(pData, pTempBuf, sizeof(double) * dataLen);
	free(pTempBuf);
	pTempBuf = NULL;
	return;
}

int RotateMatrixByData(double* pInData, int width, int height)
{
	if ((pInData == NULL) || (width <= 0) || (height <= 0))
	{
		return(0);
	}

	int nn = 3;                                    //Limits test area. Normally not a problem.
	double sum0 = 0.0, sum1 = 0.0;
	int sumCount = 0, i = 0, j = 0;
	double testV = 0, testH = 0;
	for (i = 0; i < width; i++)                         //Compute v ranges
	{
		sum0 += pInData[(height - nn - 1) * width + i];  //下边
		sum1 += pInData[(nn - 1) * width + i];         //上边
	}
	testV = fabs((sum0 - sum1) / width);
	sum0 = 0;
	sum1 = 0;
	for (i = 0; i < height; i++)                        //Compute h ranges
	{
		sum0 += pInData[i * width + (width - nn - 1)];   //右边
		sum1 += pInData[i * width + nn - 1];           //左边
	}
	testH = fabs((sum0 - sum1) / height);

	int rflag = 0;
	if (testV > testH)   //刀口图像旋转90度
	{
		double* buf = NULL;
		buf = (double*)malloc(sizeof(double) * width * height);
		if (buf == NULL)
		{
			return(0);
		}
		memset(buf, 0, sizeof(double) * width * height);

		for (i = 0; i < height; i++)
		{
			for (j = 0; j < width; j++)
			{
				buf[j * height + i] = pInData[i * width + j];              //转置
			}
		}
		memset(pInData, 0, sizeof(double) * width * height);
		for (i = width - 1; i >= 0; i--)
		{
			for (j = 0; j < height; j++)
			{
				pInData[(width - i - 1) * height + j] = buf[i * height + j];   //上下互换
			}
		}

		free(buf);
		buf = NULL;
		rflag = 1;
	}
	return(rflag);
}

/************************************求微分************************************************/
int Derivl(double* img, double* pFiltBuf, int width, int height, double* pFil, int filLen)
{
	if ((img == NULL) || (pFiltBuf == NULL) || (pFil == NULL) ||
		(width <= 0) || (height <= 0) || (filLen <= 0))
	{
		return(-1);
	}

	int i = 0, j = 0, nn = filLen;
	int lenA = filLen;
	int len = sizeof(double) * (width + filLen - 1);

	double* temp = NULL;
	temp = (double*)malloc(len);                          //存放卷积结果
	if (temp == NULL)
	{
		return(-1);
	}
	for (i = 0; i < height; i++)
	{
		memset(temp, 0, len);
		Conv(pFil, img + i * width, lenA, width, temp);        //卷积
		for (j = nn - 1; j < width; j++)
		{
			pFiltBuf[i * width + j] = temp[j];
		}
		pFiltBuf[i * width + nn - 2] = pFiltBuf[i * width + nn - 1];
	}

	free(temp);
	temp = NULL;

	return(0);
}