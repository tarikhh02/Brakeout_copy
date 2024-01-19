#define _CRT_SECURE_NO_WARNINGS

#include<windows.h>
#include "Audio.h"

#pragma comment(lib, "winmm.lib")

void Audio::PlaySoundFromPath(const char* soundPath)
{
	int len = strlen(soundPath) + 1;
	
	wchar_t* wSoundPath = new wchar_t[len];

	mbstowcs(wSoundPath, soundPath, len);

	PlaySound(wSoundPath, NULL, SND_FILENAME | SND_ASYNC);
}