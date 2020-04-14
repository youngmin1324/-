#include "Bird.h"
Bird::Bird() 
{ 
	this->orCount = rand() % MAX_COUNT + 1;
	this->count = this->orCount;
	this->setDir();
	this->setPos();
}

void Bird::setPos()
{
	while (this->x <= 0 || this->x >= SIZE_X - 1)
		this->x = rand() % SIZE_X;
	while (this->y <= 0 || this->y >= SIZE_Y - 1)
		this->y = rand() % SIZE_Y;
}

void Bird::setDir()
{
	this->dir = rand() % 4 + 1;
}

bool Bird::move() // bird·Î
{
	if (count == 0)
	{
		count = orCount;

		int rx = rand() % 3 - 1;
		int ry = rand() % 3 - 1;
		int tempX = this->x;
		int tempY = this->y;
		this->x = (this->x + rx);
		this->y = (this->y + ry);

		while (this->x <= 0 || this->x >= SIZE_X - 1 ||
			this->y <= 0 || this->y >= SIZE_Y - 1 || (rx!=0&&ry!=0))
		{
			rx = rand() % 3 - 1;
			ry = rand() % 3 - 1;
			this->x = (tempX + rx);
			this->y = (tempY + ry);
		}

		return true;
	}
	else
	{
		count--;
		return false;
	}
}