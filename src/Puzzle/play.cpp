#include "play.h"

void NewBoard(byte** field) {
	int randshift;
	srand(time(NULL));
	for (int i = 0; i < 1000; i++) {
		randshift = rand() % 4;
		switch (randshift) {
			case 0: {
				RectangelMove(DownToUp, field);
				break;
			}
			case 1: {
				RectangelMove(LeftToRight, field);
				break;
			}
			case 2: {
				RectangelMove(UpToDown, field);
					break;
			}
			case 3: {
				RectangelMove(RightToLeft, field);
				break;
			}
		}
	}
}

void ProcessGame(byte** field) {
	while (true) {
		RectangelMove(KeyCheckConslole(), field);
		system("CLRSCR");
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++)
				printf("[%2d] ", field[i][j]);
			printf("\n");
		}
	}
}