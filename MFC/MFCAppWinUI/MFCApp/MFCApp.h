
// MFCApp.h : main header file for the MFCApp application
//
#pragma once

#ifndef __AFXWIN_H__
	#error "include 'pch.h' before including this file for PCH"
#endif

#include "resource.h"       // main symbols

//TODO STEP 2: Start
//Using winrt namespaces
using namespace winrt;
using namespace Windows::UI;
using namespace Windows::UI::Composition;
using namespace Windows::UI::Xaml::Hosting;
using namespace Windows::Foundation::Numerics;
using namespace Windows::UI::Xaml::Controls;
//TODO STEP 2: End
// CMFCAppApp:
// See MFCApp.cpp for the implementation of this class
//

class CMFCAppApp : public CWinAppEx
{
public:
	CMFCAppApp() noexcept;
	winrt::MyApp::App hostApp{ nullptr };

// Overrides
public:
	virtual BOOL InitInstance();
	virtual int ExitInstance();

// Implementation
	UINT  m_nAppLook;
	BOOL  m_bHiColorIcons;

	virtual void PreLoadState();
	virtual void LoadCustomState();
	virtual void SaveCustomState();

	afx_msg void OnAppAbout();
	DECLARE_MESSAGE_MAP()
};

extern CMFCAppApp theApp;
