#include<iostream> 
#include<vector>
#include<utility>
#include<algorithm>
#include<set>
#include<string>
using namespace std; 

int factorial(int n){
    if(n<0)
        return -1;
    int resp = 1;
    while (n > 1){
        resp *= n;
        n--;
    }
    return resp;
}

void getAllPermutations(string str, int l, int r, vector<string> &permutations){
    if(l == r)
        permutations.push_back(str);
    for(int i=l; i<=r; i++){
        swap(str[l],str[i]);
        getAllPermutations(str,l+1,r,permutations);
        swap(str[l],str[i]);
    }
}



vector<string> getAllPermutations(string original){
    vector<string> permutations;
    int numPermutations = factorial(original.size());
    permutations.reserve(numPermutations);
    getAllPermutations(original, 0, original.size()-1, permutations);
    return permutations;
}
main(){ 
    string str("joel");
    vector<string> permutations = getAllPermutations(str);
    for(int i=0; i<permutations.size();i++)
        cout<<permutations[i]<<endl;

} 

