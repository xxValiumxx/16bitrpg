#include <Windows.h>

#include "Engine.h"


//int WINAPI wWinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, PWSTR pCmdLine, int nCmdShow)
int main()
{
	Engine* engine = new Engine(768, 672);

	engine->Go();
}