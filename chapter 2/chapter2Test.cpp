#include <gtest/gtest.h>
#include "exercise1.hpp"

// Exercise 1

TEST(exercise1, removeDuplicates)
{
    auto list = forward_list<int>{1,2,3,4,5,6,6,5,7,8,9};
    auto expected = forward_list<int>{1,2,3,4,5,6,7,8,9};  
    removeDuplicates(list);
    GTEST_ASSERT_EQ(list, expected);
}

TEST(exercise1, removeDuplicatesEmpty)
{
    auto list = forward_list<int>{};
    auto expected = forward_list<int>{};  
    removeDuplicates(list);
    GTEST_ASSERT_EQ(list, expected);
}

TEST(exercise1, removeDuplicatesInplace)
{
    auto list = forward_list<int>{1,2,3,4,5,6,6,5,7,8,9};
    auto expected = forward_list<int>{1,2,3,4,5,6,7,8,9};  
    removeDuplicatesInPlace(list);
    GTEST_ASSERT_EQ(list, expected);
}

TEST(exercise1, removeDuplicatesInplaceEmpty)
{
    auto list = forward_list<int>{};
    auto expected = forward_list<int>{};  
    removeDuplicatesInPlace(list);
    GTEST_ASSERT_EQ(list, expected);
}


int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}