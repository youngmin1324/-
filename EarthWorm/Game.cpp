#include "Game.h"

Game::Game() {
	td = TimeDivide(70000000);
}

void Game::play() 
{
	m.init();
	m.makeMap();
	m.makeFood();
	m.print();

	int keytemp;
	int i = 0;
	for (;;) 
	{
		if (td.countCheck()) {
			if (_kbhit()) {
				int ch = _getch();
				if (ch != EXT_KEY) continue;
				keytemp = _getch();
				m.w.changeDir(keytemp);
			}
			//printf("frame %d", i++);
			m.mapUpdate();
			if (m.getIsOver())
			{
				//printf("game over");
				break;
			}


			m.print();
		}
	}
}