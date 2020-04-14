#pragma once

#include "DoubleBuffer.h"

DoubleBuffer::DoubleBuffer()
{
	this->monsterX = 1;
	this->monsterY = 1;

	for (int i = 0; i < 10; i++)
	{
		for (int j = 0; j < 10; j++)
		{
			if (i == 0 || i == 9)
			{
				//if (j == 0 || j == 9)
				this->map1[i][j] = 1;
			}
			else
			{
				if (j == 0 || j == 9)
					this->map1[i][j] = 1;
				else
					this->map1[i][j] = 0;
			}
		}
	}
}

void DoubleBuffer::mosterMove()
{
	this->map1[monsterY][monsterX] = 0;
	monsterX = (monsterX + 1) % 9;
	monsterY = (monsterY + 1) % 9;
	this->map1[monsterY][monsterX] = 3;
}



void DoubleBuffer::setMap()
{
	for (int i = 0; i < TOTAL_SIZE_Y; i++) {
		for (int j = 0; j < TOTAL_SIZE_X; j++) {
			map2[i][j] = map1[i][j];
		}
	}
}

void DoubleBuffer::print()
{
	for (int i = 0; i < SIZE_Y; i++) {
		for (int j = 0; j < SIZE_X; j++) {
			gotoxy(2 * j, i);
			switch (map2[i][j]) {
			case 0:
				printf("  ");
				break;
			case 1:
				printf("¢Ì");
				break;
			case 2:
				printf("¡Û");
			case 3:
				printf("¢Ô");
				break;
			case 4:
				printf("¡Ä");
				break;
			case 5:
				printf("¡Ý");
				break;
			}
		}
	}
}
