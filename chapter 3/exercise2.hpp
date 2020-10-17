// How would you design a stack which, in addition to push and pop, also has a
// function min which returns the minimum element? Push, pop and min should
// all operate in O(1) time.

#include<stack>

template<class T>
class Stack{
public:
    Stack();
    Stack(std::initializer_list<T> l);
    T top();
    void pop();
    void push(const T& value);
    T min();
private:
    std::stack<T> stack_;
    std::stack<T> stackMin_;
};

template<class T>
Stack<T>::Stack(){
}

template<class T>
Stack<T>::Stack(std::initializer_list<T> l){
    for(auto& value: l)
        push(value);
}


template<class T>
void Stack<T>::push(const T& value){
    stack_.push(value);
    if(stackMin_.empty() || value <= stackMin_.top()){
        stackMin_.push(value);
    }
}

template<class T>
void Stack<T>::pop(){
    if(stack_.top() == stackMin_.top())
        stackMin_.pop();
    stack_.pop();
}

template <class T>
T Stack<T>::top(){
    return stack_.top();
}

template <class T>
T Stack<T>::min(){
    return stackMin_.top();
}