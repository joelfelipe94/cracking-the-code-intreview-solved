#include<iostream> 
#include<vector>
#include<utility>
#include<algorithm>
using namespace std; 
 

int findMagicIndex(const vector<int> &vec, int begin, int end){
    if(begin == end){
        if(vec[begin] == begin)
            return begin;
        else
            return -1;
    }
    else{
        int mid = (begin + end) / 2;
        if(vec[mid]==mid)
            return mid;
        else if(vec[mid]<mid)
            return findMagicIndex(vec, mid+1,end);
        else
            return findMagicIndex(vec,begin, mid-1);
    }
}



int findMagicIndex(const vector<int> &vec){
    return findMagicIndex(vec, 0, vec.size()-1);
}


/** follow up **/

int findMagicIndexFollow(const vector<int> &vec, int begin, int end){
    if(begin > vec[end] || end < vec[begin])
        return -1;
    else{
        if(begin==end)
            return begin;
        else{
            int mid=(begin+end)/2;
            int resultLeft,resultRight;
            resultLeft = findMagicIndexFollow(vec, mid+1, end);
            if(resultLeft!=-1)
                return resultLeft;
            resultRight = findMagicIndexFollow(vec, begin, mid);
            return resultRight;
        }
    }
}


int findMagicIndexFollow(const vector<int> &vec){
    return findMagicIndexFollow(vec, 0, vec.size()-1);
}

main(){ 
    int a[]={-3, -2,-1,0,2,3,4,7};
    vector<int> vec(a,a+8);
    cout<<findMagicIndex(vec)<<endl;

    /** follow up **/

    int b[]={-3, -2,-1,0,4,4,4,4};
    vector<int> vec2(b,b+8);
    cout<<findMagicIndexFollow(vec2)<<endl;
} 

