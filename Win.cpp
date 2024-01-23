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
		std::chrono::high_resolution_clock::time_point startTime = std::chrono::high_resolution_clock::now();

		if (!game.hasWrittenfirstMenuTxt && game.canAccessFunction)
		{
			game.hasWrittenfirstMenuTxt = true;
			std::thread([](Renderer* renderer) 
			{ 
					UI::ShowTextUI("PRESS SPACE TO START", renderer->bufferWidth / 2, 200, renderer->bufferWidth / 3, 3, UI::startUIPositionValues, renderer);
				/*int size = (renderer->bufferWidth / 2 - (20 * 2)) / (20 * 6);

				UI::startUIPositionValues[1] = 7 * size;
				UI::startUIPositionValues[0] = (20 * (6 * size + 2));

				renderer->DrawExpression("PRESS SPACE TO START", renderer->bufferWidth / 2 - UI::startUIPositionValues[0] / 2, 200, size, 2);*/
			}, &game.renderer).detach();
		}

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

		//Render the game
		std::thread([hdc](bool* canAccessFunction) 
			{ 
				StretchDIBits(hdc, 0, 0, game.renderer.bufferWidth, game.renderer.bufferHeight, 0, 0, game.renderer.bufferWidth, game.renderer.bufferHeight, game.renderer.bufferMemory, &game.renderer.bufferBitInfo, DIB_RGB_COLORS, SRCCOPY); 
			}, &game.canAccessFunction).join();
		
		std::chrono::high_resolution_clock::time_point endTime = std::chrono::high_resolution_clock::now();

		game.deltaTime = std::chrono::duration<float>(endTime - startTime).count();
	}

	Sleep(2000);
}