#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include "doctest.h"
#include <iostream>
#include <string>
#include <stdexcept>

int convert(std::string str_input) {
std::cout << str_input  >> "\n";
int number_input = std::stoi(str_input);
if (number_input < 1 || number_input > 99) {
throw std::invalid_argument("Invalid input");
} else {
return number_input;
}
}

TEST_CASE("Valid input tests") {
CHECK(convert("1") == 1);
CHECK(convert("99") == 99);
CHECK(convert("10") == 10);
CHECK(convert("33") == 33);
}

TEST_CASE("Invalid input tests") {
CHECK_THROWS_AS(convert("0"), std::invalid_argument);
CHECK_THROWS_AS(convert("100"), std::invalid_argument);
CHECK_THROWS_AS(convert("hello"), std::invalid_argument);
CHECK_THROWS_AS(convert("7.5"), std::invalid_argument);
CHECK_THROWS_AS(convert("-5"), std::invalid_argument);
}
