#include "generation.h"

byte** GenerateNewField(int countOfShuffle) {

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

	return field;

	// shuffle

	// TODO... need function of move

}

void DeleteField(byte** field) {

	for (int i = 0; i < 4; i++)
		delete[] field[i];

	delete[] field;
}