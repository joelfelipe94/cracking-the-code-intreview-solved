#include <gtest/gtest.h>
#include <vector>
#include "exercise1.hpp"
#include "exercise2.hpp"
#include "exercise3.hpp"
#include "exercise4.hpp"
#include "exercise5.hpp"
#include "exercise6.hpp"

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

// Exercise 4

TEST(exercise4, TowersOfHanoi)
{
    vector<Tower> towers = {Tower(5), Tower(0), Tower(0)};
    towers[0].moveToTower(5, towers[1], towers[2]);
    vector<Tower> expected = {Tower(0), Tower(0), Tower(5)};
    GTEST_ASSERT_EQ(towers, expected);
}

// Exercise 5

TEST(exercise5, singleValueDequeue)
{
    DoubleStackQueue<int> dsq;
    dsq.enqueue(1);
    auto result = dsq.dequeue();
    GTEST_ASSERT_EQ(result, 1);
}

TEST(exercise5, multipleValuesDequeue)
{
    DoubleStackQueue<int> dsq;
    dsq.enqueue(1);
    dsq.enqueue(2);
    dsq.enqueue(3);
    dsq.dequeue(); //dequeue 1
    dsq.dequeue(); //dequeue 2
    auto result = dsq.dequeue(); //dequeue 3
    GTEST_ASSERT_EQ(result, 3);
}

TEST(exercise5, emptyQueueDequeue)
{
    DoubleStackQueue<int> dsq;
    try {
        dsq.dequeue();
        FAIL() << "Expected std::logic_error";
    }
    catch(std::logic_error const & err) {
        EXPECT_EQ(err.what(),std::string("Unable to dequeue empty queue"));
    }
    catch(...) {
        FAIL() << "Expected std::logic_error";
    }
}

// Exercise 6

TEST(exercise6, stackSort)
{
    std::stack<int> stk;
    for (auto& item : {6, 5, 4, 4, 1, 2, 3}) {
        stk.push(item);
    }
    std::stack<int> expected;
    for (auto& item : {1, 2, 3, 4, 4, 5, 6}) {
        expected.push(item);
    }

    sort(stk);
    GTEST_ASSERT_EQ(stk, expected);
}

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}