// You have two numbers represented by a linked list, where each node contains a
// single digit. The digits are stored in reverse order, such that the Ts digit is at the
// head of the list. Write a function that adds the two numbers and returns the sum
// as a linked list.

#include <algorithm>
#include "exercise2.hpp"
using namespace std;


void expandNumber(forward_list<char> &num, size_t sizeDiff){
    for(auto i=0; i < sizeDiff; i++)
        num.push_front('0');
}

forward_list<char> 
internalAdd(forward_list<char> num1, forward_list<char> num2){
    auto size1 = getLength(num1);
    auto size2 = getLength(num2);
    forward_list<char> res;
    if (size1 < size2)
        expandNumber(num1, size2 - size1);
    else if(size2 > size1)
        expandNumber(num2, size1 - size2);
    char carry = 0;
    for(auto it1=num1.begin(), it2=num2.begin() ; it1 != num1.end(); it1++, it2++){
        auto d1 = *it1 - '0';
        auto d2 = *it2 - '0';
        auto r = (carry + d1 + d2) % 10;
        carry = (carry + d1 + d2) / 10;
        res.push_front(r + '0');
    }
    if(carry > 0)
        res.push_front(carry + '0');
    return res;
}


forward_list<char> add(const forward_list<char> &num1, const forward_list<char> &num2){
    auto res = internalAdd(num1, num2);
    res.reverse();
    return res;
}

// Suppose the digits are stored in forward order. Repeat the above problem.
forward_list<char> addForward(forward_list<char> num1, forward_list<char> num2){
    num1.reverse();
    num2.reverse();
    return internalAdd(num1, num2);
}