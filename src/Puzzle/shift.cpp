#include "shift.h"

// change 2 elemets
void swap(byte &a, byte &b) {
	byte temp = a;
	a = b;
	b = temp;
}

// check from console
MoveDirection KeyCheckConslole() {
	char key = getch();
	return KeyCheck(key);
}

// check 
MoveDirection KeyCheck(char key) {
	if (key == 87 || key == 119 || key == 150 || key == 230 || key == -26 || key == -106 || key == 72)
		return DownToUp;

	if (key == 68 || key == 100 || key == 130 || key == 162 || key == -94 || key == -126 || key == 77)
		return LeftToRight;

	if (key == 83 || key == 115 || key == 155 || key == 235 || key == -21 || key == -101 || key == 80)
		return UpToDown;

	if (key == 65 || key == 97 || key == 148 || key == 228 || key == -28 || key == -108 || key == 75)
		return RightToLeft;
	if (key == 27)
		return Esc;
	return None;
}

// move empty cell
void RectangelMove(MoveDirection direction, byte** field) {
	int i, j;

	switch (direction) {
		case DownToUp: {
			for (i = 1; i < 4; i++)
				for (j = 0; j < 4; j++)
					if (field[i][j] == EMPTY)
						swap(field[i][j], field[i - 1][j]);
			break;
		}

		case UpToDown: {
			for (i = 2; i >= 0; i--)
				for (j = 0; j < 4; j++)
					if (field[i][j] == EMPTY)
						swap(field[i][j], field[i + 1][j]);
			break;
		}

		case LeftToRight: {
			for (i = 0; i < 4; i++)	
				for (j = 2; j >= 0; j--)
					if (field[i][j] == EMPTY)
						swap(field[i][j], field[i][j + 1]);
			break;
		}

		case RightToLeft: {
			for (i = 0; i < 4; i++)
				for (j = 1; j < 4; j++)
					if (field[i][j] == EMPTY)
						swap(field[i][j], field[i][j - 1]);
			break;
		}

		default: break;
	}
}