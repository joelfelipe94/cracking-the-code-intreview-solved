// Describe how you could use a single array to implement three stacks
#include<unordered_set>
#include<forward_list>
#include<vector>
using namespace std;


template<class T>
class ThreeStacks{
    size_t size;
    size_t botton[3], ceiling[3];
    vector<T> arr;
public:
    ThreeStacks(size_t size);
    void push(const T& value, int stackIndex);
    void pop(int stackIndex);
    bool empty(int stackIndex);
    T top(int stackIndex);
};

template<class T>
ThreeStacks<T>::ThreeStacks(size_t size)
    :size(size)
    ,arr(size)
{
    for(auto i = 0; i < 3; i++)
    {
        botton[i] = i*size/3;
        ceiling[i] = i*size/3;
    }
}

template<class T>
void ThreeStacks<T>::push(const T& value, int stackIndex){
    auto nextStack = (stackIndex+1)%3;
    if((stackIndex == 2 && ceiling[stackIndex] < size) ||  
       (stackIndex != 2 && ceiling[stackIndex] < botton[stackIndex + 1]))
    {
        arr[ceiling[stackIndex]] = value;
        ceiling[stackIndex]++;
    }
    else
        throw "Not enough space.";
}

template <class T>
void ThreeStacks<T>::pop(int stackIndex)
{
    if(top[stackIndex] > botton[stackIndex])
        ceiling[stackIndex]--;
}

template <class T>
T ThreeStacks<T>::top(int stackIndex)
{
    if(ceiling[stackIndex] > botton[stackIndex])
        return arr[ceiling[stackIndex] - 1];
    else 
        throw "This stack is empty";
}

template <class T>
bool ThreeStacks<T>::empty(int stackIndex)
{
    return ceiling[stackIndex] == botton[stackIndex];
}
