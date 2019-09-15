#include "stdafx.h"

#include "generation.h"

int main() {

	byte** field = GenerateNewField(0);


	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++)
			printf("[%2d] ", field[i][j]);
		printf("\n");
	}

	DeleteField(field);

	system("PAUSE");

	return 0;
}