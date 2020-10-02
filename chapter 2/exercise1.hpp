// Write code to remove duplicates from an unsorted linked list.
// FOLLOW UP
// How would you solve this problem if a temporary buffer is not allowed?
#include<unordered_set>
#include<forward_list>
using namespace std;



// Write code to remove duplicates from an unsorted linked list.
template<class T>
void removeDuplicates(forward_list<T> &listDuplicates){
    unordered_set<T> historic;
    auto itBefore=listDuplicates.before_begin();
    for(auto it=listDuplicates.begin();it!=listDuplicates.end(); ){
        if(historic.count(*it)==1){
            it = listDuplicates.erase_after(itBefore);
        }
        else{
            historic.insert(*it);
            it++;
            itBefore++;
        }
    }
}

// How would you solve this problem if a temporary buffer is not allowed?
template<class T>
void removeDuplicatesInPlace(forward_list<T> &listDuplicates){
    for (auto itSlow = listDuplicates.begin(); itSlow!=listDuplicates.end(); itSlow++){
        auto itBefore=itSlow;
        auto it=itSlow;
        for(++it;it!=listDuplicates.end();){
            if(*itSlow == *it){
                it = listDuplicates.erase_after(itBefore);
            }
            else{
                it++;
                itBefore++;
            }
        }
    }
}
