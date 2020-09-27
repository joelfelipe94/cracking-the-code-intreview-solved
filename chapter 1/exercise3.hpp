// Given two strings, write a method to decide if one is a permutation of the other.
#include <vector>
#include <string>
using namespace std;

vector<unsigned int> countChar(const string& str){
    vector<unsigned int> charCount(256, 0);
    for(auto &c: str)
        charCount[c]++;
    return charCount;
}

bool isPermutation(string first, string second){
    if(first.size() != second.size())
        return false;
    return countChar(first) == countChar(second);
}