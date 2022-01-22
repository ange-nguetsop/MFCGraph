
// MFCGraph.h: Hauptheaderdatei für die PROJECT_NAME-Anwendung
//

#pragma once

#ifndef __AFXWIN_H__
	#error "'pch.h' vor dieser Datei für PCH einschließen"
#endif

#include "resource.h"		// Hauptsymbole


// CMFCGraphApp:
// Siehe MFCGraph.cpp für die Implementierung dieser Klasse
//

class CMFCGraphApp : public CWinApp
{
public:
	CMFCGraphApp();

// Überschreibungen
public:
	virtual BOOL InitInstance();

// Implementierung

	DECLARE_MESSAGE_MAP()
};

extern CMFCGraphApp theApp;
