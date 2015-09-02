//派生类对象与基类对象共享基类的静态数据成员,所以不能用子类覆盖父类的静态函数
#ifndef __IDXUTD3D11_H__
#define __IDXUTD3D11_H__

#include "DXUT.h"

class DXUTD3D11{
public:
	DXUTD3D11(){}
	~DXUTD3D11(){}
public:
	static void DXUTInitWindow( HWND hWnd );

private:
	static void InitApp(){}
	
private:
	//--------------------------------------------------------------------------------------
	// Reject any D3D11 devices that aren't acceptable by returning false
	//--------------------------------------------------------------------------------------
	static bool CALLBACK IsD3D11DeviceAcceptable( const CD3D11EnumAdapterInfo *AdapterInfo, UINT Output, const CD3D11EnumDeviceInfo *DeviceInfo,
		DXGI_FORMAT BackBufferFormat, bool bWindowed, void* pUserContext );

	//--------------------------------------------------------------------------------------
	// Called right before creating a D3D9 or D3D11 device, allowing the app to modify the device settings as needed
	//--------------------------------------------------------------------------------------
	static bool CALLBACK ModifyDeviceSettings( DXUTDeviceSettings* pDeviceSettings, void* pUserContext );

	//--------------------------------------------------------------------------------------
	// Create any D3D11 resources that aren't dependant on the back buffer
	//--------------------------------------------------------------------------------------
	static HRESULT CALLBACK OnD3D11CreateDevice( ID3D11Device* pd3dDevice, const DXGI_SURFACE_DESC* pBackBufferSurfaceDesc,
		void* pUserContext );

	//--------------------------------------------------------------------------------------
	// Create any D3D11 resources that depend on the back buffer
	//--------------------------------------------------------------------------------------
	static HRESULT CALLBACK OnD3D11ResizedSwapChain( ID3D11Device* pd3dDevice, IDXGISwapChain* pSwapChain,
		const DXGI_SURFACE_DESC* pBackBufferSurfaceDesc, void* pUserContext );

	//--------------------------------------------------------------------------------------
	// Handle updates to the scene.  This is called regardless of which D3D API is used
	//--------------------------------------------------------------------------------------
	static void CALLBACK OnFrameMove( double fTime, float fElapsedTime, void* pUserContext );

	//--------------------------------------------------------------------------------------
	// Render the scene using the D3D11 device
	//--------------------------------------------------------------------------------------
	static void CALLBACK OnD3D11FrameRender( ID3D11Device* pd3dDevice, ID3D11DeviceContext* pd3dImmediateContext,
		double fTime, float fElapsedTime, void* pUserContext );

	//--------------------------------------------------------------------------------------
	// Release D3D11 resources created in OnD3D11ResizedSwapChain 
	//--------------------------------------------------------------------------------------
	static void CALLBACK OnD3D11ReleasingSwapChain( void* pUserContext );

	//--------------------------------------------------------------------------------------
	// Release D3D11 resources created in OnD3D11CreateDevice 
	//--------------------------------------------------------------------------------------
	static void CALLBACK OnD3D11DestroyDevice( void* pUserContext );

	//--------------------------------------------------------------------------------------
	// Handle messages to the application
	//--------------------------------------------------------------------------------------
	static LRESULT CALLBACK MsgProc( HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam,
		bool* pbNoFurtherProcessing, void* pUserContext );

	//--------------------------------------------------------------------------------------
	// Handle key presses
	//--------------------------------------------------------------------------------------
	static void CALLBACK OnKeyboard( UINT nChar, bool bKeyDown, bool bAltDown, void* pUserContext );

	//--------------------------------------------------------------------------------------
	// Handle mouse button presses
	//--------------------------------------------------------------------------------------
	static void CALLBACK OnMouse( bool bLeftButtonDown, bool bRightButtonDown, bool bMiddleButtonDown,
		bool bSideButton1Down, bool bSideButton2Down, int nMouseWheelDelta,
		int xPos, int yPos, void* pUserContext );

	//--------------------------------------------------------------------------------------
	// Call if device was removed.  Return true to find a new device, false to quit
	//--------------------------------------------------------------------------------------
	static bool CALLBACK OnDeviceRemoved( void* pUserContext );

};

#endif