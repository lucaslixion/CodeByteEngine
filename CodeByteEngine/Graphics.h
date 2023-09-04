#pragma once

#include "Window.h"
#include "Timer.h"
#include "Vec4.h"
#include <Windows.h>
#include <d3d11.h>
#include <d3dcompiler.h>

#include <wrl.h>

namespace wrl = Microsoft::WRL;
namespace CodeByte::Graphics
{
	class Renderer2d
	{
	public:
		Renderer2d(HWND hwnd);
		~Renderer2d();
		void ClearBuffer(Vector::Vec4 v);
		void Present();
		void CreateShaders(HWND hwnd, LPCWSTR shadName);
		void DrawTrig();
	private:
		wrl::ComPtr<ID3D11Device> pDevice;
		wrl::ComPtr<IDXGISwapChain> pSwap;
		wrl::ComPtr<ID3D11DeviceContext> pContext;
		wrl::ComPtr<ID3D11RenderTargetView> pTarget;
		wrl::ComPtr<ID3DBlob> vs_blob;
		wrl::ComPtr<ID3DBlob> ps_blob;
		wrl::ComPtr<ID3DBlob> err_blob;
		HRESULT hr;
		LPCWSTR base = L"C:\\dev\\CodeByteEngine\\bin\\Release-windows-x86_64\\Sandbox\\";

	};
}

