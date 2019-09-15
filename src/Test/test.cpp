#include "../Puzzle/generation.h"
#include "../Puzzle/play.h" 
#include "../Puzzle/shift.h"
#include "pch.h"

TEST(GeneralFunctions, Swap) {
	byte a = 1, b = 2;
	swap(a, b);
}

TEST(GameMechanics, Generation) {
	byte** testField;

	for (int k = 0; k < 100; k++) {
		testField = GenerateNewField();
		int sum = 0;

		// checking for control sum
		for (int i = 0; i < 4; i++) {
			for (int j = 0; j < 4; j++)
				sum += testField[i][j];
		}

		DeleteField(testField);
		ASSERT_EQ(sum, 120);
	}
}

TEST(GameMechanics, Victory) {
	byte** testField = GenerateNewField();
	
	// freshly generated field cant be win 
	ASSERT_FALSE(VictoryCheck(testField));

	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			testField[i][j] = i * 4 + j + 1;
	testField[3][3] = EMPTY;

	ASSERT_TRUE(VictoryCheck(testField));
}

int main(int argc, char** argv) {

	testing::InitGoogleTest(&argc, argv);
	
	return RUN_ALL_TESTS();
}