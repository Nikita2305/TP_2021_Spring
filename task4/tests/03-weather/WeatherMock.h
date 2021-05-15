//
// Created by Pavel Akhtyamov on 02.05.2020.
//

#pragma once

#include <gmock/gmock.h>
#include <Weather.h>

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

class WeatherMock : public Weather {
public:
    MOCK_METHOD(cpr::Response, Get, (const std::string&, const cpr::Url&), (override));
    void DelegateToFake(bool flag) {
        if (flag) {
            ON_CALL(*this, Get).WillByDefault([this](const std::string& city, const cpr::Url& url) {
                return fake.Get(city, url);
            });
        } else {
            ON_CALL(*this, Get).WillByDefault([this](const std::string& city, const cpr::Url& url) {
                return impotent.Get(city, url);
            });
        }
    }
private:
    FakeWeather fake;
    ImpotentWeather impotent;
};
