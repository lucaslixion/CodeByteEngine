#pragma once

#include "Window.h"
#include "Timer.h"

namespace CodeByte::Windows
{
	class App
	{
	public:
		App();
		virtual ~App();
		int Go();
		virtual VOID Draw();
		virtual VOID Update();
		virtual VOID Begin();
		virtual VOID FixedUpdate();
	protected:
		Window* wnd;
		CodeByte::Util::Timer timer;
		int FPS;
		const double FrameSpeed;
		std::chrono::system_clock::time_point startTime;
	};

}

