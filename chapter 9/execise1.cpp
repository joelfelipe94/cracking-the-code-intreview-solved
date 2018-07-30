#include<iostream> 
#include<vector> 
using namespace std; 
 
int getNumway(int n){ // returns the number of ways to climb the stairs 
    if(n==0)          // using a top down solution 
        return 1; 
    else if(n>0) 
        return getNumway(n-1) + getNumway(n-2) + getNumway(n-3); 
    else 
        return 0; 
} 
 
int getNumwayDP(int n){         // returns the number of ways to climb the stairs but uses dynamic programming 
    vector<int> historic(n+1);  // in a botton up solution 
    if(n<=2) 
        return n; 
    else{ 
        historic[0]=1; 
        historic[1]=1; 
        historic[2]=2; 
        for(int i=3; i<=n; i++){ 
            historic[i] = historic[i-1] + historic[i-2] + historic[i-3]; 
        } 
        return historic[n]; 
    } 
} 
 
int getNumwayDPMemorySaving(int n){ 
    int a=1, b=1,c=2; 
    if(n < 0)     //in the case of a invalid input 
        return 0; 
    else if(n == 0 || n== 1) 
        return 1; 
    else if(n == 2) 
        return 2; 
    else{ 
        int newValue; 
        for(int i=3; i<=n; i++){ 
            newValue = a + b + c; 
            a=b; 
            b=c; 
            c=newValue; 
        } 
    } 
    return c; 
} 
 
main(){ 
 
    for(int i=0; i<=10; i++){ 
        cout<<"for n="<<i<<" the number of ways is "; 
        cout<<getNumway(i)<<endl; 
    } 
    cout<<endl; 
    cout<<"Using dynamic programming"<<endl; 
    for(int i=0; i<=10; i++){ 
        cout<<"for n="<<i<<" the number of ways is "; 
        cout<<getNumwayDP(i)<<endl; 
    } 
 
    cout<<endl; 
    cout<<"Using dynamic programming but saving memory"<<endl; 
    for(int i=0; i<=10; i++){ 
        cout<<"for n="<<i<<" the number of ways is "; 
        cout<<getNumwayDPMemorySaving(i)<<endl; 
    } 
} 

