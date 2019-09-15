#include "../Puzzle/shift.h"
#include "pch.h"

TEST(GeneralFunctions, Swap) {
	byte a = 1, b = 2;
	swap(a, b);
}

int main(int argc, char** argv) {

	testing::InitGoogleTest(&argc, argv);
	
	return RUN_ALL_TESTS();
}