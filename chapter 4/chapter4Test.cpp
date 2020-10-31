#include <gtest/gtest.h>
#include "exercise1.hpp"
#include "exercise2.hpp"
#include "exercise3.hpp"

// Exercise 1

TEST(exercise1, balancedTree)
{
    Tree <int> tree;
    auto root=tree.addToRoot(1);
    tree.addToLeft(2, root);
    tree.addToRight(3, root);
    auto result = tree.isBalanced();
    GTEST_ASSERT_EQ(result,true);
}

TEST(exercise1, unbalancedTree)
{
    Tree <int> tree;
    auto root = tree.addToRoot(1);
    auto leftRoot = tree.addToLeft(2, root);
    tree.addToLeft(3, leftRoot);
    auto result = tree.isBalanced();
    GTEST_ASSERT_EQ(result,false);
}

// Exercise 2

TEST(exercise2, isConnected)
{
    NodeGraph <char> nodeD('D'), nodeC('C'), nodeB('B'), nodeA('A');
    nodeC.adjacents.push_back(&nodeD); // C-> D
    nodeA.adjacents.push_back(&nodeB); // A->B
    nodeA.adjacents.push_back(&nodeC); // A->C
    auto result = isConnected(&nodeA, &nodeD);
    GTEST_ASSERT_EQ(result,true);
}

TEST(exercise2, isConnectedFalse)
{
    NodeGraph <char> nodeD('D'), nodeC('C'), nodeB('B'), nodeA('A');
    nodeD.adjacents.push_back(&nodeC); // D-> C
    nodeA.adjacents.push_back(&nodeB); // A->B
    nodeA.adjacents.push_back(&nodeC); // A->C
    auto result = isConnected(&nodeD, &nodeB);
    GTEST_ASSERT_EQ(result,false);
}

TEST(exercise3, makeBynaryTree)
{
    auto input = std::vector<int>{1,2,3,4,5};
    auto result = makeBynaryTree(&input[0], input.size());
    std::vector<int> resultVec;
    inOrderVisit(result,resultVec);
    GTEST_ASSERT_EQ(resultVec,input);
}


int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}