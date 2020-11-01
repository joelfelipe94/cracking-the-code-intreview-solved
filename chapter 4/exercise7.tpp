// Design an algorithm and write code to find the first common ancestor of two
// nodes in a binary tree. Avoid storing additional nodes in a data structure. NOTE:
// This is not necessarily a binary search tree.
#include "exercise1.hpp"
// I reused the binary tree logic. But this logic can be easelly extended
// for other tree types
template <typename T>
int Tree<T>::firstCommonAncestor(NodeTree<T> *root, NodeTree<T> *&result, //exercise 7
                                  NodeTree<T> *a, NodeTree<T> *b)
{
    int output = 0;
    if(root == nullptr)
        return 0;
    output = firstCommonAncestor(root->left, result, a, b) + 
             firstCommonAncestor(root->right, result, a, b); 
    if(a==root)
        output++;
    if(b==root)
        output++;
    if(output == 2 && result== nullptr)
        result = root;
    return output;
}
template <typename T>
NodeTree<T> *Tree<T>::firstCommonAncestor(NodeTree<T> *a, NodeTree<T> *b)
{
    NodeTree<T> *result = nullptr;
    firstCommonAncestor(root, result, a, b);
    return result;
}