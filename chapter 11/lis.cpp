#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int lis(vector<int> array){
    vector<int> count(array.size(), 1);
    for(int i=1;i<array.size();i++)
        for(int j=0;j<i;j++){
            if(array[i]>array[j] && count[i]<count[j]+1)
                count[i]=count[j]+1;
        }
    return *max_element(count.begin(),count.end());
}

main(){
    int a[]={ 10, 22, 9, 33, 21, 50, 41, 60 };
    vector <int> arr(a, a+8);
    cout<<lis(arr)<<endl;
}
