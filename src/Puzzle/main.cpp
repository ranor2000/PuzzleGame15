#include "stdafx.h"
#include "graphicsboard.h"
#include "play.h"

int main() {
	
	byte** field = nullptr;

	initwindow(600, 500);
	settextstyle(0, 0, 10);

	ProcessGame(field);

	system("PAUSE");

	return 0;
}