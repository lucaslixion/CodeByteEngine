#include <Windows.h>

#include "App.h"
#include "Graphics.h"

class Sandbox : CodeByte::Windows::App
{
public:

	Sandbox()
	{
		system("copy_folder.bat");
		wnd->CreateWin(800,800,L"SandBox");
		Begin();
	}
	virtual ~Sandbox() = default;
	virtual VOID Draw() override
	{
		const double c = sin(timer.Peek()) / 2.f + 0.5f;
		Ren2D->ClearBuffer(CodeByte::Vector::Vec4(c, c, 1.0f, 1.0f));
		Ren2D->CreateShaders(wnd->hwnd,L"Base.hlsl");
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

