#pragma once

#include "Error.h"

#include <Windows.h>
#include <optional>

namespace CodeByte::Windows
{
	class Window
	{
	public:
		Window();
		~Window();
		void CreateWin(int width, int heigth, LPCWSTR wname);
		static std::optional<int> ProcessMSG();
	private:
		static LRESULT CALLBACK HandleMSG(HWND hWnd, UINT msg, WPARAM wparam, LPARAM lparam);
		WNDCLASSEX wc;
		HWND hwnd;
		HINSTANCE hInst;
		static constexpr LPCWSTR name = L"CodeByte";
		HRESULT hr;
	};

}