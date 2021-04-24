#include "gtest/gtest.h"
#include "A/index.h"
#include "B/lib.h"

TEST(pop, POP_TEST) {
    EXPECT_EQ(100, pop(200)); 
    EXPECT_EQ(101, pop(203));
}

TEST(sum, SUM_TEST) {
  EXPECT_EQ(0, sum(0, 0));
  EXPECT_EQ(1, sum(0, 1));
}

int main(int argc, char *argv[]) {
	::testing::InitGoogleTest(&argc, argv);
	return RUN_ALL_TESTS();
}
