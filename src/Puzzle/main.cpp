#include "stdafx.h"
#include "graphicsboard.h"
#include "play.h"

int main() {
	
	byte** field = nullptr;

	initwindow(600, 500);
	settextstyle(0, 0, 3);
	SalutingWindow();
	getch();
	settextstyle(0, 0, 10);

	while (true) {
		cleardevice();
		ProcessGame(field);
		if (getch() == 27)break;
	}

	system("PAUSE");

	return 0;
}