// Implement an algorithm to delete a node in the middle of a singly linked list,
// given only access to that node.
#include<forward_list>
#include<cassert>


// It does not work for the last element because it woult require an Iterator
// to the previou element. But it works for the first element.
template <typename T>
void deleteMiddleElement(std::forward_list<T>fList, typename std::forward_list<T>::iterator &midIt){
    auto nextIt = midIt;
    nextIt++;
    assert(nextIt != fList.end());
    (*midIt) = (*nextIt);
    fList.erase_after(midIt);
}
