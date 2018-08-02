#include<iostream>
using namespace std;

int binaryRotatedSearch(int *arr, int left, int right, int n){
    if(left==right){
        if(arr[left]==n){
            return left;

        }
        else
            return -1;
    }
    int index = -1;
    int middle=(left+right)/2;

    if((arr[middle]>=n && arr[left]<=n) || (arr[left] > arr[middle]))
        index= binaryRotatedSearch(arr, left, middle, n);
    if(index!=-1){
        return index;
    }
    if((arr[middle+1]<=n && arr[right]>=n) || (arr[middle+1]>arr[right]))
        index= binaryRotatedSearch(arr, middle+1, right, n);
    return index;
}

int binaryRotatedSearch(int *arr, int size, int n){
    binaryRotatedSearch(arr, 0, size-1, n);
}

main(){
    int a[12] = {15, 16, 19, 20, 25, 1, 3, 4, 5, 7, 10, 14};
    int index = binaryRotatedSearch(a, 12, 1);
    cout<<index<<endl;
}
