#pragma once


// CLSLADialog-Dialog

class CLSLADialog : public CDialogEx
{
	DECLARE_DYNAMIC(CLSLADialog)

public:
	CLSLADialog(CWnd* pParent = nullptr);   // Standardkonstruktor
	virtual ~CLSLADialog();

// Dialogfelddaten
#ifdef AFX_DESIGN_TIME
	enum { IDD = IDD_DIALOG1 };
#endif

protected:
	virtual void DoDataExchange(CDataExchange* pDX);    // DDX/DDV-Unterstützung

	DECLARE_MESSAGE_MAP()
	double lStaerke;
public:
	afx_msg void OnCbnSelchangeCombo1();
	virtual BOOL OnInitDialog();
protected:
	CComboBox comboBox;
	CString comboWert;
public:
	double getLstaerke(void)const;
	CString getComboWert(void)const;
};
