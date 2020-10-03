// Implement an algorithm to find the kth to last element of a singly linked list.
#pragma once
#include <forward_list>
#include <cassert>
using namespace std;

template <typename T>
size_t getLength(const forward_list<T>& list){
    auto length = size_t(0);
    for(auto value : list){
        length++;
    }
    return length;
}

template <typename T>
T getNthElementFromEnd(forward_list<T>& list, size_t N){
    auto length = getLength(list);
    assert(N > 0 && N <= length); // we count from zero to the maximum size
    auto K = length - N;
    auto count = size_t(0);
    for(auto it=list.begin();it!=list.end();it++, count++){
        if(count==K){
           return *it; 
        }
    }
}