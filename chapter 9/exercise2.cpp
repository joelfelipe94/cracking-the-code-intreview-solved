#include<iostream> 
#include<vector>
#include<utility>
#include<algorithm>
using namespace std; 
 
int getNumPaths(int X, int Y){
    if(X < 0 || Y < 0)
        return -1;
    int lastRow[Y+1],lastCol[X+1],newValue=1;
    for(int i=0; i<= Y;i++)
        lastRow[i]=1;
    for(int j=0; j<= X;j++)
        lastCol[j]=1;
    for(int i=1; i<=Y; i++)
        for(int j=1; j<=X; j++){
            newValue = lastCol[j]+lastRow[i];
            lastRow[i] = newValue;
            lastCol[j] = newValue;
        }
    return newValue;
}

/** Follow up question **/

int getNumPaths(int X, int Y, vector< pair<int,int> > offLimits){
    pair<int, int> lastLimit;
    vector<int> lastCol(X+1);
    vector<int> lastRow(Y+1);
    int newValue=1;
    sort(offLimits.begin(), offLimits.end());
    reverse(offLimits.begin(),offLimits.end());
    for(int j=0; j<=X; j++)
        for(int i=0;i<=Y;i++){
            if(i == 0 || j == 0)
                newValue = 1;
            else
                newValue = lastCol[j] + lastRow[i];
            if(!offLimits.empty()){
                lastLimit = offLimits.back();
                if(lastLimit.first==j && lastLimit.second==i)
                    newValue = 0;
            }
            lastCol[j] = newValue;
            lastRow[i] = newValue;
        }
    return newValue;
}

main(){ 
 
    for(int x=0; x<=10; x++)
        for(int y=0; y<=10; y++){
            cout<<"There are "<<getNumPaths(x,y);
            cout<<" ways to get from (0,0) to (" <<x<<","<<y;
            cout<<") in this grid going only down and to the right"<<endl;
        }

    /** Follow up question **/
    cout<<endl;
    vector< pair<int, int> > emptyVec;      //in order to test restrictions
    for(int x=0; x<=10; x++)                //just fill this vector
        for(int y=0; y<=10; y++){
            cout<<"There are "<<getNumPaths(x,y,emptyVec);
            cout<<" ways to get from (0,0) to (" <<x<<","<<y;
            cout<<") in this grid going only down and to the right"<<endl;
        }
} 

