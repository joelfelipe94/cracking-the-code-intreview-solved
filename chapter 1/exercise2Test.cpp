#include <gtest/gtest.h>
#include "exercise2.hpp"
#include <string>

TEST(reverse, oddSize)
{
    std::string expected("abcde"), inStr("edcba");
    GTEST_ASSERT_EQ(reverse(inStr), expected);
}

TEST(reverse, evenSize)
{
    std::string expected("abcd"), inStr("dcba");
    GTEST_ASSERT_EQ(reverse(inStr), expected);
}

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}