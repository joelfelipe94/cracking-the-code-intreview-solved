
// Implement an algorithm to determine if a string has all unique characters. What
// if you cannot use additional data structures?

#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

// First the solution using an aditional structure
bool isAllUnique(string str){
    if(str.length() > 256)
        return false;
    vector<bool> hasChar(255,false);
    for(auto c :str){
        if(hasChar[c])
            return false;
        hasChar[c] = true;
    }
    return true;
}

// Without the aditional structure
bool isAllUniqueInplace(string str){
    if(str.length() > 256)
        return false;
    sort(str.begin(),str.end());
    for (auto i=0; i + 1<str.size(); i++){
        if(str[i] == str[i+1]){
            return false;
        }
    }
    return true;
}
