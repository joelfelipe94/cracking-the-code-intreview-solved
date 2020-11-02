#include "exercise1.hpp"
#include "iostream"
// You are given a binary tree in which each node contains a value. Design an algo-
// rithm to print all paths which sum to a given value. The path does not need to
// start or end at the root or a leaf.

template <typename T>
void Tree<T>::printSum(T targetSum)
{
    std::list<NodeTree<T>*> path = {root};
    if(root != nullptr)
        printSumRec(path, root->data, targetSum);
}

template <typename T>
void Tree<T>::printSumRec(std::list<NodeTree<T>*> path, T sum, T targetSum)
{
    if(path.empty())
        return;
    if(sum == targetSum)
        printPath(path);
    auto last = path.back();
    
    auto &lastLeftChild = last->left;
    if(lastLeftChild != nullptr)
    {
        auto pathLeft = path;
        pathLeft.push_back(lastLeftChild);
        printSumRec(pathLeft, sum + lastLeftChild->data, targetSum);
    }
    
    auto &lastRightChild = last->right;
    if(lastRightChild != nullptr)
    {
        auto pathRight = path;
        pathRight.push_back(lastRightChild);
        printSumRec(pathRight, sum + lastRightChild->data, targetSum);
    }
    auto pathFront = path.front()->data;
    path.pop_front();
    printSumRec(path, sum - pathFront, targetSum);
}

template <typename T>
void Tree<T>::printPath(std::list<NodeTree<T>*> path){
    for(auto element: path){
        if(element != nullptr)
            std::cout<<element->data<<"->";
    }
    std::cout<<"END"<<std::endl;
}