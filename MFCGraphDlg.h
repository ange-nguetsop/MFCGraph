
// MFCGraphDlg.h: Headerdatei
//

#pragma once
#include"CGraph.h"


// CMFCGraphDlg-Dialogfeld
class CMFCGraphDlg : public CDialogEx
{
// Konstruktion
public:
	CMFCGraphDlg(CWnd* pParent = nullptr);	// Standardkonstruktor

// Dialogfelddaten
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_MFCGRAPH_DIALOG };
#endif

	protected:
	virtual void DoDataExchange(CDataExchange* pDX);	// DDX/DDV-Unterstützung


// Implementierung
protected:
	HICON m_hIcon;

	// Generierte Funktionen für die Meldungstabellen
	virtual BOOL OnInitDialog();
	afx_msg void OnSysCommand(UINT nID, LPARAM lParam);
	afx_msg void OnPaint();
	afx_msg HCURSOR OnQueryDragIcon();
	DECLARE_MESSAGE_MAP()
protected:

	CGraph g;
public:
	afx_msg void OnBnClickedButton1();
protected:
	double Amplitude;
	double frequence;
	double offset;
	double Xmin;
public:
	double Xmax;
protected:
	double Ymin;
	double Ymax;
public:
	afx_msg void OnBnClickedButton2();
	afx_msg void OnBnClickedButton3();
	afx_msg void OnBnClickedButton4();
};
