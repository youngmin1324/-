#pragma once
#include "Other.h"

class TimeDivide
{
private:
	static int number;
	int count;
	int orCount;
public:
	TimeDivide();
	TimeDivide(int orCount);
	int getOrCount();
	bool countCheck();
};