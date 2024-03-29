#include "UI.h"

const char* UI::characters[27] =
{
	//letters
	"A@    @\n@    @\n@    @\n@@@@@@\n@    @\n@    @\n@@@@@@",
	"P@     \n@     \n@     \n@@@@@@\n@    @\n@    @\n@@@@@@",
	"R@    @\n@   @ \n@  @  \n@@@@@@\n@    @\n@    @\n@@@@@@",
	"E@@@@@@\n@     \n@     \n@@@@@@\n@     \n@     \n@@@@@@",
	"S@@@@@@\n     @\n     @\n@@@@@@\n@     \n@     \n@@@@@@",
	"C@@@@@@\n@     \n@     \n@     \n@     \n@     \n@@@@@@",
	"T  @@  \n  @@  \n  @@  \n  @@  \n  @@  \n  @@  \n@@@@@@",
	"O@@@@@@\n@    @\n@    @\n@    @\n@    @\n@    @\n@@@@@@",
	"U@@@@@@\n@    @\n@    @\n@    @\n@    @\n@    @\n@    @",
	"L@@@@@@\n@     \n@     \n@     \n@     \n@     \n@     ",
	"N@    @\n@   @@\n@  @ @\n@  @ @\n@ @  @\n@ @  @\n@@   @",
	"Y  @@  \n  @@  \n  @@  \n  @@  \n @  @ \n@    @\n@    @",
	":      \n  @@  \n  @@  \n      \n  @@  \n  @@  \n      ",
	"W@@  @@\n@ @@ @\n@ @@ @\n@ @@ @\n@    @\n@    @\n@    @",
	"I  @@  \n  @@  \n  @@  \n  @@  \n  @@  \n  @@  \n  @@  ",
	"V  @@  \n @  @ \n@    @\n@    @\n@    @\n@    @\n@    @",
	//numbers
	"0@@@@@@\n@    @\n@    @\n@    @\n@    @\n@    @\n@@@@@@",
	"1     @\n     @\n     @\n     @\n  @  @\n   @ @\n    @@",
	"2@@@@@@\n@     \n@     \n@@@@@@\n     @\n     @\n@@@@@@",
	"3@@@@@@\n     @\n     @\n@@@@@@\n     @\n     @\n@@@@@@",
	"4     @\n     @\n     @\n@@@@@@\n@    @\n@    @\n@     ",
	"5@@@@@@\n     @\n     @\n@@@@@@\n@     \n@     \n@@@@@@",
	"6@@@@@@\n@    @\n@    @\n@@@@@@\n@     \n@     \n@@@@@@",
	"7 @    \n  @   \n   @  \n   @  \n     @\n     @\n@@@@@@",
	"8@@@@@@\n@    @\n@    @\n@@@@@@\n@    @\n@    @\n@@@@@@",
	"9@@@@@@\n     @\n     @\n@@@@@@\n@    @\n@    @\n@@@@@@",
	//heart
	"<  @@  \n @@@@ \n@@@@@@\n@@@@@@\n@@@@@@\n@@  @@\n @  @ ",
};

const char* UI::playerLivesToTxt[3] = { "<", "<<" ,"<<<" };

int* UI::startUIPositionValues = new int[2] {0, 0};
int* UI::finishGameUIPositionValues = new int[2] {0, 0};
int* UI::scoreUIPositionValues = new int[2] {0, 0};
int* UI::heartsUIPositionValues = new int[2] {0, 0};