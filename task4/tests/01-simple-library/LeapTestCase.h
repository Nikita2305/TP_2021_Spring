//
// Created by akhtyamovpavel on 5/1/20.
//


#pragma once

#include <gtest/gtest.h>
#include "Functions.h"

class LeapTestCase : public ::testing::Test {
 public:
  void test1() {
    EXPECT_EQ(IsLeap(1), false);
    EXPECT_EQ(IsLeap(4), true);
    EXPECT_EQ(IsLeap(400), true);
    EXPECT_EQ(IsLeap(100), false);
  }
  void test2() {
    EXPECT_THROW(IsLeap(-1), std::invalid_argument);
  }
  void test3() {
    EXPECT_EQ(GetMonthDays(20, 2), 29);
    EXPECT_EQ(GetMonthDays(21, 2), 28);
    EXPECT_EQ(GetMonthDays(20, 4), 30);
    EXPECT_EQ(GetMonthDays(20, 3), 31);
  }
  void test4() {
    EXPECT_THROW(GetMonthDays(1, -4), std::invalid_argument);
  }
};

TEST_F(LeapTestCase, name) {
  test1();
  test2();
  test3();
  test4();
}
