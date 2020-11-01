// Implement a function to check if a binary tree is a binary search tree.
#include "exercise1.hpp"
#include <stack>

template <typename T>
bool Tree<T>::isBinarySearchTree(){
    std::stack< NodeTree<T>* > parent;
    // the empty tree is a binary search tree
    if(root == nullptr)
        return true;
    // go to the leftmost element    
    auto currNode = root;
    while(currNode->left!=nullptr)
    {
        parent.push(currNode); //keep the parent when going to the left
        currNode = currNode->left;
    }

    // the leftmost node will be the first in the sequence
    auto previousNode = currNode;
    // navigate the tree inorder checking the current element agains the previous
    while (currNode->right != nullptr || !parent.empty())
    {
        if(currNode->right != nullptr){
            currNode = currNode->right;
        }
        else
        {
            currNode = parent.top();
            parent.pop();
        }
        // if the previous elemnt is greater than the current return false
        if(previousNode->data > currNode->data)
            return false;
        previousNode = currNode;
    }
    
    return true;
    
    
}