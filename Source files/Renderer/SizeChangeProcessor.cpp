#include "Renderer.h"

void Renderer::ProcessSizeChangeAndSetMemory(HWND hWnd)
{
	RECT rect;
	GetClientRect(hWnd, &rect);

	bufferWidth = rect.right - rect.left;
	bufferHeight = rect.bottom - rect.top;
	int bufferSize = bufferHeight * bufferWidth * sizeof(unsigned int);

	if (bufferMemory) free(bufferMemory);
	bufferMemory = malloc(bufferSize);

	SetBitInfo();
}

void Renderer::SetBitInfo()
{
	bufferBitInfo.bmiHeader.biSize = sizeof(bufferBitInfo.bmiHeader);
	bufferBitInfo.bmiHeader.biWidth = bufferWidth;
	bufferBitInfo.bmiHeader.biHeight = bufferHeight;
	bufferBitInfo.bmiHeader.biPlanes = 1;
	bufferBitInfo.bmiHeader.biBitCount = 32;
	bufferBitInfo.bmiHeader.biCompression = BI_RGB;
}