#include "Window.h"

namespace CodeByte::Windows
{
	LRESULT Window::HandleMSG(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam)
	{
		switch (msg)
		{
		case WM_CLOSE:
			PostQuitMessage(0);
			return 0;
		}

		return DefWindowProc(hwnd, msg, lparam, wparam);
	}
	Window::Window(int width, int heigth, LPCWSTR wname)
		: hInst(GetModuleHandle(nullptr))
	{
		wc.cbClsExtra = 0;
		wc.cbSize = sizeof(wc);
		wc.cbWndExtra = 0;
		wc.hInstance = GetInstance();
		wc.lpszClassName = GetName();
		wc.lpfnWndProc = HandleMSG;
		wc.hbrBackground = nullptr;
		wc.hCursor = nullptr;
		wc.hIcon = nullptr;
		wc.hIconSm = nullptr;
		wc.style = CS_OWNDC;
		wc.lpszMenuName = nullptr;
		HRESULT hr = RegisterClassEx(&wc);
		CB_LOG_HR("Could not register Class", hr);
		RECT wr;
		wr.left = 100;
		wr.right = width + wr.left;
		wr.top = 100;
		wr.bottom = heigth + wr.top;
		hr = AdjustWindowRect(&wr, WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU , FALSE);
		CB_LOG_HR("Could not adjust rect", hr);
		hwnd = CreateWindow(
			GetName(), wname,
			WS_CAPTION | WS_MINIMIZEBOX | WS_SYSMENU,
			CW_USEDEFAULT, CW_USEDEFAULT, wr.right - wr.left, wr.bottom - wr.top,
			nullptr, nullptr, GetInstance(), nullptr

		);

		ShowWindow(hwnd, SW_SHOWDEFAULT);
		
	}
	Window::~Window()
	{
		DestroyWindow(hwnd);
		UnregisterClass(GetName(), hInst);
	}

	std::optional<int> Window::PMessage()
	{
		MSG msg;

		while (PeekMessage(&msg, nullptr, 0, 0, PM_REMOVE))
		{
			if (msg.message == WM_QUIT)
			{
				return msg.wParam;
			}

			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
		return {};
	}


}
