#include "../Puzzle/generation.h"
#include "../Puzzle/play.h" 
#include "../Puzzle/shift.h"

#include "pch.h"

TEST(GeneralFunctions, Swap) {
	byte a, da, b, db;
	a = da = 1,
	b = db = 2;
	swap(da, db);

	ASSERT_NE(da, a);
	ASSERT_NE(db, b);
}

TEST(GameMechanics, Generation) {
	byte** testField;

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

TEST(GameMechanics, Victory) {
	byte** testField = GenerateNewField();
	
	// freshly generated field cant be win 
	ASSERT_FALSE(VictoryCheck(testField,100));

	for (int i = 0; i < 4; i++)
		for (int j = 0; j < 4; j++)
			testField[i][j] = i * 4 + j + 1;
	testField[3][3] = EMPTY;

	ASSERT_TRUE(VictoryCheck(testField,100));
}

int main(int argc, char** argv) {

	testing::InitGoogleTest(&argc, argv);
	
	return RUN_ALL_TESTS();
}