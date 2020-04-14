#pragma once
#include "Other.h"
#include "Food.h"
#include "Bird.h"
#include "Worm.h"

class Map {
private:
	int map1[SIZE_Y][SIZE_X];
	int map2[SIZE_Y][SIZE_X];
	Food f[FOOD_NUM];
	int lswitch;
	bool isOver;
public:
	Bird b[BIRD_NUM]; // ������ ��ġ�� ��ġ�� �ʴ���, ����� �ƴ����� üũ
	Worm w;
	void init();
	void makeMap();
	void setMap(int i, int j);
	void print();
	//void birdMove();
	//void wormMove();
	void makeFood();
	bool bumpCheck(int tmp);
	void mapUpdate();
	bool getIsOver() { return this->isOver; }
};