#include "DXUTD3D11.h"

void DXUTD3D11::DXUTInitWindow( HWND hWnd ){
	assert( NULL == hWnd );
	LONG lStyle = GetWindowLong( hWnd, GWL_STYLE );
	if( lStyle & WS_TABSTOP )
	{
		SetWindowLong( hWnd, GWL_STYLE, lStyle & ( ~WS_TABSTOP ) );
	}

	// Set general DXUT callbacks
	DXUTSetCallbackFrameMove( OnFrameMove );
	DXUTSetCallbackKeyboard( OnKeyboard );
	DXUTSetCallbackMouse( OnMouse );
	DXUTSetCallbackMsgProc( MsgProc );
	DXUTSetCallbackDeviceChanging( ModifyDeviceSettings );
	DXUTSetCallbackDeviceRemoved( OnDeviceRemoved );

	// Set the D3D11 DXUT callbacks. Remove these sets if the app doesn't need to support D3D11
	DXUTSetCallbackD3D11DeviceAcceptable( IsD3D11DeviceAcceptable );
	DXUTSetCallbackD3D11DeviceCreated( OnD3D11CreateDevice );
	DXUTSetCallbackD3D11SwapChainResized( OnD3D11ResizedSwapChain );
	DXUTSetCallbackD3D11FrameRender( OnD3D11FrameRender );
	DXUTSetCallbackD3D11SwapChainReleasing( OnD3D11ReleasingSwapChain );
	DXUTSetCallbackD3D11DeviceDestroyed( OnD3D11DestroyDevice );

	// Perform any application-level initialization here
	InitApp();

	DXUTInit( true, true, NULL ); // Parse the command line, show msgboxes on error, no extra command line params
	DXUTSetCursorSettings( true, true ); // Show the cursor and clip it when in full screen
	DXUTCreateWindow_s( hWnd );

	RECT rect;
	assert( GetClientRect( hWnd, &rect ) );
	int nWeidth = rect.right - rect.left;
	int nHeight = rect.bottom - rect.top;

	assert( nHeight >0 && nWeidth>0 );
	DXUTCreateDevice( D3D_FEATURE_LEVEL_11_0, true, nWeidth, nHeight );
}

//bool DXUTD3D11::DXUTInitWindowBefore( HWND hWnd ){
//	assert( NULL == hWnd );
//	LONG lStyle = GetWindowLong( hWnd, GWL_STYLE );
//	if( lStyle & WS_TABSTOP )
//	{
//		SetWindowLong( hWnd, GWL_STYLE, lStyle & ( ~WS_TABSTOP ) );
//	}
//
//	// Set general DXUT callbacks
//	DXUTSetCallbackFrameMove( OnFrameMove );
//	DXUTSetCallbackKeyboard( OnKeyboard );
//	DXUTSetCallbackMouse( OnMouse );
//	DXUTSetCallbackMsgProc( MsgProc );
//	DXUTSetCallbackDeviceChanging( ModifyDeviceSettings );
//	DXUTSetCallbackDeviceRemoved( OnDeviceRemoved );
//
//	// Set the D3D11 DXUT callbacks. Remove these sets if the app doesn't need to support D3D11
//	DXUTSetCallbackD3D11DeviceAcceptable( IsD3D11DeviceAcceptable );
//	DXUTSetCallbackD3D11DeviceCreated( OnD3D11CreateDevice );
//	DXUTSetCallbackD3D11SwapChainResized( OnD3D11ResizedSwapChain );
//	DXUTSetCallbackD3D11FrameRender( OnD3D11FrameRender );
//	DXUTSetCallbackD3D11SwapChainReleasing( OnD3D11ReleasingSwapChain );
//	DXUTSetCallbackD3D11DeviceDestroyed( OnD3D11DestroyDevice );
//}
//
//bool DXUTD3D11::DXUTInitWindowEnd( HWND hWnd ){
//	DXUTInit( true, true, NULL ); // Parse the command line, show msgboxes on error, no extra command line params
//	DXUTSetCursorSettings( true, true ); // Show the cursor and clip it when in full screen
//	DXUTCreateWindow_s( hWnd );
//
//	RECT rect;
//	VERIFY( GetClientRect( hWnd, &rect ) );
//	int nWeidth = rect.right - rect.left;
//	int nHeight = rect.bottom - rect.top;
//
//	ASSERT( nHeight >0 && nWeidth>0 );
//	DXUTCreateDevice( D3D_FEATURE_LEVEL_11_0, true, nWeidth, nHeight );
//}

