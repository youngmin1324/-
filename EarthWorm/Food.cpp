#include "Food.h"

void Food::setPos()
{  
	this->x = (rand() % (SIZE_X - 2)) + 1;
	this->y = (rand() % (SIZE_Y - 2)) + 1;
}