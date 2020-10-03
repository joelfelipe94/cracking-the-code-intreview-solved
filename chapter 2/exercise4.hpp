// Write code to partition a linked list around a value x, such that all nodes less than
// x come before all nodes greater than or equal to x.
#include <forward_list>

using namespace std;

template <typename T>
void partitionateX(forward_list<T> &fList, const T& X){
    auto lessThanX = forward_list<T>();
    auto greatherThanX = forward_list<T>();
    for(auto &value: fList){
        if(value<X){
            lessThanX.push_front(value);
        }
        else{
            greatherThanX.push_front(value);
        }
    }
    greatherThanX.splice_after(greatherThanX.before_begin(),lessThanX);
    fList = greatherThanX;
}


// This function is used to verify the solution
template <typename T>
bool verifySolution(const forward_list<T> &fList, const T& X){
    auto smallerThenX = true;
    for(auto &value: fList){
        if(smallerThenX && value >= X)
            smallerThenX = false;
        else if (!smallerThenX && value < X)
            return false;
    }
    return true;
}
