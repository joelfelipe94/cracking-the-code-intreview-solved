// Imagine a (literal) stack of plates. If the stack gets too high, it might topple.
// Therefore, in real life, we would likely start a new stack when the previous stack
// exceeds some threshold. Implement a data structure SetOf Stacks that mimics
// this. SetOf Stacks should be composed of several stacks and should create a
// new stack once the previous one exceeds capacity. SetOf Stacks. push() and
// SetOf Stacks. pop() should behave identically to a single stack (that is, popO
// should return the same values as it would if there were just a single stack).
#include <cstddef>
#include <vector>
#include <stack>

template <class T>
class SetOfStacks{
public:
    SetOfStacks(size_t maxSize=100);
    void push(const T &value);
    void pop();
    void popAt(size_t index);
    T top();
private:
    size_t maxSize;
    size_t size;
    std::vector< std::stack<T> > stacksVec;
};

template <class T>
SetOfStacks<T>::SetOfStacks(size_t size)
:size(0)
,maxSize(size)
{}

template <class T>
void SetOfStacks<T>::push(const T& value)
{
    if(stacksVec.empty() || stacksVec.back().size() >= maxSize)
        stacksVec.push_back(stack<T>());
    stacksVec.back().push(value);
}

template <class T>
T SetOfStacks<T>::top()
{
    return stacksVec.back().top();
}

template <class T>
void SetOfStacks<T>::pop()
{
    if(stacksVec.empty())
        return;
    if(!stacksVec.back().empty())
        stacksVec.back().pop();
    if(stacksVec.back().empty())
        stacksVec.pop_back();
}

// Implement a function popAt(int index) which performs a pop operation on
// a specific sub-stack.

template <class T>
void SetOfStacks<T>::popAt(size_t index){
    stacksVec[index].pop();
}

