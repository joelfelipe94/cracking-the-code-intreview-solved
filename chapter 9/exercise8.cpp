#include<iostream> 
#include<vector>
#include<utility>
#include<algorithm>
#include<list>
#include<string>
using namespace std; 

int getNumChanges(int value, list<int> coin){
    if(value==0)
        return 1;
    else if(value<0 || coin.empty())
        return 0;
    else{
        int countChanges = 0;
        countChanges += getNumChanges(value-coin.front(),coin);
        coin.pop_front();
        countChanges+=getNumChanges(value, coin);
        return countChanges;
    }

}

main(){
    int a[]={25, 10, 5, 1};
    list<int> coins(a,a+4);
    for(int i=1; i<=100; i++){
        cout<<"For "<<i<<" cents there are ";
        cout<< getNumChanges(i, coins);
        cout<<" ways to give the change"<<endl;
    }


} 

