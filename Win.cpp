#include <windows.h>
#include <malloc.h>
#include <thread>
#include <chrono>
#include "Game.h"
#include "Input.h"

Game game;
int startWindowWidth = 1280;
int startWidnowHeight = 720;

LRESULT WindowCallBack(HWND hWnd, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
	LRESULT result{};
	result = DefWindowProc(hWnd, uMsg, wParam, lParam);

	if(uMsg == WM_CLOSE || uMsg == WM_DESTROY)
	{
		game.isGameRunning = false;
		result = 0;
	}

	else if (uMsg == WM_SIZE)
	{
		std::thread([hWnd]() { game.AdaptGameForNewScreenSize(hWnd); }).detach();
	}
	
	else if (uMsg == WM_CREATE)
	{
		//Initialize objects for the game
		std::thread([hWnd]() { game.InitializeObjects(); }).detach();

		//load main menu screen
	}

	else if (uMsg == WM_KEYDOWN || uMsg == WM_KEYUP)
	{
		Input::key = (unsigned int)wParam;
		Input::isDown = ((lParam & (1 << 31)) == 0);
	}

	return result;
}

int WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
	//Create window class
	WNDCLASS windowClass = WNDCLASS();
	windowClass.style = CS_HREDRAW | CS_VREDRAW;
	windowClass.lpszClassName = L"Game Widnow";
	windowClass.lpfnWndProc = (WNDPROC)WindowCallBack;
	
	//Register window class
	RegisterClass(&windowClass);

	//Create window
	HWND window = CreateWindow(windowClass.lpszClassName, L"Brakeout Copy", WS_OVERLAPPEDWINDOW | WS_MAXIMIZE | WS_VISIBLE, 0, 0, GetSystemMetrics(SM_CXSCREEN), GetSystemMetrics(SM_CYSCREEN), 0, 0, hInstance, 0);

	HDC hdc = GetDC(window);

	Sleep(2000);

	game.isGameRunning = true;

	while (game.isGameRunning)
	{
		LARGE_INTEGER frequency, startTime, endTime;

		QueryPerformanceFrequency(&frequency);

		QueryPerformanceCounter(&startTime);

		void* bufferToRender;

		MSG message;
		while (PeekMessage(&message, window, 0, 0, PM_REMOVE))
		{
			TranslateMessage(&message);
			DispatchMessage(&message);
		}

		//Gather input
		Input::ProcessInput(&game);

		//Simulate game
		game.ProcessMovableObjects();

		bufferToRender = game.renderer.bufferMemory;

		//Render the game
		StretchDIBits(hdc, 0, 0, game.renderer.bufferWidth, game.renderer.bufferHeight, 0, 0, game.renderer.bufferWidth, game.renderer.bufferHeight, game.renderer.bufferMemory, &game.renderer.bufferBitInfo, DIB_RGB_COLORS, SRCCOPY);
		
		QueryPerformanceCounter(&endTime);

		game.deltaTime = (float)(endTime.QuadPart - startTime.QuadPart) / frequency.QuadPart;
	}

	Sleep(2000);
}