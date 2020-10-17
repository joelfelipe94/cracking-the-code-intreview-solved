#include <gtest/gtest.h>
#include "exercise1.hpp"
#include "exercise2.hpp"
#include "exercise3.hpp"

// Exercise 1

TEST(exercise1, Insert0)
{
    ThreeStacks<int> stacks(9);
    stacks.push(10, 0);
    auto isEmpty = stacks.empty(0);
    GTEST_ASSERT_EQ(isEmpty,false);
}
TEST(exercise1, Insert1)
{
    ThreeStacks<int> stacks(9);
    stacks.push(10, 1);
    auto isEmpty = stacks.empty(1);
    GTEST_ASSERT_EQ(isEmpty,false);
}

TEST(exercise1, Insert2)
{
    ThreeStacks<int> stacks(9);
    stacks.push(10, 2);
    auto isEmpty = stacks.empty(2);
    GTEST_ASSERT_EQ(isEmpty,false);
}

TEST(exercise1, InsertThrow)
{
    ThreeStacks<int> stacks(9);
    stacks.push(10, 2);
    stacks.push(10, 2);
    stacks.push(10, 2);
    
    EXPECT_THROW(stacks.push(10, 2), const char*);
}

TEST(exercise1, IsEmpty)
{
    ThreeStacks<int> stacks(9);
    auto isEmpty = stacks.empty(1);
    GTEST_ASSERT_EQ(isEmpty,true);
}

TEST(exercise1, top)
{
    ThreeStacks<int> stacks(9);
    stacks.push(10, 2);
    auto topValue = stacks.top(2);
    GTEST_ASSERT_EQ(topValue,10);
}

TEST(exercise1, topThrow)
{
    ThreeStacks<int> stacks(9);
    EXPECT_THROW(stacks.top(2), const char*);
}


// Exercise 2

TEST(exercise2, min)
{
    Stack<int> stk({2,3,4,2,1,4}) ;
    auto minValue = stk.min();
    GTEST_ASSERT_EQ(minValue,1);
}

TEST(exercise2, pop)
{
    Stack<int> stk({2,3,4,2,1,4}) ;
    stk.pop();
    stk.pop();
    auto minValue = stk.min();
    GTEST_ASSERT_EQ(minValue,2);
}

TEST(exercise2, top)
{
    Stack<int> stk({2,3,4,2,1,4}) ;
    auto topValue = stk.top();
    GTEST_ASSERT_EQ(topValue, 4);
}

TEST(exercise2, push)
{
    Stack<int> stk;
    stk.push(10);
    auto topValue = stk.top();
    GTEST_ASSERT_EQ(topValue, 10);
}

// Exercise 3

TEST(exercise3, push)
{
    SetOfStacks<int> sos;
    sos.push(10);
    auto result = sos.top(); 
    GTEST_ASSERT_EQ(result, 10);
}

TEST(exercise3, pop)
{
    SetOfStacks<int> sos;
    sos.push(20);
    sos.push(10);
    sos.pop();
    auto result = sos.top(); 
    GTEST_ASSERT_EQ(result, 20);
}

TEST(exercise3, popAt)
{
    SetOfStacks<int> sos(2);
    sos.push(30);
    sos.push(20);
    sos.push(10);
    sos.popAt(0);
    sos.pop(); 
    auto result = sos.top();
    GTEST_ASSERT_EQ(result, 30);
}

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}