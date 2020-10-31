// Given a sorted (increasing order) array with unique integer elements, write an
// algorithm to create a binary search tree with minimal height.
#include"exercise1.hpp"

NodeTree <int> * makeBynaryTree(int *arr, size_t length)
{
    if(length == 0)
        return nullptr;
    else
    {
        auto root = new NodeTree<int>(arr[length/2], 
                                  makeBynaryTree(arr+length/2+1, length - length/2 -1),
                                  makeBynaryTree(arr,length/2));
        return root;
    }
}

void inOrderVisit(NodeTree <int> * root, std::vector<int> &result)
{
    if(root != nullptr)
    {
        inOrderVisit(root->left, result);
        result.push_back(root->data);
        inOrderVisit(root->right, result);
    }
}