#include <Windows.h>

#include "App.h"
#include "Graphics.h"

class Sandbox : CodeByte::Windows::App
{
public:

	Sandbox()
	{
		wnd->CreateWin(800,800,L"SandBox");
		Begin();
	}
	virtual ~Sandbox() = default;
	virtual VOID Draw() override
	{
		const double c = sin(timer.Peek()) / 2.f + 0.5f;
		Ren2D->ClearBuffer(c, c, 1.f);
		Ren2D->Present();
	}
	virtual VOID Update() override
	{}
	virtual VOID FixedUpdate() override
	{}
	virtual VOID Begin() override
	{
		Ren2D = new CodeByte::Graphics::Renderer2d(wnd->hwnd);
		FPS = 60;
	}
	int run()
	{
		return App::Go();
	}

private:
	CodeByte::Graphics::Renderer2d* Ren2D;
};


int CALLBACK WinMain(
	HINSTANCE hInstance,
	HINSTANCE hPrevInstance,
	LPSTR lpCmdLine,
	int nShowCmd)
{
	Sandbox app{};
	return app.run();
}

