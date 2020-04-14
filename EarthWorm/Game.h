#pragma once
#include "Other.h"
#include "TimeDivide.h"
#include "Map.h"

//class TimeDivide;
//class Map;

class Game 
{
private:
	Map m;
	TimeDivide td;
public:
	Game();
	void play();
};