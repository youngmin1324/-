#pragma once
#include "Other.h"

class Bird 
{
private:
	int dir;
	int x;
	int y;
	int orCount;
	int count;
public:
	Bird();
	bool move();
	void setDir();
	void setPos();
	int getX() { return this->x; }
	int getY() { return this->y; }
	void setX(int x) { this->x = x; }
	void setY(int y) { this->y = y; }
	void setCount(int c) { this->count = c; }
};

