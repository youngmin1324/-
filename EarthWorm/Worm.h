#pragma once
#include "Other.h"

class Worm {
private:

public:
	int body_x[200];
	int body_y[200];
	int dir;
	int length;
	int orCount;
	int count;

	Worm();
	void changeDir(int keytmp);
	void move();
	void setPos();
};