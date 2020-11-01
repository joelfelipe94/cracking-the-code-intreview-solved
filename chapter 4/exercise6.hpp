// Write an algorithm to find the'next'node (i.e., in-order successor) of a given node
// in a binary search tree. You may assume that each node has a link to its parent.

template <typename T>
struct NodeTreeWP // nodeTreeWithParent
{
    NodeTreeWP<T> *right;
    NodeTreeWP<T> *left;
    NodeTreeWP<T> *parent;
    T data;
    NodeTreeWP(T data, NodeTreeWP<T> *right = nullptr, NodeTreeWP<T> *left = nullptr,
               NodeTreeWP<T> *parent = nullptr);
    void addToLeft(NodeTreeWP<T> *leftChild);
    void addToRight(NodeTreeWP<T> *rightChild);
};

template <typename T>
NodeTreeWP<T>::NodeTreeWP(T data, NodeTreeWP<T> *right,
                          NodeTreeWP<T> *left, NodeTreeWP<T> *parent)
    : right(right), left(left), data(data), parent(parent)
{
}

template <typename T>
NodeTreeWP<T> *nextNode(NodeTreeWP<T> *source)
{
    if (source == nullptr)
        return nullptr;
    NodeTreeWP<T> *node = nullptr;
    // if there is a subtree in the right
    if (source->right != nullptr)
    {
        node = source->right;
        // get the leftmost element
        while (node->left != nullptr)
        {
            node = node->left;
        }
        return node;
    }
    else
    {
        // go to the parent from the left subtree
        while (source->parent != nullptr)
        {
            node = source->parent;
            if (node->left == source)
                return node;
            else
            {
                source = node;
            }
        }
        return nullptr; // there is no next element
    }
}

template <class T>
void NodeTreeWP<T>::addToLeft(NodeTreeWP<T> *leftChild)
{
    this->left = leftChild;
    leftChild->parent = this;
}
template <class T>
void NodeTreeWP<T>::addToRight(NodeTreeWP<T> *rightChild)
{
    this->right = rightChild;
    rightChild->parent = this;
}