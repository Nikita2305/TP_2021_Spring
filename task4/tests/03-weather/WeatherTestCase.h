
#pragma once

#include <gtest/gtest.h>
#include "Weather.h"
#include "WeatherMock.h"

class WeatherTestCase : public ::testing::Test {
public:
    void test1() {
        WeatherMock a;
        a.DelegateToFake(true);
        for (int i = 0; i < 100; ++i)
            a.GetDifferenceString("alsdfj", "askdf");
        for (int i = 0; i < 100; ++i)
            a.GetTomorrowDiff("a;kjfal;kjflaskdf");
    }
    void test2() {
        WeatherMock a;
        a.DelegateToFake(false);
        a.SetApiKey("laskdj");
        EXPECT_THROW(a.GetDifferenceString("alsdfj", "askdf"), std::invalid_argument);
    }
};
