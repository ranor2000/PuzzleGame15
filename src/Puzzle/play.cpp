#include "play.h"

void ProcessGame(byte** field) {

	field = GenerateNewField(0);
	OutputBoard(field);

	while (true) {
		MoveDirection direction = KeyCheckConslole();
		if (direction == None)
			continue;

		RectangelMove(direction, field);
		system("CLS");
		if (VictoryCheck(field)) break;

		OutputBoard(field);
	}

	DeleteField(field);
}

bool VictoryCheck(byte** field) {
	int coinc=0;
	for (int i = 0; i < 4; i++) 
		for (int j = 0; j < 4; j++)
			if (field[i][j] == i * 4 + j + 1) coinc++;

	if (coinc == 14) {
		system("CLS");
		printf("Vicory\n");
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