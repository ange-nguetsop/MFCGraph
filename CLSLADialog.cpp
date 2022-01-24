// CLSLADialog.cpp: Implementierungsdatei
//

#include "pch.h"
#include "MFCGraph.h"
#include "CLSLADialog.h"
#include "afxdialogex.h"


// CLSLADialog-Dialog

IMPLEMENT_DYNAMIC(CLSLADialog, CDialogEx)

CLSLADialog::CLSLADialog(CWnd* pParent /*=nullptr*/)
	: CDialogEx(IDD_DIALOG1, pParent)
	, lStaerke(0)
	, comboWert(_T(""))
{

}

CLSLADialog::~CLSLADialog()
{
}

void CLSLADialog::DoDataExchange(CDataExchange* pDX)
{
	CDialogEx::DoDataExchange(pDX);
	DDX_Text(pDX, IDC_EDIT1, lStaerke);
	DDX_Control(pDX, IDC_COMBO2, comboBox);
	DDX_CBString(pDX, IDC_COMBO2, comboWert);
}


BEGIN_MESSAGE_MAP(CLSLADialog, CDialogEx)
	ON_CBN_SELCHANGE(IDC_COMBO1, &CLSLADialog::OnCbnSelchangeCombo1)
END_MESSAGE_MAP()


// CLSLADialog-Meldungshandler


void CLSLADialog::OnCbnSelchangeCombo1()
{

	comboBox.GetLBText(comboBox.GetCurSel(), comboWert);
	UpdateData(FALSE);

}


BOOL CLSLADialog::OnInitDialog()
{
	CDialogEx::OnInitDialog();

	CString str1("PS_SOLID");
	comboBox.AddString(str1);
	CString str2("PS_DASH");
	comboBox.AddString(str2);
	CString str3("PS_DASHDOT");
	comboBox.AddString(str3);
	CString str4("PS_DASHDOTDOT");
	comboBox.AddString(str4);
	CString str5("PS_DOT");
	comboBox.AddString(str5);
	// TODO:  hier zusätzliche Initialisierung hinzufügen.

	return TRUE;  // return TRUE unless you set the focus to a control
				  // AUSNAHME: OCX-Eigenschaftenseite muss FALSE zurückgeben.
}

double CLSLADialog::getLstaerke(void) const
{
	return lStaerke;
}

CString CLSLADialog::getComboWert(void) const
{
	return comboWert;
}
