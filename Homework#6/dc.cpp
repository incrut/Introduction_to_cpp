#include <iostream>
#include <string>
#include <stdexcept>
#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"

int convert_input(std::string input) {
    int number;
    try {
        size_t decimal_point = input.find(".");
        if (decimal_point != std::string::npos) {
            throw std::string("invalid input");
        }
        number = std::stoi(input);
    } catch (std::invalid_argument&) {
        throw std::string("invalid input");
    }
    if (number < 1 || number > 99) {
        throw std::string("invalid input");
    }
    return number;
}

TEST_CASE("Valid input is converted to integer") {
    CHECK(convert_input("1") == 1);
    CHECK(convert_input("50") == 50);
    CHECK(convert_input("99") == 99);
}

TEST_CASE("Invalid input throws an exception of type string") {
    CHECK_THROWS_AS(convert_input("0"), std::string);
    CHECK_THROWS_AS(convert_input("100"), std::string);
    CHECK_THROWS_AS(convert_input("2.5"), std::string);
    CHECK_THROWS_AS(convert_input("test"), std::string);
}