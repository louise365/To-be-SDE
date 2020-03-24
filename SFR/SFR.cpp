// SFR.cpp : 此文件包含 "main" 函数。程序执行将在此处开始并结束。
//

#include <iostream>
#include <memory>
#include <vector>
#include <string>
#include <cstring>
#include <algorithm>
#include "Polyfit.h"
#include "helper.h"
using namespace std;

class SFRMeasurement
{
private:
public:
	double Centroid(double* dataA, double* dataB, int N)
	{
		if ((dataA == NULL) || (dataB == NULL) || (N <= 0))
			return(-1);
		double temp = 0, loc = 0, dataSum = 0;
		int i = 0;

		for (i = 0; i < N; i++)
		{
			temp = dataA[i] * dataB[i];    //与窗数据相乘
			loc += (i + 1) * temp;
			dataSum += temp;
		}

		if (dataSum < 0.0001)
			return(0);
		else
			return(loc / dataSum);
	}
	//symmetric Hamming 
	void ProduceHammingData(double* hammBuf, int N, double mid)
	{
		if (hammBuf == NULL)	return 

		memset(hammBuf, 0, sizeof(double) * N);
		double arg = 0, wid1 = 0, wid2 = 0, wid;
		int i = 0;
		wid = max(mid-1, N-mid);
		if (!wid)
			wid = 1.0;
		for (i = 0; i < N; i++)
		{
			arg = (i + 1) - mid;
			hammBuf[i] = 0.54 + 0.46 * cos(PI * arg / wid);
		}
		return;
	}
	double DetectSlantedEdgeGrayRation(double* grayImageData, int width, int height)
	{
		if (grayImageData == NULL)
		{
			return(-1);
		}
		int i = 0, j = 0, blockN = 5;
		double sumLeft = 0.0, sumRight = 0.0, testGrayRatio = 0;
		blockN = width < 10 ? 3 : 5;
		for (i = 0; i < height; i++)
		{
			for (j = 0; j < blockN; j++)
			{
				sumLeft += grayImageData[i * width + j];
				sumRight += grayImageData[i * width + (width - blockN + j)];
			}
			sumRight += grayImageData[i * width + (width - blockN - 1)];
		}

		testGrayRatio = sumLeft - sumRight;
		return(testGrayRatio);
	}

	int FFT(int number, double dx, double* pInLSF, int ns, double ds, double* pOutSFR)
	{
		if ((pInLSF == NULL) || (pOutSFR == NULL))
		{
			return(-1);
		}

		double a = 0, b = 0, PI2 = 0, g = 0, maxSfr = 1.0;
		int i = 0, j = 0;

		PI2 = 2.0 * PI;
		for (j = 0; j < ns; j++)
		{
			g = PI2 * dx * ds * (double)j;
			a = 0;
			b = 0;
			for (i = 0; i < number; i++)
			{
				a += pInLSF[i] * cos(g * (double)(i));
				b += pInLSF[i] * sin(g * (double)(i));
			}
			pOutSFR[j] = sqrt(a * a + b * b);

			if (j == 0)
			{
				maxSfr = pOutSFR[0];
				if (maxSfr == 0)
				{
					maxSfr = 1.0;
				}
			}
			pOutSFR[j] /= maxSfr;    //归一化
		}
		return(0);
	}
	template<typename T> T* differential(T*& buff, int len) {
		if (len < 2)
			return 0;
		T* ret = (T*)malloc((len - 1) * sizeof(T));
		if (!ret)
			return ret;
		for (int i = 0; i < len - 1; ++i)
			ret[i] = buff[i + 1] - buff[i];
		return ret;
	}
	//roi_x,roi_y -> left top corner
	template<typename T> T* crop(T*& buff, int imgW, int imgH,
		int roi_x, int roi_y, int roi_w, int roi_h) {
		T* ret = 0;
		//todo
		return ret;
	}
	template<typename T> bool validateModulationRatio(T*& buff, int width, int height, 
		float thresholod = 0.2, int testSize = 1) {
		//const int checkRoiNum = 4;
		if (width < 3 || height < 3)
			return 0;
		//left top,right top,left bottom,right bottom
		//simplify to be one pixel for the check area size
		testSize = 0;
		vector<pair<int, int>> vt = {
			make_pair(0,0),
			make_pair(width - 1,0),
			make_pair(0,height - 1),
			make_pair(width - 1,height - 1) };
		vector<double> ratio;
		for (auto v : vt) {
			double sum = 0;
			for (int i = v.first - testSize; i <= v.first + testSize; ++i)
				for (int j = v.second - testSize; j <= v.second + testSize; ++j)
					sum += buff[i + j * width];
			if(testSize)
				ratio.emplace_back(sum / testSize / testSize);
			else
				ratio.emplace_back(sum);
		}
		if (fabs((ratio[0] - ratio[1]) / (ratio[0] + ratio[1])) < thresholod ||
			fabs((ratio[2] - ratio[3]) / (ratio[2] + ratio[3])) < thresholod)
			return false;
		return true;
	}
	template<typename T> T* OECF(T*& buff, int len, float gamma = 1.0) {
		if (gamma == 0)
			return 0;
		T* ret = (T*)malloc((len) * sizeof(T));
		if (gamma == 1)
			memcpy(ret, buff, len * sizeof(T));
		else
			for (int i = 0; i < len; ++i)
				ret[i] = powf(buff, gamma);
		return ret;
	}
	int SFR(unsigned short* usBuffer, int width, int height, float gamma) {
		//1, converted to a linear quantization charcteristic
		//2, differentiate using discrete derivative
		//3, calculate the best fit line to the centroids of the first derivatives
		//4, create a single "composite" line data from line 2,3,etc. 
	}
};

int main()
{
	SFRMeasurement s;
	int width, height;
	int* buff = readFromCSV("d:\\sfr.txt",width,height);
	s.validateModulationRatio(buff, width, height);
	s.OECF(buff, width * height);
}

// 运行程序: Ctrl + F5 或调试 >“开始执行(不调试)”菜单
// 调试程序: F5 或调试 >“开始调试”菜单

// 入门使用技巧: 
//   1. 使用解决方案资源管理器窗口添加/管理文件
//   2. 使用团队资源管理器窗口连接到源代码管理
//   3. 使用输出窗口查看生成输出和其他消息
//   4. 使用错误列表窗口查看错误
//   5. 转到“项目”>“添加新项”以创建新的代码文件，或转到“项目”>“添加现有项”以将现有代码文件添加到项目
//   6. 将来，若要再次打开此项目，请转到“文件”>“打开”>“项目”并选择 .sln 文件
