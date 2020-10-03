#include <gtest/gtest.h>
#include "exercise1.hpp"
#include "exercise2.hpp"
#include "exercise3.hpp"
#include "exercise4.hpp"
#include "exercise5.hpp"
#include <iterator>

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

TEST(exercise2, getNthElementFromEnd)
{
    auto list = forward_list<int>{1,2,3,4,5,6,7,8,9,0};
    auto N = 4;
    auto expected = 7;  
    auto result = getNthElementFromEnd(list,4);
    GTEST_ASSERT_EQ(result, expected);
}

TEST(exercise2, getNthElementFromEndLast)
{
    auto list = forward_list<int>{1,2,3,4,5,6,7,8,9,0};
    auto N = 10;
    auto expected = 1;  
    auto result = getNthElementFromEnd(list,N);
    GTEST_ASSERT_EQ(result, expected);
}

TEST(exercise3, deleteMiddleElement)
{
    auto listChar = forward_list<char>{'e', 'd', 'c', 'b', 'a'};
    auto expected = forward_list<char>{'e', 'd', 'b', 'a'};
    auto itMid = listChar.begin();
    advance(itMid, 2);
    deleteMiddleElement(listChar,itMid);
    GTEST_ASSERT_EQ(listChar, expected);
}

TEST(exercise3, deleteMiddleElementFirst)
{
    auto listChar = forward_list<char>{'e', 'd', 'c', 'b', 'a'};
    auto expected = forward_list<char>{'d', 'c', 'b', 'a'};
    auto itMid = listChar.begin();
    deleteMiddleElement(listChar,itMid);
    GTEST_ASSERT_EQ(listChar, expected);
}

TEST(exercise4, partitionateX)
{
    auto listChar = forward_list<char>{'e', 'd', 'c', 'b', 'a'};
    auto X = 'c';
    partitionateX(listChar, X);
    bool validSolution = verifySolution(listChar, X);
    GTEST_ASSERT_EQ(validSolution, true);
}

TEST(exercise4, partitionateXSmallerElement)
{
    auto listChar = forward_list<char>{'e', 'd', 'c', 'b', 'a'};
    auto X = '0';
    partitionateX(listChar, X);
    bool validSolution = verifySolution(listChar, X);
    GTEST_ASSERT_EQ(validSolution, true);
}

TEST(exercise4, partitionateXGreatherElement)
{
    auto listChar = forward_list<char>{'e', 'd', 'c', 'b', 'a'};
    auto X = 'z';
    partitionateX(listChar, X);
    bool validSolution = verifySolution(listChar, X);
    GTEST_ASSERT_EQ(validSolution, true);
}

TEST(exercise4, partitionateXCheckSolutionVerifier)
{
    auto listChar = forward_list<char>{'e', 'd', 'c', 'b', 'a'};
    auto X = 'c';
    bool validSolution = verifySolution(listChar, X);
    GTEST_ASSERT_EQ(validSolution, false);
}

TEST(exercise5, add)
{
    auto num1 = forward_list<char>{'7', '1', '6'};
    auto num2 = forward_list<char>{'5', '9', '2'};
    auto expected = forward_list<char>{'2', '1', '9'};
    auto res = add(num1,num2);
    GTEST_ASSERT_EQ(res, expected);
}

TEST(exercise5, addForward)
{
    auto num1 = forward_list<char>{'6', '1', '7'};
    auto num2 = forward_list<char>{'2', '9', '5'};
    auto expected = forward_list<char>{'9', '1', '2'};
    auto res = addForward(num1,num2);
    GTEST_ASSERT_EQ(res, expected);
}

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}