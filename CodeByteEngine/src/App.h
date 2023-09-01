#pragma once
#include "Windows/Window.h"

namespace CodeByte::App
{
	class App
	{
	public:
		App();
		int Run();
	private:
		CodeByte::Windows::Window wnd;
		VOID doFrame();
	};
}

