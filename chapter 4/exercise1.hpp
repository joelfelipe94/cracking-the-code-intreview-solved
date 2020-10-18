// Implement a function to check if a binary tree is balanced. For the purposes of
// this question, a balanced tree is defined to be a tree such that the heights of the
// two subtrees of any node never differ by more than one.
#include<cmath> //abs
#include<algorithm> //max
#include<exception> //logic_error
#include<stack>
template <class T>
struct NodeTree
{

    NodeTree<T> *right;
    NodeTree<T> *left;
    T data;
    NodeTree(T data, NodeTree<T>*right, NodeTree<T> *left);
};

template<class T>
class Tree
{
    NodeTree<T> *root;
    int isBalancedRec(NodeTree<T> *node);
    void addToAdress(T data, NodeTree<T> *&node);
public:
    NodeTree<T> * addToRoot(T data);
    NodeTree<T> * addToLeft(T data, NodeTree<T> *node);
    NodeTree<T> * addToRight(T data, NodeTree<T> *node);
    bool isBalanced();
    Tree();
    ~Tree();
};

template<class T>
NodeTree<T>::NodeTree(T data,NodeTree<T>*right,NodeTree<T> *left)
:right(right)
,left(left)
,data(data)
{}

template<class T>
bool Tree<T>::isBalanced()
{
    return isBalancedRec(root) != -1;
}

template<class T>
int Tree<T>::isBalancedRec(NodeTree<T> *node)
{
    if(node == nullptr)
        return 0;
    else
    {
        auto rightSize = isBalancedRec(node->right);
        auto leftSize = isBalancedRec(node->left);
        if(std::abs(rightSize-leftSize) > 1 || rightSize == -1 || leftSize == -1)
            return -1;
        else
            return 1 + std::max(rightSize, leftSize);
    }
}

template <class T>
Tree<T>::Tree()
:root(nullptr)
{}

template <class T>
Tree<T>::~Tree()
{
    std::stack< NodeTree<T>* > nodesToErase;
    nodesToErase.push(root);
    while(!nodesToErase.empty()){
        auto node = nodesToErase.top();
        nodesToErase.pop();
        if(node->left != nullptr)
            nodesToErase.push(node->left);
        if(node->right != nullptr)
            nodesToErase.push(node->right);
        delete node;
    }
}

template <class T>
void Tree<T>::addToAdress(T data, NodeTree<T> *&node){ 
    if(node == nullptr)
    {
        node = new NodeTree<T>(data, nullptr, nullptr);
    }
    else
    {
        node->data = data;
    }
}

template <class T>
NodeTree<T> * Tree<T>::addToRoot(T data){
    if(root == nullptr)
    {
        root = new NodeTree<T>(data, nullptr, nullptr);
    }
    else
    {
        root->data = data;
    }
    return root;
}

template <class T>
NodeTree<T> * Tree<T>::addToLeft(T data, NodeTree<T> *node)
{
    if(node == nullptr)
        throw std::logic_error("Cannot add to the left of a null node.");
    addToAdress(data, node->left);
    return node->left;
}
template <class T>
NodeTree<T> * Tree<T>::addToRight(T data, NodeTree<T> *node)
{
    if(node == nullptr)
        throw std::logic_error("Cannot add to the right of a null node.");
    addToAdress(data, node->right);
    return node->right;
}