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

TEST(GameMechanics, KeyCheck) {
	char a,b,c,d;

	for (int i = 0; i < 7; i++) {
		switch(i) {
		case 0: a = 87; b = 68; c = 83; d = 65; break;
		case 1: a = 119; b = 100; c = 115; d = 97; break;
		case 2: a = 150; b = 130; c = 155; d = 148; break;
		case 3: a = 230; b = 162; c = 235; d = 228; break;
		case 4: a = -26; b = -94; c = -21; d = -28; break;
		case 5: a = -106; b = -126; c = -101; d = -108; break;
		case 6: a = 72; b = 77; c = 80; d = 75; break;
		}

		ASSERT_EQ(KeyCheck(a), DownToUp);
		ASSERT_EQ(KeyCheck(b), LeftToRight);
		ASSERT_EQ(KeyCheck(c), UpToDown);
		ASSERT_EQ(KeyCheck(d), RightToLeft);
	}

	ASSERT_EQ(KeyCheck(27), Esc);
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

TEST(GameIO, SaveLoad) {
	scorelist
		* tested = new scorelist[SCORE_LIST_SIZE],
		* control = new scorelist[SCORE_LIST_SIZE];
	char tmp[WORDSIZE];
	for (int i = 0; i < SCORE_LIST_SIZE; i++) {
		_itoa(i*100+i, tmp, 10);

		strcpy(control[i].playerName, tmp);
		control[i].score = i;
		strcpy(control[i].textScore, tmp);
	}
	savescore(control);

	loadscore(tested);

	for (int i = 0; i < SCORE_LIST_SIZE; i++) {
		ASSERT_EQ(control[i].score, tested[i].score);
		ASSERT_FALSE(strcmp(control[i].textScore, tested[i].textScore));
		ASSERT_FALSE(strcmp(control[i].playerName, tested[i].playerName));
	}

}

int main(int argc, char** argv) {

	testing::InitGoogleTest(&argc, argv);
	
	return RUN_ALL_TESTS();
}