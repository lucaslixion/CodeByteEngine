#include "App.h"


namespace CodeByte::Windows
{
	App::App()
	{
		wnd = new Window();
	}
	App::~App()
	{
		delete wnd;
	}
	int App::Go()
	{
		while (true)
		{
			if (const auto ecode = Window::ProcessMSG())
			{
				return *ecode;
			}
			Update();
			Draw();
		}
	}
	VOID App::Draw()
	{
		return;
	}
	VOID App::Update()
	{
		return;
	}
	VOID App::Begin()
	{
		return;
	}
}