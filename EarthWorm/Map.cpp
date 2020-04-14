#pragma once

#include "Map.h"

void Map::init() 
{
	this->isOver = false;
	//for (int i = 0; i < SIZE_Y; i++) {
	//	for (int j = 0; j < SIZE_X; j++) {
	//		map1[i][j] = 10;
	//		map2[i][j] = 10;
	//	}
	//}
	// bird 초기화 필요
	//for (int i = 0; i < BIRD_NUM; i++) {
	//b[i].y = 1;
	//b[i].x = 1;
	//}
}
void Map::makeMap() {
	for (int i = 0; i < TOTAL_SIZE_Y; i++) {
		for (int j = 0; j < TOTAL_SIZE_X; j++) {
			if (i == 0 || j == 0 || i == TOTAL_SIZE_Y - 1 || j == TOTAL_SIZE_X - 1) {
				map2[i][j] = -1;
				map1[i][j] = 1;
			}
			else {
				map2[i][j] = -1;
				map1[i][j] = 0;
			}
		}
	}
}

void Map::setMap(int i, int j)
{ // double buffer 
	map2[i][j] = map1[i][j];
}

void Map::print() {
	for (int i = 0; i < SIZE_Y; i++) {
		for (int j = 0; j < SIZE_X; j++) {
			if (map1[i][j] != map2[i][j]) {
				gotoxy(2 * j, i);
				switch (map1[i][j]) {
				case 0:
					printf("  ");
					break;
				case 1:
					printf("▩");
					break;
				case 2:
					printf("○");
					break;
				case 3:
					printf("‡");
					break;
				case 4:
					printf("∞");
					break;
				case 5:
					printf("◎");
					break;
				}
				setMap(i, j);
			}
		}
	}
}
//
//void Map::birdMove() // bird로
//{
//	for (int i = 0; i < 5; i++) {
//		if (this->map1[b[i].y][b[i].x] == 5)
//			this->map1[b[i].y][b[i].x] = 0;
//
//		b[i].x = (b[i].x + rand() % 3 - 1) % SIZE_X;
//		b[i].y = (b[i].y + rand() % 3 - 1) % SIZE_Y;
//
//		if (this->map1[b[i].y][b[i].x] == 0 || this->map1[b[i].y][b[i].x] == 2)
//			this->map1[b[i].y][b[i].x] = 5;
//		else
//			i--;
//	}
//}
//
//void Map::wormMove() 
//{
//	int prev_x = w.body_x[w.length];
//	int prev_y = w.body_y[w.length];
//
//	for (int i = w.length - 1; i >= 0; i--)
//	{
//		w.body_x[i + 1] = w.body_x[i];
//		w.body_y[i + 1] = w.body_y[i];
//	}
//
//	if (w.dir == 1)
//		(w.body_y[0])--;
//	else if (w.dir == 2)
//		(w.body_y[0])++;
//	else if (w.dir == 3)
//		(w.body_x[0])++;
//	else if (w.dir == 4)
//		(w.body_x[0])--;
//
//	map1[prev_y][prev_x] = 0;
//
//	int tmp = map1[w.body_y[0]][w.body_x[0]];
//	map1[w.body_y[0]][w.body_x[0]] = 2;
//
//	for (int i = 1; i <= w.length; i++) {
//		map1[w.body_y[i]][w.body_x[i]] = 2;
//	}
//
//	bumpCheck(tmp);
//}

void Map::makeFood() // food를 계속 생성하게끔, food num까지 
{
	int badfood_count = 0;
	for (int i = 0; i < FOOD_NUM; i++) {
		f[i].state = BADFOOD;
		badfood_count++;
		if (badfood_count > FOOD_NUM / 5)
			f[i].state = GOODFOOD;
		if(i==0)
			f[i].setPos();
		for (int j = 0; j < i; j++) {
			f[i].setPos();
			if (f[j].x == f[i].x&&f[j].y == f[i].y) {
				i--;
				break;
			}
		}
	}
}

void Map::mapUpdate()
{ // 그짓
	int tempMap[SIZE_Y][SIZE_X] = { 0, };
	bool isBirdMoved = false;
	static int frameNum = 0;

	for (int i = 1; i < SIZE_Y - 1; ++i)
	{
		for (int j = 1; j < SIZE_X - 1; ++j)
		{
			if (this->map1[i][j] != 0)
			{
				tempMap[i][j] = this->map1[i][j];
				this->map1[i][j] = 0;
			}
		}
	}

	for (int i = 0; i < BIRD_NUM; ++i)
	{
		//isBirdMoved = false;
		int orX = this->b[i].getX();
		int orY = this->b[i].getY();
		isBirdMoved = this->b[i].move();
		if (isBirdMoved && tempMap[this->b[i].getY()][this->b[i].getX()] == 2 ||
			isBirdMoved && tempMap[this->b[i].getY()][this->b[i].getX()] == 3 ||
			isBirdMoved && tempMap[this->b[i].getY()][this->b[i].getX()] == 4)
		{
			this->b[i].setX(orX);
			this->b[i].setY(orY);
		}

		/*if (isBirdMoved && tempMap[this->b[i].getY()][this->b[i].getX()] != 0)
		{
			b[i].setCount(0);
			i--;
			continue;
		}*/

		/*do
		{
			isBirdMoved = this->b[i].move();
		} while (isBirdMoved && tempMap[this->b[i].getY()][this->b[i].getX()] != 0);*/
		this->map1[this->b[i].getY()][this->b[i].getX()] = 5;
	}
	//printf("bird moved, %d", frameNum);

	for (int i = 0; i < FOOD_NUM; ++i)
	{
		if (this->f[i].state == BADFOOD)
			this->map1[this->f[i].y][this->f[i].x] = 3;
		else if (this->f[i].state == GOODFOOD)
			this->map1[this->f[i].y][this->f[i].x] = 4;
		else if (this->f[i].state == NOPRESENT)
		{
			this->f[i].setPos(); // 상태도 다시 바꿔주기
			srand((unsigned int)time(NULL));
			this->f[i].state = rand() % 2 == BADFOOD ? BADFOOD : GOODFOOD;

			//for (int j = 0; j < FOOD_NUM; ++j)
			//{
			//	if (i == j) continue;
			//	if (this->f[j].x == this->f[i].x && this->f[j].y == this->f[i].y)
			//	{
			//		i--;
			//		break;
			//	}
			//}
		}
	}
	//printf("food set, %d", frameNum);

	this->w.move(); // BUMP CHECK
	if (this->map1[this->w.body_y[0]][this->w.body_x[0]] == 1 ||
		this->map1[this->w.body_y[0]][this->w.body_x[0]] == 5)
	{
		this->isOver = true;
		return;
	}

	else if (this->map1[this->w.body_y[0]][this->w.body_x[0]] == 3 ||
		this->map1[this->w.body_y[0]][this->w.body_x[0]] == 4)
	{
		for (int i = 0; i < FOOD_NUM; ++i)
		{
			if (this->f[i].x == this->w.body_x[0] &&
				this->f[i].y == this->w.body_y[0])
			{
				this->w.length += ((this->f[i].state == GOODFOOD) ? 1 : -1);
				if (this->w.length == -1) { //몸 길이 체크
					isOver = true;
					return;
				}

				this->f[i].state = NOPRESENT;
			}
		}
	}

	

	//printf("worm moved, %d", frameNum);

	for (int i = 0; i < this->w.length+1; ++i)
	{
		if(this->w.body_x[i]!=0&& this->w.body_y[i]!=0)
			this->map1[this->w.body_y[i]][this->w.body_x[i]] = 2;
	}

	frameNum++;
}