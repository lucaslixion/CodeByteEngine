#include "Graphics.h"

#pragma comment(lib,"d3d11.lib")
#pragma comment(lib,"d3dcompiler.lib")

namespace CodeByte::Graphics
{
	Renderer2d::Renderer2d(HWND hwnd)
	{
		DXGI_SWAP_CHAIN_DESC sd = {};
		sd.BufferDesc.Width = 0;
		sd.BufferDesc.Height = 0;
		sd.BufferDesc.Format = DXGI_FORMAT_B8G8R8A8_UNORM;
		sd.BufferDesc.RefreshRate.Numerator = 0;
		sd.BufferDesc.RefreshRate.Denominator = 0;
		sd.BufferDesc.Scaling = DXGI_MODE_SCALING_UNSPECIFIED;
		sd.BufferDesc.ScanlineOrdering = DXGI_MODE_SCANLINE_ORDER_UNSPECIFIED;
		sd.SampleDesc.Count = 1;
		sd.SampleDesc.Quality = 0;
		sd.BufferUsage = DXGI_USAGE_RENDER_TARGET_OUTPUT;
		sd.BufferCount = 1;
		sd.OutputWindow = hwnd;
		sd.Windowed = TRUE;
		sd.SwapEffect = DXGI_SWAP_EFFECT_DISCARD;
		sd.Flags = 0;

		HRESULT hr = D3D11CreateDeviceAndSwapChain(
			nullptr,
			D3D_DRIVER_TYPE_HARDWARE,
			nullptr,
			0,
			nullptr,
			0,
			D3D11_SDK_VERSION,
			&sd,
			&pSwap,
			&pDevice,
			nullptr,
			&pContext
		);

		CB_LOG_HR("Could Not Init D3D11!", hr);
		wrl::ComPtr<ID3D11Resource> pBackBuffer;
		hr = pSwap->GetBuffer(0, __uuidof(ID3D11Resource), &pBackBuffer);
		CB_LOG_HR("Cannot Get Buffer", hr);
		hr = pDevice->CreateRenderTargetView(pBackBuffer.Get(), nullptr, &pTarget);
		CB_LOG_HR("Cant Create RenderView", hr);
	}

	Renderer2d::~Renderer2d()
	{
		if (pTarget != nullptr)
		{
			pTarget->Release();
		}
		if (pContext != nullptr)
		{
			pContext->Release();
		}
		if (pSwap != nullptr)
		{
			pSwap->Release();
		}
		if (pDevice != nullptr)
		{
			pDevice->Release();
		}
	}

	void Renderer2d::ClearBuffer(Vector::Vec4 v)
	{
		const float color[] = { v.X,v.Y,v.Z,v.W};
		pContext->ClearRenderTargetView(pTarget.Get(), color);
	}
	void Renderer2d::Present()
	{
		pSwap->Present(1u, 0u);
	}
	void Renderer2d::CreateShaders(HWND hwnd,LPCWSTR shadName)
	{
		std::wstring wstr1(base);
		std::wstring wstr2(shadName);

		// Concatenate wstrings
		std::wstring result = wstr1 + wstr2;

		// Convert the concatenated wstring back to LPCWSTR
		LPCWSTR FULL = result.c_str();
		hr = D3DCompileFromFile(
			FULL,
			0,0,
			"vs_main",
			"vs_5_0",
			0,
			0,
			&vs_blob,
			&err_blob);
		CB_LOG_HR("Cant compile VertexShader", hr);
	}
}