#include "pch.h"

TEST(testOfTest, PassedTest) {
  ASSERT_EQ(1, 1);
}

TEST(testOfTest, FailedTest) {
	ASSERT_EQ(1, 0);
}

TEST(testOfTest, testout) {
	byte** field = nullptr;
}

int main(int argc, char** argv) {

	testing::InitGoogleTest(&argc, argv);
	
	return RUN_ALL_TESTS();
}