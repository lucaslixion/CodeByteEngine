#include "App.h"

CodeByte::App::App::App()
	:wnd(800,800,L"Hello")
{
}

int CodeByte::App::App::Run()
{
	while (true)
	{
		if (const auto ecode = CodeByte::Windows::Window::PMessage())
		{
			return *ecode;
		}
		doFrame();
	}
}

VOID CodeByte::App::App::doFrame()
{
	return;
}
