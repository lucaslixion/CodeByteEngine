#include <Windows.h>

#include "App.h"

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
	{}
	virtual VOID Update() override
	{}
	virtual VOID Begin() override
	{}

	virtual int Go() override;
};

int Sandbox::Go()
{
	while (true)
	{
		if (const auto ecode = CodeByte::Windows::Window::ProcessMSG())
		{
			return *ecode;
		}
		Update();
		Draw();
	}
}

int CALLBACK WinMain(
    HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    LPSTR lpCmdLine,
    int nShowCmd)
{
	Sandbox app{};
	return app.Go();
}

