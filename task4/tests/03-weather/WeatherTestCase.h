
#pragma once

#include <gtest/gtest.h>
#include "Weather.h"

class FakeWeather : public Weather {
 public:
  float float_rand() {
    return (rand() % 100) / 10.0;
  }
  cpr::Response Get(const std::string& city, const cpr::Url& url) override {
    cpr::Response response;
    response.text = "{\"list\":[\"a;f\",\"a;jf\",\";jf\",\"ajkf\",\"asjf\",\"a;igj\",\"apoisjg\",{\"main\":{\"temp\":" + std::to_string(float_rand()) + "}}], \"main\":{\"temp\":" + std::to_string(float_rand()) + "}}";
    response.status_code = 200;
    return response;
  }
};

class ImpotentWeather : public Weather {
 public:
  cpr::Response Get(const std::string& city, const cpr::Url& url) override {
    cpr::Response response;
    response.status_code = 147;
    return response;
  }
};

class WeatherTestCase : public ::testing::Test {
 public:
  void test1() {
    FakeWeather a;
    for (int i = 0; i < 100; ++i)
      a.GetDifferenceString("alsdfj", "askdf");
    for (int i = 0; i < 100; ++i)
      a.GetTomorrowDiff("a;kjfal;kjflaskdf");
  }
  void test2() {
    ImpotentWeather a;
    a.SetApiKey("laskdj");
    EXPECT_THROW(a.GetDifferenceString("alsdfj", "askdf"), std::invalid_argument);
  }
};

TEST_F(WeatherTestCase, name) {
  test1();
  test2();
}
