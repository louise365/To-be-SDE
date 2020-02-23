
// OpticalCenterToolDlg.cpp : 实现文件
//

#include "stdafx.h"
#include "OpticalCenterTool.h"
#include "OpticalCenterToolDlg.h"
#include "afxdialogex.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// COpticalCenterToolDlg 对话框




COpticalCenterToolDlg::COpticalCenterToolDlg(CWnd* pParent /*=NULL*/)
	: CDialogEx(COpticalCenterToolDlg::IDD, pParent)
{
	m_hIcon = AfxGetApp()->LoadIcon(IDR_MAINFRAME);
}

void COpticalCenterToolDlg::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
}

BEGIN_MESSAGE_MAP(COpticalCenterToolDlg, CDialogEx)
	ON_WM_PAINT()
	ON_WM_QUERYDRAGICON()
	ON_BN_CLICKED(IDC_BUTTON1, &COpticalCenterToolDlg::OnBnClickedButton1)
END_MESSAGE_MAP()


// COpticalCenterToolDlg 消息处理程序

BOOL COpticalCenterToolDlg::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	// 设置此对话框的图标。当应用程序主窗口不是对话框时，框架将自动
	//  执行此操作
	SetIcon(m_hIcon, TRUE);			// 设置大图标
	SetIcon(m_hIcon, FALSE);		// 设置小图标

	// TODO: 在此添加额外的初始化代码

	return TRUE;  // 除非将焦点设置到控件，否则返回 TRUE
}

// 如果向对话框添加最小化按钮，则需要下面的代码
//  来绘制该图标。对于使用文档/视图模型的 MFC 应用程序，
//  这将由框架自动完成。

void COpticalCenterToolDlg::OnPaint()
{
	if (IsIconic())
	{
		CPaintDC dc(this); // 用于绘制的设备上下文

		SendMessage(WM_ICONERASEBKGND, reinterpret_cast<WPARAM>(dc.GetSafeHdc()), 0);

		// 使图标在工作区矩形中居中
		int cxIcon = GetSystemMetrics(SM_CXICON);
		int cyIcon = GetSystemMetrics(SM_CYICON);
		CRect rect;
		GetClientRect(&rect);
		int x = (rect.Width() - cxIcon + 1) / 2;
		int y = (rect.Height() - cyIcon + 1) / 2;

		// 绘制图标
		dc.DrawIcon(x, y, m_hIcon);
	}
	else
	{
		CDialogEx::OnPaint();
	}
}

//当用户拖动最小化窗口时系统调用此函数取得光标
//显示。
HCURSOR COpticalCenterToolDlg::OnQueryDragIcon()
{
	return static_cast<HCURSOR>(m_hIcon);
}



void COpticalCenterToolDlg::OnBnClickedButton1()
{
	// TODO: 在此添加控件通知处理程序代码
	if(!ValidateInput())
	{
		MessageBox(_T("Invalid input"));
		return;
	}
	TCHAR szFilter[] = _T("Bitmap(*.bmp)|*.bmp|AllFile(*.bmp)|*.bmp||"); 
	CFileDialog dlg(TRUE,_T("Choose the image path"),NULL, 0, szFilter, this);
	m_strImagePath	=	"";
	if(IDOK == dlg.DoModal())
	{
		m_strImagePath	=	dlg.GetPathName();
	}
	CalcOC(m_strImagePath);
}

BOOL COpticalCenterToolDlg::ValidateInput()
{
	m_nOCX = m_nOCY = -1;
	CString tmp;
	((CEdit*)GetDlgItem(IDC_EDIT_BRIGHTNESS_THRESHOLD))->GetWindowText(tmp.GetBuffer(255),255);
	m_nBrightnessThreshold = atoi(CT2A(tmp.GetBuffer(0)));
	((CEdit*)GetDlgItem(IDC_EDIT_CRITERIA_X))->GetWindowText(tmp.GetBuffer(0),255);
	m_nCriteriaX = atoi(CT2A(tmp.GetBuffer(0)));
	((CEdit*)GetDlgItem(IDC_EDIT_CRITERIA_Y))->GetWindowText(tmp.GetBuffer(0),255);
	m_nCriteriaY = atoi(CT2A(tmp.GetBuffer(0)));
	if(m_nBrightnessThreshold<=0 || m_nBrightnessThreshold >100||
		m_nCriteriaX <= 0 || 
		m_nCriteriaY <= 0 )
		return FALSE;

	return TRUE;
}

