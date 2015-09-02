// DXUTWindow.cpp : implementation file
//

#include "stdafx.h"
#include "MFC.DXUT.h"
#include "DXUTWindow.h"
#include "SimpleBezier.h"


// CDXUTWindow

IMPLEMENT_DYNAMIC(CDXUTWindow, CWnd)

CDXUTWindow::CDXUTWindow()
{

}

CDXUTWindow::~CDXUTWindow()
{
}


BEGIN_MESSAGE_MAP(CDXUTWindow, CWnd)
	ON_WM_DESTROY()
	ON_WM_CREATE()
	ON_WM_MOUSEMOVE()
END_MESSAGE_MAP()



// CDXUTWindow message handlers



void CDXUTWindow::DXUTInitWindow(){
	SimpleBezier::DXUTInitWindow( m_hWnd );
}


BOOL CDXUTWindow::PreTranslateMessage( MSG* pMsg )
{
	// TODO: Add your specialized code here and/or call the base class
	DXUTStaticWndProc( pMsg->hwnd, pMsg->message,
		pMsg->wParam, pMsg->lParam );


	return CWnd::PreTranslateMessage( pMsg );
}



void CDXUTWindow::PreSubclassWindow()
{
	// TODO: Add your specialized code here and/or call the base class

	DXUTInitWindow();

	CWnd::PreSubclassWindow();
}


void CDXUTWindow::OnDestroy()
{
	CWnd::OnDestroy();

	// TODO: Add your message handler code here
}


int CDXUTWindow::OnCreate( LPCREATESTRUCT lpCreateStruct )
{
	if( CWnd::OnCreate( lpCreateStruct ) == -1 )
		return -1;

	// TODO:  Add your specialized creation code here
	DXUTInitWindow();

	return 0;
}

LRESULT CDXUTWindow::Render()
{
	DXUTRender3DEnvironment();
	return 0;
}

void CDXUTWindow::OnMouseMove( UINT nFlags, CPoint point )
{
	// TODO: Add your message handler code here and/or call default

	SetFocus();

	CWnd::OnMouseMove( nFlags, point );
}
