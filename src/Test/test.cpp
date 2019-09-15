#include "pch.h"

TEST(testOfTest, PassedTest) {
  EXPECT_EQ(1, 1);
  EXPECT_TRUE(true);
}

TEST(testOfTest, FailedTest) {
	EXPECT_EQ(1, 0);
}