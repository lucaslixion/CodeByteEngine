#pragma once

#include "Window.h"

namespace CodeByte::Windows
{
	class App
	{
	public:
		App();
		virtual ~App();
		virtual int Go();
		virtual VOID Draw();
		virtual VOID Update();
		virtual VOID Begin();
	protected:
		Window* wnd;
	};
}

