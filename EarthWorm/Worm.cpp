#pragma once
#include "Worm.h"

void Worm::changeDir(int keytemp) 
{
	switch (keytemp) {
	case KEY_UP:
		if (dir != 1 && dir != 2)
			dir = 1;
		break;
	case KEY_DOWN:
		if (dir != 2 && dir != 1)
			dir = 2;
		break;
	case KEY_RIGHT:
		if (dir != 3 && dir != 4)
			dir = 3;
		break;
	case KEY_LEFT:
		if (dir != 4 && dir != 3)
			dir = 4;
		break;
	default:
		break;
	}
}

Worm::Worm() {
	length = 0;
	body_x[0] = SIZE_X / 2;
	body_y[0] = SIZE_Y / 2;
	for (int i = 1; i < 200; i++) {
		body_x[i] = 0;
		body_y[i] = 0;
	}
	dir = 1;

	count = orCount = WARM_SPEED;
}

void Worm::move()
{
	if (count == 0)
	{
		count = orCount;
		this->setPos();
	}
	else
		count--;
}

void Worm::setPos()
{
	for (int i = this->length - 1; i >= 0; i--)
	{
		this->body_x[i + 1] = this->body_x[i];
		this->body_y[i + 1] = this->body_y[i];
	}

	if (this->dir == 1)
		(this->body_y[0])--;
	else if (this->dir == 2)
		(this->body_y[0])++;
	else if (this->dir == 3)
		(this->body_x[0])++;
	else if (this->dir == 4)
		(this->body_x[0])--;
}
