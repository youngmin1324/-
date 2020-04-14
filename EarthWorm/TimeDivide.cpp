#pragma once
#include "TimeDivide.h"

int TimeDivide::number = 0;

TimeDivide::TimeDivide() {
}

TimeDivide::TimeDivide(int orCount)
{
	count = this->orCount = orCount;
}

bool TimeDivide::countCheck()
{
	if (count > 0) {
		count--;
		return false;
	}
	else {
		count = orCount;
		return true;
	}
}

int TimeDivide::getOrCount()
{
	return this->orCount;
}



