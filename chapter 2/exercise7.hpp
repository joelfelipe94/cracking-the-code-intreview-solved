#include <forward_list>
// Implement a function to check if a linked list is a palindrome.
template <typename T>
bool isPalindrome(std::forward_list<T> fList){
    auto reverseFList = fList;
    reverseFList.reverse();
    return reverseFList == fList;
}