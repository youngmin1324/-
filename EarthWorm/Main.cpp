#include "Game.h"
#include "Other.h"

int menuDraw() {
	const int initY = SIZE_Y / 2 - 1;
	int x = SIZE_X - 6;
	int y = initY;

	gotoxy(x - 2, y);
	printf("> 게 임 시 작\n");
	gotoxy(x, y + 2);
	printf("   종 료   ");

	while (1) {
		if (_kbhit()) {
			int keytemp = _getch();
			switch (keytemp) {
			case KEY_DOWN:
				if (y == initY) {
					gotoxy(x - 2, y);
					printf("  ");
					y += 2;
					gotoxy(x - 2, y);
					printf("> ");
				}
				break;
			case KEY_UP:
				if (y == initY + 2) {
					gotoxy(x - 2, y);
					printf("  ");
					y -= 2;
					gotoxy(x - 2, y);
					printf("> ");
				}
				break;
			case KEY_ENTER:
				system("cls");
				return y - initY;
			}
		}
	}
}

void printGameOver() {
	int x = SIZE_X - 8;
	int y = SIZE_Y / 2;

	gotoxy(x, y);
	printf("G A M E  O V E R");

	Sleep(1000);

	while (1) {
		if (_kbhit()) {
			_getch();
			system("cls");

			return;
		}
	}
}

int main()
{
	system(" mode  con lines=25   cols=70 ");
	system("title 지렁쓰○○○○");
	removeCursor();
	for (;;) {
		srand((unsigned int)time(NULL));

		int select = menuDraw();
		if (select == 2) break;

		Game earthworm;
		earthworm.play();
		system("cls");
		
		printGameOver();
	}
	/*DoubleBuffer db;
	for (;;)
	{
		db.mosterMove();
		db.set();
		db.print();

		Sleep(10);
	}


	//TimeDivide tdArr[10];


	//for (;;)
	//{
	//	for (int i = 0; i < 10; ++i)
	//	{
	//		tdArr[i].countCheck();
	//	}
	//	Sleep(10);
	//}
	*/
	return 0;
}
