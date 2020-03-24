#pragma once 
/**************************************************************************************************
  �������� void PolyfitFunc(int n, int m, double x[], double y[], double a[], double dt[])
	���ܣ� ����������ʽ����С�����������
���������
	 int n          �������ݵ�ĸ���
	 int m          ��϶���ʽ������������϶���ʽ�Ĵ���Ϊm-1��Ҫ��m<=n��m<=20
	 double x[n]    ��Ÿ���n�����ݵ��x����
	 double y[n]    ��Ÿ���n�����ݵ��y����
���������
	 double a[m]    ����m-1����϶���ʽ��m��ϵ������϶���ʽ��ʽΪ
					Pm-1(x)=a(0)+a(1)*x+a(2)*x^2+...+a(m-1)*x^(m-1)
	 double dt[3]   ����dt[0]������϶���ʽ�����ݵ�����ƽ���ͣ�dt[1]���������϶���ʽ�����ݵ�
					���ľ���ֵ֮�ͣ�dt[2]���������϶���ʽ�����ݵ�������ֵ�����ֵ����
***************************************************************************************************/
#define NULL 0
#define fabs(a) (a>0?a:-a)
void PolyfitFunc(int n, int m, double x[], double y[], double a[], double dt[])
{
	if ((x == NULL) || (y == NULL) || (a == NULL) || (dt == NULL)
		|| (n <= 0) || (m < 0))
	{
		return;
	}

	int i = 0, j = 0, k = 0;
	double alpha, p, q, g, w, beta, d1, d2, s[20], t[20], b[20];

	if (m > 20)
	{
		//printf("����ʽ������಻�ܳ���\n");
		return;
	}

	for (i = 0; i <= m - 1; i++)
	{
		a[i] = 0.0;
	}
	if (m > n)
	{
		m = n;
	}
	if (m > 20)
	{
		m = 20;
	}
	b[0] = 1.0;
	d1 = n;
	alpha = 0.0;
	q = 0.0;
	for (i = 0; i <= n - 1; i++)
	{
		alpha = alpha + x[i];
		q = q + y[i];
	}
	q = q / d1;                                         //q0
	alpha = alpha / d1;                                 //alpha(0)
	a[0] = q * b[0];
	if (m > 1)
	{
		t[1] = 1.0; t[0] = -alpha;
		d2 = 0.0; q = 0.0; g = 0.0;
		for (i = 0; i <= n - 1; i++)                         //����q1,alpha(1)��d1
		{
			w = x[i] - alpha;
			d2 = d2 + w * w;
			q = q + y[i] * w;
			g = g + x[i] * w * w;
		}
		q = q / d2;                                      //q1
		alpha = g / d2;                                  //alpha(1)
		beta = d2 / d1;                                  //����beta(1)
		d1 = d2;
		a[1] = q * t[1];
		a[0] = q * t[0] + a[0];
	}
	for (j = 2; j <= m - 1; j++)                              //���Ƽ���Qj(x)
	{
		s[j] = t[j - 1];
		s[j - 1] = -alpha * t[j - 1] + t[j - 2];
		if (j >= 3)
		{
			for (k = j - 2; k >= 1; k--)
				s[k] = -alpha * t[k] + t[k - 1] - beta * b[k];
		}
		s[0] = -alpha * t[0] - beta * b[0];
		d2 = 0.0; q = 0.0; g = 0.0;
		for (i = 0; i <= n - 1; i++)                          //����qj,alpha(j)��dj
		{
			w = s[j];
			for (k = j - 1; k >= 0; k--)
			{
				w = w * x[i] + s[k];
			}
			d2 = d2 + w * w; q = q + y[i] * w;
			g = g + x[i] * w * w;
		}
		q = q / d2;                                        //qj
		alpha = g / d2;                                    //alpha(j)
		beta = d2 / d1;                                    //����beta(j)
		d1 = d2;
		a[j] = q * s[j]; t[j] = s[j];
		for (k = j - 1; k >= 0; k--)
		{
			a[k] = q * s[k] + a[k];
			b[k] = t[k]; t[k] = s[k];
		}
	}
	dt[0] = 0.0; dt[1] = 0.0; dt[2] = 0.0;
	for (i = 0; i <= n - 1; i++)
	{
		w = a[m - 1];
		for (k = m - 2; k >= 0; k--)
		{
			w = a[k] + w * x[i];
		}
		p = w - y[i];
		if (fabs(p) > dt[2])
		{
			dt[2] = fabs(p);
		}
		dt[0] = dt[0] + p * p;
		dt[1] = dt[1] + fabs(p);
	}
	return;
}
