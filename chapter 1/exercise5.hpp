// Implement a method to perform basic string compression using the counts
// of repeated characters. For example, the string aabcccccaaa would become
// a2b1c5a3. If the "compressed" string would not become smaller than the orig-
// inal string, your method should return the original string.
#include<string>
using namespace std;

string compress (string str){
    string compressed;
    for(auto i=0; i<str.size(); i++){
        auto &atual = str[i];
        auto count=1;
        while(atual==str[i+1]){
            count++;
            i++;
        }
        compressed = compressed + atual + to_string(count);
    }
    if(compressed.size()<str.size())
        return compressed;
    else
        return str;
}