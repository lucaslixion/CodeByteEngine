#include "App.h"
#include <thread>

using namespace std::chrono;
namespace CodeByte::Windows
{
	App::App()
		: FrameSpeed(1000.f / FPS)
	{
		wnd = new Window();
		timer = CodeByte::Util::Timer();
		startTime = system_clock::now();

	}
	App::~App()
	{
		delete wnd;
	}
	int App::Go()
	{
		while (true)
		{

			auto endTime = system_clock::now();
			duration<double, std::milli> delta = endTime - startTime;
			startTime = endTime;

			auto frameStart = system_clock::now();
			const auto ecode = CodeByte::Windows::Window::ProcessMSG();
			if (ecode)
			{
				return *ecode;
			}
			Update();
			FixedUpdate();
			Draw();
			auto frameEnd = system_clock::now();
			delta = endTime - startTime;
			if (delta.count() < FrameSpeed)
			{	
				Sleep(FrameSpeed - delta.count());
			}
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
	VOID App::FixedUpdate()
	{
		return;
	}
}