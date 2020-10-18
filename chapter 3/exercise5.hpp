// Implement a MyQueue class which implements a queue using two stacks.
#include<stack>
#include<exception>
template <class T>
class DoubleStackQueue{
public:
    void enqueue(const T& value);
    T dequeue();
private:
    std::stack<T> front, back;
};
template <class T>
void DoubleStackQueue<T>::enqueue(const T & value){
    back.push(value);
}

template <class T>
T DoubleStackQueue<T>::dequeue(){
    if(front.empty())
    {
        while(!back.empty())
        {
            front.push(back.top());
            back.pop();
        }
    }
    if(front.empty())
        throw std::logic_error("Unable to dequeue empty queue");
    auto value= front.top();
    front.pop();
    return value;
}
