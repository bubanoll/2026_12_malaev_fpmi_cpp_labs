#include "pch.h"
#include "gtest/gtest.h"
#include <optional>


std::optional<int> removeMinDigit(int number) {
    if (number <= 0) {
        return std::nullopt;
    }

    int min = 9;
    int next_number = number;
    while (next_number > 0) {
        int cifra = next_number % 10;
        if (cifra < min) {
            min = cifra;
        }
        next_number /= 10;
    }

    int result = 0;
    int k = 1;
    next_number = number;
    while (next_number > 0) {
        int cifra = next_number % 10;
        if (min != cifra) {
            result = result + cifra * k;
            k *= 10;
        }
        next_number /= 10;
    }

    return result;
}

TEST(RemoveMinDigitTest, PositiveNumberTest1) {
    auto res = removeMinDigit(5389);
    ASSERT_TRUE(res.has_value());
    EXPECT_EQ(res.value(), 589);
}

TEST(RemoveMinDigitTest, AllSameDigits) {
    auto res = removeMinDigit(333);
    ASSERT_TRUE(res.has_value());
    EXPECT_EQ(res.value(), 0);
}

TEST(RemoveMinDigitTest, InvalidInputZeroOrNegative) {
    EXPECT_FALSE(removeMinDigit(0).has_value());
    EXPECT_FALSE(removeMinDigit(-15).has_value());
}