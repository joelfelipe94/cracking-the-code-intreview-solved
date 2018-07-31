#include<iostream> 
#include<vector>
#include<utility>
#include<algorithm>
#include<set>
#include<string>
using namespace std; 

vector<string> getAllParenthesis(int n){
    vector<string> result;
    string temp;
    vector<string> resultSubProblem;
    if(n==0)
        return result;
    else if(n==1)
        result.push_back(string("()"));
    else{
        resultSubProblem = getAllParenthesis(n-1);
        for(int i=0; i< resultSubProblem.size();i++){
            temp="(";
            temp+=resultSubProblem[i];
            temp+=")";
            result.push_back(temp);
            temp = "()";
            temp += resultSubProblem[i];
            result.push_back(temp);
        }
    }
    return result;
}
main(){ 
    vector<string> allParenthesis = getAllParenthesis(1);
    for(int i=0;i<allParenthesis.size();i++){
        cout<<allParenthesis[i]<<endl;
    }
} 

