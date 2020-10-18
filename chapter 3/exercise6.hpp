// Write a program to sort a stack in ascending order (with biggest items on top).
// You may use at most one additional stack to hold items, but you may not copy
// the elements into any other data structure (such as an array). The stack supports
// the following operations: push, pop, peek, and isEmpty.
#include<stack>
template <class T>
void sort(std::stack<T> &inStack){
    stack<T> auxStack; 
    while (!inStack.empty())
    {
        auxStack.push(inStack.top());
        inStack.pop();
        while (!auxStack.empty() && !inStack.empty() 
                && inStack.top() > auxStack.top()){
            auto value = inStack.top();
            inStack.pop();
            inStack.push(auxStack.top());
            auxStack.pop();
            inStack.push(value);

        }
    }
    while (!auxStack.empty())
    {
        inStack.push(auxStack.top());
        auxStack.pop();
    }
}