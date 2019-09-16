#include "generation.h"

byte** GenerateNewField() {

	// allocation and fill orderly
	byte** field;
	field = new byte*[4];
	for (int i = 0; i < 4; i++) {
		field[i] = new byte[4];
		for (int j = 0; j < 4; j++) {
			field[i][j] = i * 4 + j + 1;
		}
	}
	field[3][3] = EMPTY;
	srand(time(NULL));
	// shuffle
	for (int i = 0; i < 1000; i++) {
		int randshift = rand() % 4;
		MoveDirection shift = None;
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
	return field;
}

void DeleteField(byte** field) {
	for (int i = 0; i < 4; i++)
		delete[] field[i];
	delete[] field;
}