#include<iostream>
#include<string>
#include<utility>
#include<vector>
using namespace std;

template <typename T>
int partition (T& arr, int left, int right){
    int pivot = (left+right)/2;
    while(left<=right){
        while(arr[left]<arr[pivot]) left++;
        while(arr[right]>arr[pivot]) right--;
        if(left<=right){
            swap(arr[left], arr[right]);
            left++;
            right--;
        }
    }
    left;
}

template<typename T>
void quickSort(T& arr, int left, int right){
    int index;
    index=partition(arr, left,right);
    if(left<index-1)
        quickSort(arr, left, index-1);
    if(index<right)
        quickSort(arr, index, right);
}

template<typename T>
void quickSort(T& arr){
    quickSort<T>(arr, 0, arr.size()-1);
}

template <typename T>
vector< pair<T, T> > makeSortedPair(const vector<T> &arr){
    vector< pair<T,T> > sortedPair(arr.size());
    for(int i=0; i<arr.size(); i++){
        sortedPair[i].second = arr[i];
        sortedPair[i].first = arr[i];
        quickSort<T>(sortedPair[i].first);
    }
    return sortedPair;
}

void sortAnagrams(vector<string> &arrStr){
    vector< pair<string, string> >  sortedPairStr;
    sortedPairStr = makeSortedPair<string>(arrStr);
    quickSort(sortedPairStr);
    for(int i=0;i<arrStr.size();i++)
        arrStr[i] = sortedPairStr[i].second;
}


main(){
    vector<string> vecStr;
    vecStr.push_back("abb");
    vecStr.push_back("aaa");
    vecStr.push_back("bba");
    vecStr.push_back("bac");
    sortAnagrams(vecStr);
    for(int i=0;i<vecStr.size();i++){
        cout<<vecStr[i]<<endl;
    }


}
