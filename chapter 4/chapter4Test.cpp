#include <gtest/gtest.h>
#include "exercise1.hpp"
#include "exercise2.hpp"
#include "exercise3.hpp"
#include "exercise6.hpp"

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

// Exercise 3

TEST(exercise3, makeBynaryTree)
{
    auto input = std::vector<int>{1,2,3,4,5};
    auto result = makeBynaryTree(&input[0], input.size());
    std::vector<int> resultVec;
    inOrderVisit(result,resultVec);
    GTEST_ASSERT_EQ(resultVec,input);
}

// Exercise 4 

TEST(exercise4, makeListFirst)
{
    Tree<int> tree;
    auto root = tree.addToRoot(1);
    auto leftChild = tree.addToLeft(2, root);
    auto leftGrandChild = tree.addToLeft(3, leftChild);
    auto result = tree.makeLists();
    std::vector< std::list< NodeTree<int> > > expected(3);
    expected[0].push_back(*root);
    expected[1].push_back(*leftChild);
    expected[2].push_back(*leftGrandChild);
    GTEST_ASSERT_EQ(result,expected);
}

TEST(exercise4, makeListsSecond)
{
    Tree<int> tree;
    auto root = tree.addToRoot(1);
    auto leftChild = tree.addToLeft(2, root);
    auto rightChild = tree.addToRight(3, root);
    auto result = tree.makeLists();
    std::vector< std::list< NodeTree<int> > > expected(2);
    expected[0].push_back(*root);
    expected[1].push_back(*leftChild);
    expected[1].push_back(*rightChild);
    GTEST_ASSERT_EQ(result,expected);
}

TEST(exercise4, makeListsEmpty)
{
    Tree<int> tree;
    auto result = tree.makeLists();
    std::vector< std::list< NodeTree<int> > > expected;
    GTEST_ASSERT_EQ(result,expected);
}

// Exercise 5

TEST(exercise5, isBinarySearchTreeTrue)
{
    Tree <int> tree;
    auto root=tree.addToRoot(2);
    tree.addToLeft(1, root);
    tree.addToRight(3, root);
    GTEST_ASSERT_EQ(tree.isBinarySearchTree(),true);
}


TEST(exercise5, isBinarySearchTreeFalse)
{
    Tree <int> tree;
    auto root=tree.addToRoot(1);
    tree.addToLeft(2, root);
    tree.addToRight(3, root);
    GTEST_ASSERT_EQ(tree.isBinarySearchTree(),false);
}

TEST(exercise5, isBinarySearchTreeEmpty)
{
    Tree <int> tree;
    GTEST_ASSERT_EQ(tree.isBinarySearchTree(),true);
}

// Exercise 6

TEST(exercise6, nextNodeNullptr)
{
    auto result = nextNode<int>( nullptr);
    decltype(result) expected = nullptr;
    GTEST_ASSERT_EQ(result, expected);
}


TEST(exercise6, nextNodeNoNext)
{
    NodeTreeWP<int> root(1), leftChild(0), rightChild(2);
    root.addToLeft(&leftChild);
    root.addToRight(&rightChild);
    auto result = nextNode<int>( &rightChild);
    GTEST_ASSERT_EQ(result, nullptr);
}

TEST(exercise6, nextNodeFromLeft)
{
    NodeTreeWP<int> root(1), leftChild(0), rightChild(2);
    root.addToLeft(&leftChild);
    root.addToRight(&rightChild);
    auto result = nextNode<int>( &leftChild);
    GTEST_ASSERT_EQ(result, &root);
}

TEST(exercise6, nextNodeFromParent)
{
    NodeTreeWP<int> root(1), leftChild(0), rightChild(2);
    root.addToLeft(&leftChild);
    root.addToRight(&rightChild);
    auto result = nextNode<int>( &root);
    GTEST_ASSERT_EQ(result, &rightChild);
}

TEST(exercise6, nextNodeFromLeftGrandchild)
{
    NodeTreeWP<int> root(1), leftChild(0), rightChild(2), leftGrandchild(1);
    root.addToLeft(&leftChild);
    leftChild.addToRight(&leftGrandchild);
    root.addToRight(&rightChild);
    auto result = nextNode<int>( &leftGrandchild);
    GTEST_ASSERT_EQ(result, &root);
}

TEST(exercise6, nextNodeFromGrandParent)
{
    NodeTreeWP<int> root(1), leftChild(0), rightChild(2), rightGrandchild(3);
    root.addToLeft(&leftChild);
    root.addToRight(&rightChild);
    rightChild.addToLeft(&rightGrandchild);
    auto result = nextNode<int>( &root);
    GTEST_ASSERT_EQ(result, &rightGrandchild);
}

int main(int argc, char* argv[])
{
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}