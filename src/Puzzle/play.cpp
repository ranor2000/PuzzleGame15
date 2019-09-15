#include "play.h"

void ProcessGame(byte** field) {

	field = GenerateNewField();
	OutputBoard(field);

	while (true) {
		MoveDirection direction = KeyCheckConslole();
		if (direction == None)
			continue;
	
		RectangelMove(direction, field);
		if (VictoryCheck(field)) break;

		BoardOutput(field);
	}

	DeleteField(field);
}

bool VictoryCheck(byte** field) {
	int coinc=0;
	for (int i = 0; i < 4; i++) 
		for (int j = 0; j < 4; j++)
			if (field[i][j] == i * 4 + j + 1) coinc++;

	if (coinc == 15) {
		VictoryWindow();
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