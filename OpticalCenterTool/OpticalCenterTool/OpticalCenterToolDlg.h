
// OpticalCenterToolDlg.h : ͷ�ļ�
//

#pragma once


// COpticalCenterToolDlg �Ի���
class COpticalCenterToolDlg : public CDialogEx
{
// ����
public:
	COpticalCenterToolDlg(CWnd* pParent = NULL);	// ��׼���캯��

// �Ի�������
	enum { IDD = IDD_OPTICALCENTERTOOL_DIALOG };

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV ֧��
private:
	CString m_strImagePath;
	int m_nCriteriaX,m_nCriteriaY;
	int m_nBrightnessThreshold;
	BOOL ValidateInput();
	BOOL CalcOC(CString strImagePath);
	int m_nImageWidth,m_nImageHeight;
	int m_nOCX,m_nOCY;
	BOOL LoadBMP(CString strImagePath, int &nImageWidth, int &nImageHeight, unsigned char *&pY, int &min, int &max);
// ʵ��
protected:
	HICON m_hIcon;

	// ���ɵ���Ϣӳ�亯��
	virtual BOOL OnInitDialog();
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnBnClickedButton1();
};
