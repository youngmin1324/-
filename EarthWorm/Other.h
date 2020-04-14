#pragma once
#include <iostream>
#include <conio.h>
#include <Windows.h>
#include <time.h>
#include <stdlib.h>
using namespace std;

#define EXT_KEY			0xE0	//확장키 인식값 
#define KEY_ENTER		13
#define KEY_LEFT		0x4b
#define KEY_RIGHT		0x4d
#define KEY_UP			0x48
#define KEY_DOWN		0x50
#define FOOD_NUM 10
#define BIRD_NUM 5
#define SIZE_X 35 // map size
#define SIZE_Y 25 // map size
#define TOTAL_SIZE_X 35
#define TOTAL_SIZE_Y 25
#define MAX_COUNT 10
#define WARM_SPEED 1
#define BADFOOD 0
#define GOODFOOD 1
#define NOPRESENT 2

int gotoxy(int x, int y);
void removeCursor(void);