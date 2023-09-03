#include "Window.h"

namespace CodeByte::Windows
{
	Window::Window()	
		: hInst(GetModuleHandle(nullptr)), hwnd(nullptr)
	{
		wc.cbSize = sizeof(wc);
		wc.hInstance = hInst;
		wc.lpszClassName = name;
		wc.cbClsExtra = 0;
		wc.cbWndExtra = 0;
		wc.hbrBackground = nullptr;
		wc.hCursor = nullptr;
		wc.hIcon = nullptr;
		wc.hIconSm = nullptr;
		wc.lpfnWndProc = HandleMSG;
		wc.lpszMenuName = nullptr;
		wc.style = CS_OWNDC;

		hr = RegisterClassEx(&wc);
		CB_LOG_HR("Could Not Register Class CodeByte Engine", hr);
	}
	Window::~Window()
	{
		UnregisterClass(name, hInst);
		DestroyWindow(hwnd);
	}

	void Window::CreateWin(int width, int heigth, LPCWSTR wname)
	{
		RECT wr;
		wr.left = 100;
		wr.right = width + wr.left;
		wr.top = 100;
		wr.bottom = heigth + wr.top;
		CB_LOG_HR("Could Not Change Window Ajusting",AdjustWindowRect(&wr, WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU, FALSE));
		hwnd = CreateWindow(
			name, wname,
			WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU,
			CW_USEDEFAULT, CW_USEDEFAULT, wr.right - wr.left, wr.bottom - wr.top,
			nullptr, nullptr,hInst,nullptr 
		);
		ShowWindow(hwnd, SW_SHOWDEFAULT);
	}

	std::optional<int> Window::ProcessMSG()
	{
		MSG msg;
		while (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT)
			{
				return (int)msg.wParam;
			}
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		return {};
	}

	LRESULT Window::HandleMSG(HWND hWnd, UINT msg, WPARAM wparam, LPARAM lparam)
	{
		switch (msg)
		{
		case WM_DESTROY:
			PostQuitMessage(0);
			return 0;
		}

		return DefWindowProc(hWnd, msg, wparam, lparam);
	}


}
