
// MFCAppView.cpp : implementation of the CMFCAppView class
//

#include "pch.h"
#include "framework.h"
// SHARED_HANDLERS can be defined in an ATL project implementing preview, thumbnail
// and search filter handlers and allows sharing of document code with that project.
#ifndef SHARED_HANDLERS
#include "MFCApp.h"
#endif

#include "MFCAppDoc.h"
#include "MFCAppView.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#endif


// CMFCAppView

IMPLEMENT_DYNCREATE(CMFCAppView, CView)

BEGIN_MESSAGE_MAP(CMFCAppView, CView)
	// Standard printing commands
	ON_COMMAND(ID_FILE_PRINT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_DIRECT, &CView::OnFilePrint)
	ON_COMMAND(ID_FILE_PRINT_PREVIEW, &CMFCAppView::OnFilePrintPreview)
	ON_WM_CONTEXTMENU()
	ON_WM_RBUTTONUP()
	ON_WM_SIZE()
	ON_WM_CLOSE()
END_MESSAGE_MAP()

// CMFCAppView construction/destruction

CMFCAppView::CMFCAppView() noexcept
{
	// TODO: add construction code here
	
}

CMFCAppView::~CMFCAppView()
{
	if (_desktopWindowXamlSource != nullptr)
	{
		_desktopWindowXamlSource.Close();
		_desktopWindowXamlSource = nullptr;
	}
}

void CMFCAppView::AdjustLayout()
{
	if (_desktopWindowXamlSource != nullptr)
	{
		auto interop = _desktopWindowXamlSource.as<IDesktopWindowXamlSourceNative>();
		HWND xamlHostHwnd = NULL;
		check_hresult(interop->get_WindowHandle(&xamlHostHwnd));

		RECT windowRect;
		GetWindowRect(&windowRect);
		::SetWindowPos(xamlHostHwnd, NULL, 0, 0, windowRect.right - windowRect.left, windowRect.bottom - windowRect.top, SWP_SHOWWINDOW);
	}
}

BOOL CMFCAppView::PreCreateWindow(CREATESTRUCT& cs)
{
	// TODO: Modify the Window class or styles here by modifying
	//  the CREATESTRUCT cs

	return CView::PreCreateWindow(cs);
}

// CMFCAppView drawing

void CMFCAppView::OnDraw(CDC* /*pDC*/)
{
	CMFCAppDoc* pDoc = GetDocument();
	ASSERT_VALID(pDoc);
	if (!pDoc)
		return;
	// TODO: add draw code for native data here
	if (_desktopWindowXamlSource == nullptr)
	{
		_desktopWindowXamlSource = DesktopWindowXamlSource{};
		auto interop = _desktopWindowXamlSource.as<IDesktopWindowXamlSourceNative>();
		check_hresult(interop->AttachToWindow(GetSafeHwnd()));

		HWND xamlHostHwnd = NULL;
		check_hresult(interop->get_WindowHandle(&xamlHostHwnd));

		_treeViewUserControl = winrt::MyApp::TreeViewUserControl();
		_desktopWindowXamlSource.Content(_treeViewUserControl);

		RECT windowRect;
		GetWindowRect(&windowRect);
		::SetWindowPos(xamlHostHwnd, NULL, 0, 0, windowRect.right - windowRect.left, windowRect.bottom - windowRect.top, SWP_SHOWWINDOW);

	}
}


// CMFCAppView printing

void CMFCAppView::OnFilePrintPreview()
{
#ifndef SHARED_HANDLERS
	AFXPrintPreview(this);
#endif
}

BOOL CMFCAppView::OnPreparePrinting(CPrintInfo* pInfo)
{
	// default preparation
	return DoPreparePrinting(pInfo);
}

void CMFCAppView::OnBeginPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add extra initialization before printing
}

void CMFCAppView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	// TODO: add cleanup after printing
}

void CMFCAppView::OnRButtonUp(UINT /* nFlags */, CPoint point)
{
	ClientToScreen(&point);
	OnContextMenu(this, point);
}

void CMFCAppView::OnContextMenu(CWnd* /* pWnd */, CPoint point)
{
#ifndef SHARED_HANDLERS
	theApp.GetContextMenuManager()->ShowPopupMenu(IDR_POPUP_EDIT, point.x, point.y, this, TRUE);
#endif
}


// CMFCAppView diagnostics

#ifdef _DEBUG
void CMFCAppView::AssertValid() const
{
	CView::AssertValid();
}

void CMFCAppView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}

CMFCAppDoc* CMFCAppView::GetDocument() const // non-debug version is inline
{
	ASSERT(m_pDocument->IsKindOf(RUNTIME_CLASS(CMFCAppDoc)));
	return (CMFCAppDoc*)m_pDocument;
}
#endif //_DEBUG


void CMFCAppView::OnSize(UINT nType, int cx, int cy)
{
	CView::OnSize(nType, cx, cy);
	AdjustLayout();
}


void CMFCAppView::OnClose()
{
	// TODO: Add your message handler code here and/or call default
	
	CView::OnClose();
	
}

