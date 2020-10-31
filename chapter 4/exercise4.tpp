#include<vector>
#include<list>
#include"exercise1.hpp"

// Given a binary tree, design an algorithm which creates a linked list of all the
// nodes at each depth (e.g., if you have a tree with depth D, you'll have D linked
//lists)

template <typename T>
std::vector< std::list< NodeTree<T> > > Tree<T>::makeLists(){
    std::vector< std::list< NodeTree<T> > > lists;
    makeListsRec(root, lists, 0);
    return lists;
} 

template <class T>
void 
Tree<T>::makeListsRec(NodeTree<T> *node, std::vector< std::list< NodeTree<T> > > &vec,
                      int level){
    if(node == nullptr)
        return;
    makeListsRec(node->left, vec, level+1);
    makeListsRec(node->right, vec, level + 1);
    if(vec.size() <= level)
        vec.resize(level + 1);
    vec[level].push_back(*node);
}