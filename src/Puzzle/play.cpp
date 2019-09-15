#include "play.h"

void ProcessGame(byte** field) {
	int swipe=0;
	field = GenerateNewField(0);
	BoardOutput(field);

	while (true) {
		MoveDirection direction = KeyCheckConslole();
		if (direction == None)
			continue;
		swipe++;
		RectangelMove(direction, field);
		if (VictoryCheck(field, swipe)) break;

		BoardOutput(field);
	}

	DeleteField(field);
}

bool VictoryCheck(byte** field, int swipe) {
	int coinc=0;
	for (int i = 0; i < 4; i++) 
		for (int j = 0; j < 4; j++)
			if (field[i][j] == i * 4 + j + 1) coinc++;

	if (coinc == 15) {
		VictoryWindow(swipe);
		return true;
	} else
		return false;
}

void OutputBoard(byte** field) {
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++)
			printf("[%2d]", field[i][j]);
		printf("\n");
	}
	printf("\n");
}