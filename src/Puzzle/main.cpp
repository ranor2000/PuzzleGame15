#include "stdafx.h"
#include "graphicsboard.h"
#include "play.h"


int main() {

	byte** field = nullptr;

	initwindow(600, 500);

	SalutingWindow();

	while (true) {
		cleardevice();
		ProcessGame(field);
		if (getch() == 27)break;
	}
	
	system("PAUSE");

	return 0;
}