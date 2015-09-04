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
	ON_WM_SIZE()
	ON_WM_SIZING()
END_MESSAGE_MAP()



// CDXUTWindow message handlers



void CDXUTWindow::DXUTInitWindow(){
	SimpleBezier::DXUTInitWindow( m_hWnd );
}


BOOL CDXUTWindow::PreTranslateMessage( MSG* pMsg )
{
	// TODO: Add your specialized code here and/or call the base class
	//捕获esc键消息，使得渲染窗口不再响应该消息
	switch( pMsg->message ){
	case WM_KEYDOWN:
		switch( pMsg->wParam ){
		case VK_ESCAPE:
			return CWnd::PreTranslateMessage( pMsg );
		}
	}
	assert(pMsg->hwnd == m_hWnd);
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


void CDXUTWindow::OnSize( UINT nType, int cx, int cy )
{
	CWnd::OnSize( nType, cx, cy );

	// TODO: Add your message handler code here
	DXUTStaticWndProc( m_hWnd, WM_SIZE,
		0, 0 );
}


void CDXUTWindow::OnSizing( UINT fwSide, LPRECT pRect )
{
	CWnd::OnSizing( fwSide, pRect );

	// TODO: Add your message handler code here
}
