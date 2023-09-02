#pragma once
#include <Windows.h>
#include <string>


namespace CodeByte::Util
{
	class ErrorLogger
	{
	public:
		static void Log(std::string message);
		static void Log(HRESULT hr, std::string message);
	};
	
}

#define CB_LOG(message) {CodeByte::Util::ErrorLogger{}.Log(message);}
#define CB_LOG_HR(message,hr) {if (FAILED(hr)) CB_LOG(message);}