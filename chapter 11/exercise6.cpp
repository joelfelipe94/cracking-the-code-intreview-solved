#include<iostream>
#include<string>
#include<vector>
#include<utility>
using namespace std;

pair<int, int> binarySearch(const vector< vector<int> > &mat, int M, int N, int target){
    int i = M-1, j = 0;
    while(i >= 0 && j<N){
        if(mat[i][j]==target)
            return pair<int, int>(i, j);
        if(mat[i][j]<target)
            j++;
        if(mat[i][j]>target)
            i--;
    }
    return pair<int, int>(-1,-1);
}

ostream& operator<<(ostream& os, pair<int,int> pair){
    os<<"("<<pair.first<<", "<<pair.second<<")";
    return os;
}

main(){
    vector< vector<int> > mat;
    pair<int, int> position;
    mat.resize(4);
    for(int i=0;i<mat.size();i++){
        mat[i].resize(4);
    }
    mat[0][0]=15;
    mat[0][1]=20;
    mat[0][2]=40;
    mat[0][3]=85;
    mat[1][0]=20;
    mat[1][1]=35;
    mat[1][2]=80;
    mat[1][3]=95;
    mat[2][0]=30;
    mat[2][1]=55;
    mat[2][2]=95;
    mat[2][3]=105;
    mat[3][0]=40;
    mat[3][1]=80;
    mat[3][2]=100;
    mat[3][3]=120;
    position=binarySearch(mat, 4, 4, 30);
    cout<<position<<endl;


}
