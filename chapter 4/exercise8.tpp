// You have two very large binary trees: T1, with millions of nodes, and T2, with
// hundreds of nodes. Create an algorithm to decide if T2 is a subtree of T1.
// A tree T2 is a subtree of T1 if there exists a node n in T1 such that the subtree of
// n is identical to T2. That is, if you cut off the tree at node n, the two trees would
// be identical.
#include"exercise1.hpp"

template<class T>
bool compareTrees(NodeTree<T>* T1, NodeTree<T>* T2){
    if(T1 == nullptr || T2 == nullptr)
        return T1 == T2;
    std::stack< NodeTree<T>* > toVisit1, toVisit2;
    toVisit1.push(T1);
    toVisit2.push(T2);
    while (!toVisit1.empty() && !toVisit2.empty())
    {
        auto top1 = toVisit1.top();
        auto top2 = toVisit2.top();
        toVisit2.pop();
        toVisit1.pop();
        if(top1->data != top2->data){
            return false;
        }
        if(top1->left == nullptr || top2->left == nullptr)
            return top1->left == top2->left;
        else{
            toVisit1.push(top1->left);
            toVisit2.push(top2->left);
        }
        if(top1->right == nullptr || top2->right == nullptr)
            return top1->right == top2->right;
        else{
            toVisit1.push(top1->right);
            toVisit2.push(top2->right);
        }   
    }
    return true;
}

template<class T>
bool Tree<T>::hasSubtree(Tree<T> &T2){
    std::stack<NodeTree<T>*> toVisit;
    toVisit.push(root);
    while (!toVisit.empty())
    {
        auto currNode = toVisit.top();
        if(compareTrees(currNode, T2.root))
            return true;
        else
        {
            toVisit.pop();
            if(currNode->left != nullptr)
                toVisit.push(currNode->left);
            if(currNode->right != nullptr)
                toVisit.push(currNode->right);
        }
    }
    return false;
}
