// Implement a function void reverse(char* str) in C or C++ which reverses a null-
// terminated string.
#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

string reverse(string str){
    for(auto i=0UL, j=str.size()-1; i < j; i++, j--){
        swap(str[i],str[j]);
    }
    return str;
}