//--------------------------------------------------------------------------------------
// Reject any D3D11 devices that aren't acceptable by returning false
//--------------------------------------------------------------------------------------
bool CALLBACK DXUTD3D11::IsD3D11DeviceAcceptable( const CD3D11EnumAdapterInfo *AdapterInfo, UINT Output, const CD3D11EnumDeviceInfo *DeviceInfo,
	DXGI_FORMAT BackBufferFormat, bool bWindowed, void* pUserContext )
{
	return true;
}

//--------------------------------------------------------------------------------------
// Called right before creating a D3D9 or D3D11 device, allowing the app to modify the device settings as needed
//--------------------------------------------------------------------------------------
bool CALLBACK DXUTD3D11::ModifyDeviceSettings( DXUTDeviceSettings* pDeviceSettings, void* pUserContext )
{
	return true;
}

//--------------------------------------------------------------------------------------
// Create any D3D11 resources that aren't dependant on the back buffer
//--------------------------------------------------------------------------------------
HRESULT CALLBACK DXUTD3D11::OnD3D11CreateDevice( ID3D11Device* pd3dDevice, const DXGI_SURFACE_DESC* pBackBufferSurfaceDesc,
	void* pUserContext )
{
	return S_OK;
}


//--------------------------------------------------------------------------------------
// Create any D3D11 resources that depend on the back buffer
//--------------------------------------------------------------------------------------
HRESULT CALLBACK DXUTD3D11::OnD3D11ResizedSwapChain( ID3D11Device* pd3dDevice, IDXGISwapChain* pSwapChain,
	const DXGI_SURFACE_DESC* pBackBufferSurfaceDesc, void* pUserContext )
{
	return S_OK;
}


//--------------------------------------------------------------------------------------
// Handle updates to the scene.  This is called regardless of which D3D API is used
//--------------------------------------------------------------------------------------
void CALLBACK DXUTD3D11::OnFrameMove( double fTime, float fElapsedTime, void* pUserContext )
{
}


//--------------------------------------------------------------------------------------
// Render the scene using the D3D11 device
//--------------------------------------------------------------------------------------
void CALLBACK DXUTD3D11::OnD3D11FrameRender( ID3D11Device* pd3dDevice, ID3D11DeviceContext* pd3dImmediateContext,
	double fTime, float fElapsedTime, void* pUserContext )
{
	// Clear render target and the depth stencil 
	float ClearColor[ 4 ] = {0.176f, 0.196f, 0.667f, 0.0f};

	ID3D11RenderTargetView* pRTV = DXUTGetD3D11RenderTargetView( );
	ID3D11DepthStencilView* pDSV = DXUTGetD3D11DepthStencilView( );
	pd3dImmediateContext->ClearRenderTargetView( pRTV, ClearColor );
	pd3dImmediateContext->ClearDepthStencilView( pDSV, D3D11_CLEAR_DEPTH, 1.0, 0 );
}


//--------------------------------------------------------------------------------------
// Release D3D11 resources created in OnD3D11ResizedSwapChain 
//--------------------------------------------------------------------------------------
void CALLBACK DXUTD3D11::OnD3D11ReleasingSwapChain( void* pUserContext )
{
}


//--------------------------------------------------------------------------------------
// Release D3D11 resources created in OnD3D11CreateDevice 
//--------------------------------------------------------------------------------------
void CALLBACK DXUTD3D11::OnD3D11DestroyDevice( void* pUserContext )
{
}


//--------------------------------------------------------------------------------------
// Handle messages to the application
//--------------------------------------------------------------------------------------
LRESULT CALLBACK DXUTD3D11::MsgProc( HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam,
	bool* pbNoFurtherProcessing, void* pUserContext )
{
	return 0;
}


//--------------------------------------------------------------------------------------
// Handle key presses
//--------------------------------------------------------------------------------------
void CALLBACK DXUTD3D11::OnKeyboard( UINT nChar, bool bKeyDown, bool bAltDown, void* pUserContext )
{
}


//--------------------------------------------------------------------------------------
// Handle mouse button presses
//--------------------------------------------------------------------------------------
void CALLBACK DXUTD3D11::OnMouse( bool bLeftButtonDown, bool bRightButtonDown, bool bMiddleButtonDown,
	bool bSideButton1Down, bool bSideButton2Down, int nMouseWheelDelta,
	int xPos, int yPos, void* pUserContext )
{
}


//--------------------------------------------------------------------------------------
// Call if device was removed.  Return true to find a new device, false to quit
//--------------------------------------------------------------------------------------
bool CALLBACK DXUTD3D11::OnDeviceRemoved( void* pUserContext )
{
	return true;
}