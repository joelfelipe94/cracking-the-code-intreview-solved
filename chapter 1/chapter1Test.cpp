#include <gtest/gtest.h>
#include "exercise1.hpp"
#include "exercise2.hpp"

// Exercise 1

TEST(exercise1, isAllUniqueTrue)
{
    GTEST_ASSERT_EQ(isAllUnique("abcde"), true);
}

TEST(exercise1, isAllUniqueFalse)
{
    GTEST_ASSERT_EQ(isAllUnique("abacde"), false);
}

TEST(exercise1, isAllUniqueLarge)
{
    string inputStr("0123456789012345678901234567890123456789"
                    "0123456789012345678901234567890123456789"
                    "0123456789012345678901234567890123456789"
                    "0123456789012345678901234567890123456789"
                    "0123456789012345678901234567890123456789"
                    "0123456789012345678901234567890123456789"
                    "34567890123456789");
    GTEST_ASSERT_EQ(isAllUnique(inputStr), false);
}

TEST(exercise1, isAllUniqueEmpty)
{
    GTEST_ASSERT_EQ(isAllUnique(""), true);
}

TEST(exercise1, isAllUniqueInplaceTrue)
{
    GTEST_ASSERT_EQ(isAllUniqueInplace("abcde"), true);
}

TEST(exercise1, isAllUniqueInplaceFalse)
{
    GTEST_ASSERT_EQ(isAllUniqueInplace("abacde"), false);
}

TEST(exercise1, isAllUniqueInplaceLarge)
{
    string inputStr("0123456789012345678901234567890123456789"
                    "0123456789012345678901234567890123456789"
                    "0123456789012345678901234567890123456789"
                    "0123456789012345678901234567890123456789"
                    "0123456789012345678901234567890123456789"
                    "0123456789012345678901234567890123456789"
                    "34567890123456789");
    GTEST_ASSERT_EQ(isAllUnique(inputStr), false);
}

TEST(exercise1, isAllUniqueInplaceEmpty)
{
    GTEST_ASSERT_EQ(isAllUniqueInplace(""), true);
}

// Exercise 2

TEST(exercise2, oddSize)
{
    std::string expected("abcde"), inStr("edcba");
    GTEST_ASSERT_EQ(reverse(inStr), expected);
}

TEST(exercise2, evenSize)
{
    std::string expected("abcd"), inStr("dcba");
    GTEST_ASSERT_EQ(reverse(inStr), expected);
}

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}