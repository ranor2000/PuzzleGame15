#include "stdafx.h"
#include "graphicsboard.h"
#include "play.h"


int main() {

	byte** field = nullptr;
	initwindow(600, 500);
	SalutingWindow();
	if (getch() == 27)return 0;
	while (true) {
		cleardevice();
		ProcessGame(field);
		SalutingWindow();
		if (getch() == 27)return 0;
	}
	system("PAUSE");

	return 0;
}