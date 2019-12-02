
// MFCAppView.h : interface of the CMFCAppView class
//

#pragma once

#include "pch.h"

//TODO STEP 2: Start
//Using winrt namespaces
using namespace winrt;
using namespace Windows::UI;
using namespace Windows::UI::Composition;
using namespace Windows::UI::Xaml::Hosting;
using namespace Windows::Foundation::Numerics;
using namespace Windows::UI::Xaml::Controls;
//TODO STEP 2: End

class CMFCAppView : public CView
{
protected: // create from serialization only
	CMFCAppView() noexcept;
	DECLARE_DYNCREATE(CMFCAppView)

// Attributes
public:
	CMFCAppDoc* GetDocument() const;

//TODO STEP 3: Start
private:
	DesktopWindowXamlSource _desktopWindowXamlSource{ nullptr };
	WindowsXamlManager winxamlmanager = WindowsXamlManager{ nullptr };
	
	RelativePanel xamlContainer = RelativePanel{ nullptr };
	TextBlock tb = TextBlock{ nullptr };
	Image image = Image{ nullptr };
	InkCanvas ic = InkCanvas{ nullptr };
	InkToolbar it = InkToolbar{ nullptr };

public:
	void AdjustLayout();
//TODO STEP 3: End

// Overrides
public:
	virtual void OnDraw(CDC* pDC);  // overridden to draw this view
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
protected:
	virtual BOOL OnPreparePrinting(CPrintInfo* pInfo);
	virtual void OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo);
	virtual void OnEndPrinting(CDC* pDC, CPrintInfo* pInfo);

// Implementation
public:
	virtual ~CMFCAppView();
#ifdef _DEBUG
	virtual void AssertValid() const;
	virtual void Dump(CDumpContext& dc) const;
#endif

protected:

// Generated message map functions
protected:
	afx_msg void OnFilePrintPreview();
	afx_msg void OnRButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnContextMenu(CWnd* pWnd, CPoint point);
	DECLARE_MESSAGE_MAP()
public:
	afx_msg void OnSize(UINT nType, int cx, int cy);
	afx_msg void OnClose();
};

#ifndef _DEBUG  // debug version in MFCAppView.cpp
inline CMFCAppDoc* CMFCAppView::GetDocument() const
   { return reinterpret_cast<CMFCAppDoc*>(m_pDocument); }
#endif

