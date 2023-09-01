#pragma once

#define WIN32_LEAN_AND_MEAN

#include <Windows.h>
#include <optional>	

#include "../Util/Error.h"

namespace CodeByte::Windows
{
	class Window
	{
	private:
		WNDCLASSEX wc;
		HWND hwnd;
		HINSTANCE hInst;
		LPCWSTR name = L"CodeByte";
		int width;
		int heigth;
		static LRESULT CALLBACK HandleMSG(HWND hwnd, UINT msg, WPARAM wparam, LPARAM lparam);
	public:
		LPCWSTR GetName() noexcept { return name; }
		HINSTANCE GetInstance() noexcept { return hInst; };
		Window(int width, int heigth, LPCWSTR name);
		~Window();
		static std::optional<int> PMessage();

	};
}