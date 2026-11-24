#include "pch.h"
#include "gtest/gtest.h"
#include <optional>

std::optional<int> removeEvenOccurrences(int number) {
    if (number <= 0) {
        return std::nullopt;
    }

    int result = 0;
    int d = 1;

    int next_number = number;
    while (next_number > 0) {
        int cifra = next_number % 10;
        int k = 0;
        int check_number = number;
        while (check_number > 0) {
            if (check_number % 10 == cifra) {
                k++;
            }
            check_number /= 10;
        }

        if (k % 2 != 0) {
            result = result + cifra * d;
            d *= 10;
        }

        next_number /= 10;
    }

    return result;
}


TEST(RemoveEvenOccurrencesTest, BasicTest) {
 
    auto res = removeEvenOccurrences(1223);
    ASSERT_TRUE(res.has_value());
    EXPECT_EQ(res.value(), 13);
}

TEST(RemoveEvenOccurrencesTest, AllEvenOccurrences) {
    
    auto res = removeEvenOccurrences(445522);
    ASSERT_TRUE(res.has_value());
    EXPECT_EQ(res.value(), 0);
}

TEST(RemoveEvenOccurrencesTest, NoEvenOccurrences) {
   
    auto res = removeEvenOccurrences(12345);
    ASSERT_TRUE(res.has_value());
    EXPECT_EQ(res.value(), 12345);
}

TEST(RemoveEvenOccurrencesTest, InvalidInput) {
  
    EXPECT_FALSE(removeEvenOccurrences(0).has_value());
    EXPECT_FALSE(removeEvenOccurrences(-500).has_value());
}
