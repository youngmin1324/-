#pragma once

#include "Other.h"

int gotoxy(int x, int y)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD pos;
	pos.Y = y;
	pos.X = x;
	SetConsoleCursorPosition(hConsole, pos);
	return 0;
}

void removeCursor(void)
{
	CONSOLE_CURSOR_INFO ConCurInf;
	ConCurInf.dwSize = 50;
	ConCurInf.bVisible = FALSE;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &ConCurInf);
}