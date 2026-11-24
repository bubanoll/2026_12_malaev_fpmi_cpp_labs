#include "pch.h"
#include "gtest/gtest.h"
#include <optional>

std::optional<int> findMinNonZeroDigit(int number) {
    if (number <= 0) {
        return std::nullopt;
    }

    int min = 9;
    int next_number = number;

    while (next_number > 0) {
        int cifra = next_number % 10;

        if (cifra < min && cifra != 0) {
            min = cifra;
        }
        next_number /= 10;
    }

    return min;
}

TEST(FindMinNonZeroDigitTest, BasicPositiveNumber) {
    auto res = findMinNonZeroDigit(5389);
    ASSERT_TRUE(res.has_value());
    EXPECT_EQ(res.value(), 3);
}

TEST(FindMinNonZeroDigitTest, NumberWithZeros) {
    auto res = findMinNonZeroDigit(50206);
    ASSERT_TRUE(res.has_value());
    EXPECT_EQ(res.value(), 2);
}

TEST(FindMinNonZeroDigitTest, AllSameDigits) {
    auto res = findMinNonZeroDigit(777);
    ASSERT_TRUE(res.has_value());
    EXPECT_EQ(res.value(), 7);
}

TEST(FindMinNonZeroDigitTest, InvalidInputZeroOrNegative) {
    EXPECT_FALSE(findMinNonZeroDigit(0).has_value());
    EXPECT_FALSE(findMinNonZeroDigit(-100).has_value());
}
