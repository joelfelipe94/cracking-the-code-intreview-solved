#include <initializer_list>
#include <iostream>
template <typename T>
class Node
{
private:
    T data;
    Node<T> *next;
public:
    Node();
    Node(std::initializer_list<T> l);
    Node(const T& data, Node<T> *next=nullptr);
    Node<T>* findLoopStart();
    void createLoop(Node<T> *node);
    void append(const T &data);
    Node<T>* getNth(size_t N);
    template <typename U>
    friend std::ostream & operator << (std::ostream &out, const Node<U> &node);
    ~Node();
};

template<typename T>
Node<T>::Node()
    :next(nullptr)
{}


template<typename T>
Node<T>::Node(const T &data, Node<T> *next)
    :data(data)
    ,next(next)
{}

template<typename T>
Node<T>::Node(std::initializer_list<T> l){
    Node<T> *n=this;
    int i=0;
    for(auto &value :l){
        n->data=value;
        if(i + 1 < l.size())
            n->next= new Node<T>();
        n=n->next;
        i++; 
    }
}

template <typename T>
Node<T>::~Node()
{
}

template <typename T>
void Node<T>::append(const T&data){
    auto n=this;
    while(n->next != nullptr){
        n=n->next;
    }
    n->next = new Node<T>(data);
}

template <typename T>
void Node<T>::createLoop(Node<T> *node){
    auto n=this;
    while(n->next != nullptr){
        n=n->next;
    }
    n->next = node;
}

template <typename T>
Node<T>* Node<T>::getNth(size_t N){
    auto n=this;
    for(auto i=1;n->next != nullptr && i<N; i++){
        n=n->next;
    }
    return n;
}

template <class T>
std::ostream & operator << (std::ostream &out, const Node<T> &node)
{
    auto i=0, limit = 30;
    out << node.data;
    auto n = node.next;
    while(n!=nullptr && i<limit){
        out << " -> " << n->data; 
        n = n-> next;
        i++;
    }
    return out;
}

// Given a circular linked list, implement an algorithm which returns the node at
// the beginning of the loop.
template <typename T>
Node<T>* Node<T>::findLoopStart(){
    auto slow=this, fast=this;
    while(fast!=nullptr && fast->next!=nullptr){
        slow=slow->next;
        fast=fast->next->next;
        if(slow==fast)
            break;
    }
    if(fast == nullptr || fast->next == nullptr)
        return nullptr;
    slow=this;
    while (slow!=fast)
    {
        slow=slow->next;
        fast=fast->next;
    }
    return fast;
}
