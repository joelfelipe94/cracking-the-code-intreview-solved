// Write a method to replace all spaces in a string with'%20'. You may assume that
// the string has sufficient space at the end of the string to hold the additional
// characters, and that you are given the "true" length of the string.
#include <string>
using namespace std;



// This function was made considering that there is no
void replaceCharWithSubstring(string &inStr, char cFind, string replace){
    string outStr;
    outStr.reserve(inStr.size()); 
    for(auto &c: inStr){
        if(cFind == c){
            outStr.append(replace);
        }
        else{
            outStr.push_back(c);
        }
        if(outStr.size() == inStr.size()){
            break;
        }
    }
    inStr = outStr;
}

void replaceSpaceWithPercent20(string & str){
    replaceCharWithSubstring(str, ' ', "%20");
}