BOOL COpticalCenterToolDlg::CalcOC(CString strImagePath)
{
	if(strImagePath == "")
		return FALSE;
	//load buffer from BMP
	unsigned char *pY = 0;
	int minY,maxY;
	if(!LoadBMP(strImagePath,m_nImageWidth,m_nImageHeight,pY,minY,maxY))
		return FALSE;
	//get histogram and display
	//int nTargetY = m_nBrightnessThreshold * 255 /100;
	int nTargetY = m_nBrightnessThreshold * (maxY - minY)/100 + minY;
	int x = 0,y = 0;
	int count = 0;
	for(int i = 0;i<m_nImageWidth * m_nImageHeight;i++)
		if(abs(pY[i] - nTargetY) <= 20)
		{
			count++;
			x += i%m_nImageWidth;
			y += i/m_nImageWidth;
		}
	CString strOCX = _T("N/A"),strOCY = _T("N/A");
	if(x && y && count)
	{
		m_nOCX = x / count - m_nImageWidth/2;
		m_nOCY = y / count - m_nImageHeight/2;
		strOCX.Format(_T("%d"),m_nOCX);
		strOCY.Format(_T("%d"),m_nOCY);
	}
	((CEdit*)GetDlgItem(IDC_EDIT_OC_X))->SetWindowText(strOCX);
	((CEdit*)GetDlgItem(IDC_EDIT_OC_Y))->SetWindowText(strOCY);
	if(pY)
		free(pY);
	return TRUE;
}

BOOL COpticalCenterToolDlg::LoadBMP(CString strImagePath, int &nImageWidth, int &nImageHeight, unsigned char *&pY,int &_min, int &_max)
{
	FILE* file = _tfopen(strImagePath, _T("rb"));
	if (file)
	{
		// 填充图像缓冲区
		fseek(file, 0, SEEK_END);
		DWORD size = ftell(file);
		fseek(file, 0, SEEK_SET);
		BYTE* data = (BYTE*)ZeroMemory(malloc(size), size);
		fread(data, 1, size, file);

		// 将BYTE*转换为HBITMAP
		BITMAPFILEHEADER* pbmh = (BITMAPFILEHEADER*)data;
		if (pbmh->bfType == 0x4D42)
		{
			BYTE* pbits = data + sizeof(BITMAPFILEHEADER);
			BITMAPINFO* pbmi = (BITMAPINFO*)pbits;
			BITMAPINFO bmi = {0};
			bmi.bmiHeader.biSize		= sizeof(bmi.bmiHeader);
			bmi.bmiHeader.biBitCount	= 24;
			bmi.bmiHeader.biCompression	= BI_RGB;
			bmi.bmiHeader.biPlanes		= 1;
			bmi.bmiHeader.biSizeImage	= pbmi->bmiHeader.biSizeImage;
			nImageWidth = bmi.bmiHeader.biWidth		= pbmi->bmiHeader.biWidth;
			nImageHeight = bmi.bmiHeader.biHeight		= pbmi->bmiHeader.biHeight;
			pY = (unsigned char*)malloc(nImageHeight * nImageWidth * sizeof(unsigned char));
			COLORREF* bmbf = NULL;
			HBITMAP hBitmap = CreateDIBSection(NULL, &bmi, DIB_RGB_COLORS, (void**)&bmbf, NULL, 0);
			_min = 255;_max = 0;
			if (bmbf)
			{
				pbits += sizeof(BITMAPINFO);
				for(int y = 0; y < bmi.bmiHeader.biHeight; ++y)
				{
					int pos = bmi.bmiHeader.biWidth * y;
					int inx = bmi.bmiHeader.biWidth * 3 * y;
					for(int x = 0; x < bmi.bmiHeader.biWidth; ++x, inx += 3, ++pos)
					{
						//bmbf[pos] = RGB(pbits[inx + 2], pbits[inx], pbits[inx + 1]);
						//Y = 0.299R + 0.587G + 0.114B
						pY[inx/3]	=	int(0.299 * pbits[inx + 2] + 0.587 * pbits[inx] + 0.114 * pbits[inx + 1]);
						_min = min(_min,pY[inx/3]);
						_max = max(_max,pY[inx/3]);
					}
				}
			}
		}

		// 释放资源
		free(data);
		fclose(file);
	}
	else
		return FALSE;
	return TRUE;
}