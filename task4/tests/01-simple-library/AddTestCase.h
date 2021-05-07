//
// Created by akhtyamovpavel on 5/1/20.
//


#pragma once

#include <gtest/gtest.h>
#include "Functions.h"

class AddTestCase: public ::testing::Test{
public:
    void test1() {
        EXPECT_EQ(Add(1, 1), 2);
    }
};
