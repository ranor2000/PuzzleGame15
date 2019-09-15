#include "stdafx.h"
#include "graphicsboard.h"
#include "play.h"

int main() {
	
	byte** field = nullptr;

	initwindow(600, 500);
	settextstyle(0, 0, 10);

	while (true) {
		ProcessGame(field);
		if (getch() == 27)break;
		cleardevice();
	}

	system("PAUSE");

	return 0;
}