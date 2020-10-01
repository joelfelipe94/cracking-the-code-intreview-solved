#include <gtest/gtest.h>
#include "exercise1.hpp"
#include "exercise2.hpp"
#include "exercise3.hpp"
#include "exercise4.hpp"
#include "exercise5.hpp"
#include "exercise6.hpp"
#include "exercise7.hpp"

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

TEST(exercise3, isPermutationTrue)
{
    std::string first("abcd"), second("dcba");
    auto result = isPermutation(first,second);
    GTEST_ASSERT_EQ(result, true);
}

TEST(exercise3, isPermutationFalse)
{
    std::string first("abdd"), second("dcba");
    auto result = isPermutation(first,second);
    GTEST_ASSERT_EQ(result, false);
}

TEST(exercise3, isPermutationFalseDifferentSizes)
{
    std::string first("abdd"), second("dba");
    auto result = isPermutation(first,second);
    GTEST_ASSERT_EQ(result, false);
}

TEST(exercise4, replaceSpaceWithPercent20)
{
    std::string str("ab dd  "), expected("ab%20dd");
    replaceSpaceWithPercent20(str);
    GTEST_ASSERT_EQ(str, expected);
}

TEST(exercise5, compress)
{
    std::string str("aabcccccaaa"), expected("a2b1c5a3");
    GTEST_ASSERT_EQ(compress(str), expected);
}

TEST(exercise5, compressNotApplied)
{
    std::string str("aabcscscscscsaaa"), expected("aabcscscscscsaaa");
    GTEST_ASSERT_EQ(compress(str), expected);
}

TEST(exercise6, rotateImage)
{
    vector< vector<int> > image = { {1, 2, 3, 4},
                                    {1, 2, 3, 4},
                                    {1, 2, 3, 4},
                                    {1, 2, 3, 4}};

    vector< vector<int> > expected = { {1, 1, 1, 1},
                                        {2, 2, 2, 2},
                                        {3, 3, 3, 3},
                                        {4, 4, 4, 4}};
    rotateImage(image);                                          
    GTEST_ASSERT_EQ(image, expected);
}

TEST(exercise7, resetColumnLine)
{
    vector< vector<int> > mat = { {0, 2, 3, 4, 5},
                                {1, 2, 3, 4, 5},
                                {1, 2, 3, 4, 5},
                                {1, 2, 3, 0, 5}};

    vector< vector<int> > expected = { {0, 0, 0, 0, 0},
                                        {0, 2, 3, 0, 5},
                                        {0, 2, 3, 0, 5},
                                        {0, 0, 0, 0, 0}};
    resetColumnRow(mat);                                          
    GTEST_ASSERT_EQ(mat, expected);
}

TEST(exercise7, resetColumnLineEmptyMatrix)
{
    vector< vector<int> > mat;

    vector< vector<int> > expected;
    resetColumnRow(mat);                                          
    GTEST_ASSERT_EQ(mat, expected);
}

TEST(exercise7, resetColumnLineEmptyColumn)
{
    vector< vector<int> > mat{{}};

    vector< vector<int> > expected{{}};
    resetColumnRow(mat);                                          
    GTEST_ASSERT_EQ(mat, expected);
}


int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}