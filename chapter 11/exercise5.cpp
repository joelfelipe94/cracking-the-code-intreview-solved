#include<iostream>
#include<string>
#include<vector>
using namespace std;

int binarysearchWithGaps(const vector<string>& strVec, const string& target, int left, int right){
    if(left==right){
        if(strVec[left]==target)
            return left;
        else
            return -1;
    }
    int middle = (left+right)/2;
    int index;
    if(strVec[middle] == target)
        return middle;
    if(strVec[middle].empty()||strVec[middle]>target){
        index = binarysearchWithGaps(strVec, target, left, middle);
        if(index!=-1)
            return index;
    }
    if(strVec[middle].empty() || strVec[middle]<target)
        index = binarysearchWithGaps(strVec, target, middle +1, right);
    return index;
}

int binarysearchWithGaps(const vector<string>& strVec, const string& target){
    return binarysearchWithGaps(strVec, target, 0, strVec.size()-1);
}


main(){
    vector<string> vecStr;
    int index;
    vecStr.push_back("");
    vecStr.push_back("aba");
    vecStr.push_back("bba");
    vecStr.push_back("");
    vecStr.push_back("");
    vecStr.push_back("cba");
    vecStr.push_back("dba");
    vecStr.push_back("nba");
    index = binarysearchWithGaps(vecStr, string("dba"));
    cout<<index<<endl;
}
