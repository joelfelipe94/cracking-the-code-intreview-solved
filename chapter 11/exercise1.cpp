#include<iostream>
using namespace std;

void merge(int *a, int *b, int aSize, int bSize){
    int aCopy[aSize];
    for(int i=0;i<aSize;i++){
        aCopy[i]=a[i];
    }
    for(int i=0, ia=0, ib=0; i<(aSize+bSize); i++){
        if(ia>=aSize || (ib<bSize && aCopy[ia]>b[ib])){
            a[i]=b[ib];
            ib++;
        }
        else{
            a[i]=aCopy[ia];
            ia++;
        }
    }
}


main(){
    int a[10]={1,3,5,7,9};
    int b[5]={1,2,3,4,5};
    merge(a,b,5,5);
    for(int i=0;i<10;i++)
        cout<<a[i]<<" ";
    cout<<endl;
}
