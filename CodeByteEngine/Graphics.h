#pragma once

#include "Window.h"
#include "Timer.h"

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
		void ClearBuffer(float red, float green, float blue);
		void Present();
	private:
		wrl::ComPtr<ID3D11Device> pDevice;
		wrl::ComPtr<IDXGISwapChain> pSwap;
		wrl::ComPtr<ID3D11DeviceContext> pContext;
		wrl::ComPtr<ID3D11RenderTargetView> pTarget;

	};
}

