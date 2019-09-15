#include "shift.h"

void swap(byte &a, byte &b) {
	byte temp = a;
	a = b;
	b = temp;
}

MoveDirection KeyCheckConslole() {
	char key = _getch();
	return KeyCheck(key);
}

MoveDirection KeyCheck(char key) {
	// TODO
}

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
				for (j = 0; j < 3; j++)
					if (field[i][j] == EMPTY)
						swap(field[i][j], field[i][j - 1]);
			break;
		}
							
		default: break;
	}
}