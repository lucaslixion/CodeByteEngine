#include <Windows.h>

#include "App.h"

int WINAPI WinMain(
    HINSTANCE hInstance,
    HINSTANCE hPrevInstance,
    PSTR lpCmdLine,
    int nCmdShow)
{
    CodeByte::App::App app{};
    int out = app.Run();
    return out;
}
