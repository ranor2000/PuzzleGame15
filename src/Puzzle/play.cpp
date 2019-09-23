#include "play.h"

void ProcessGame(byte** field) {
	int swipe = 0;
	field = GenerateNewField();

	BoardOutput(field);

	// main game cycle
	while (true) {
		MoveDirection direction = KeyCheck(getch());

		if (direction == Escape)
			return;

		if (direction == None)
			continue;

		swipe++;
		RectangelMove(direction, field);
		if (VictoryCheck(field, swipe)) {
			VictoryWindow(swipe);
			break;
		}

		BoardOutput(field);
	}

	// free memory
	DeleteField(field);
}

bool VictoryCheck(byte** field, int swipe) {
	int coinc = 0;

	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			if (field[i][j] == i * 4 + j + 1) coinc++;

	if (coinc == 15)
		return true;
	else
		return false;
}
