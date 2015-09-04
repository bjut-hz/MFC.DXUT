#pragma once


// CDXUTWindow

class CDXUTWindow : public CWnd
{
	DECLARE_DYNAMIC(CDXUTWindow)

public:
	CDXUTWindow();
	virtual ~CDXUTWindow();

	static LRESULT Render();

private:
	void DXUTInitWindow();

protected:
	DECLARE_MESSAGE_MAP()
public:
	virtual BOOL PreTranslateMessage( MSG* pMsg );
	virtual void PreSubclassWindow();
	afx_msg void OnDestroy();
	afx_msg int OnCreate( LPCREATESTRUCT lpCreateStruct );
	afx_msg void OnMouseMove( UINT nFlags, CPoint point );
	afx_msg void OnSize( UINT nType, int cx, int cy );
	afx_msg void OnSizing( UINT fwSide, LPRECT pRect );
};


