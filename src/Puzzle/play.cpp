#include "play.h"

void NewBoard(byte** field) {
	srand(time(NULL));

	for (int i = 0; i < 1000; i++) {
		int randshift = rand() % 4;
		MoveDirection shift;

		switch (randshift) {
			case 0: shift = DownToUp;
				break;
			case 1: shift = LeftToRight;
				break;
			case 2:	shift = UpToDown;
				break;
			case 3: shift = RightToLeft;
				break;
		}

		RectangelMove(shift, field);
	}
}

void ProcessGame(byte** field) {
	NewBoard(field);
	while (true) {
		RectangelMove(KeyCheckConslole(), field);
		system("CLS");
		if (VictoryCheck(field) == 1) break;
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++)
				printf("[%2d] ", field[i][j]);
			printf("\n");
		}
	}
}

int VictoryCheck(byte** field) {
	int coinc=0;
	for (int i = 0; i < 4; i++) 
		for (int j = 0; j < 4; j++)
			if (field[i][j] = i * 4 + j + 1) coinc++;
	if (coinc == 14) {
		system("CLS");
		printf("Vicory");
		return 1;
	}
}