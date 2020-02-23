
// OpticalCenterToolDlg.h : 头文件
//

#pragma once


// COpticalCenterToolDlg 对话框
class COpticalCenterToolDlg : public CDialogEx
{
// 构造
public:
	COpticalCenterToolDlg(CWnd* pParent = NULL);	// 标准构造函数

// 对话框数据
	enum { IDD = IDD_OPTICALCENTERTOOL_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV 支持
private:
	CString m_strImagePath;
	int m_nCriteriaX,m_nCriteriaY;
	int m_nBrightnessThreshold;
	BOOL ValidateInput();
	BOOL CalcOC(CString strImagePath);
	int m_nImageWidth,m_nImageHeight;
	int m_nOCX,m_nOCY;
	BOOL LoadBMP(CString strImagePath, int &nImageWidth, int &nImageHeight, unsigned char *&pY, int &min, int &max);
// 实现
protected:
	HICON m_hIcon;

	// 生成的消息映射函数
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
};
