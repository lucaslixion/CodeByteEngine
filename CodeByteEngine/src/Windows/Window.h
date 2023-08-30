#pragma once

#define WIN32_LEAN_AND_MEAN

#include <Windows.h>

namespace CodeByte::Windows
{
	class Window
	{
	private:
		WNDCLASSEX wc;
		HWND hwnd;
		HINSTANCE hInst;
	public:

	};
}