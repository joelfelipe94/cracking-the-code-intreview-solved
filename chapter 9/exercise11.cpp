#include<iostream> 
#include<vector>
#include<utility>
#include<algorithm>
#include<map>
#include<string>
using namespace std; 


int getNumWaysToGetResult(string exp, bool res, int begin, int end,
                          map< pair<int, int>, int> &cacheTrue, map< pair<int, int>, int> &cacheFalse){
    if(begin==end){
        if(exp[begin]=='1' && res)
            return 1;
        else if(exp[begin] == '0' && !res)
            return 1;
        else
            return 0;
    }
    pair<int, int> interval(begin,end);
    map< pair<int,int>, int>::iterator cacheIt;
    if(res){
        cacheIt = cacheTrue.find(interval);
        if(cacheIt!=cacheTrue.end()){
            return cacheIt->second;
        }
    }
    else{
        cacheIt = cacheFalse.find(interval);
        if(cacheIt!=cacheFalse.end()){
            return cacheIt->second;
        }
    }
    int c=0;
    if(res){
        for(int i= begin+1; i<=end; i+=2){
            char op = exp[i];
            if(op == '&')
                c+=getNumWaysToGetResult(exp, true, begin, i-1,cacheTrue,cacheFalse) *
                        getNumWaysToGetResult(exp, true, i+1, end, cacheTrue, cacheFalse);
            else if(op == '|'){
                c+=getNumWaysToGetResult(exp, true, begin, i-1,cacheTrue,cacheFalse) *
                        getNumWaysToGetResult(exp, true, i+1, end, cacheTrue, cacheFalse);
                c+=getNumWaysToGetResult(exp, true, begin, i-1,cacheTrue,cacheFalse) *
                        getNumWaysToGetResult(exp, false, i+1, end, cacheTrue, cacheFalse);
                c+=getNumWaysToGetResult(exp, false, begin, i-1,cacheTrue,cacheFalse) *
                        getNumWaysToGetResult(exp, true, i+1, end, cacheTrue, cacheFalse);
            }
            else if(op == '^'){
                c+=getNumWaysToGetResult(exp, true, begin, i-1,cacheTrue,cacheFalse) *
                        getNumWaysToGetResult(exp, false, i+1, end, cacheTrue, cacheFalse);
                c+=getNumWaysToGetResult(exp, false, begin, i-1,cacheTrue,cacheFalse) *
                        getNumWaysToGetResult(exp, true, i+1, end, cacheTrue, cacheFalse);

            }


        }
        cacheTrue[interval] = c;
    }
    else{
        for(int i=begin+1;i<=end;i+=2){
            char op = exp[i];
            if(op=='&'){
                c+=getNumWaysToGetResult(exp, false, begin, i-1,cacheTrue,cacheFalse) *
                        getNumWaysToGetResult(exp, true, i+1, end, cacheTrue, cacheFalse);
                c+=getNumWaysToGetResult(exp, true, begin, i-1,cacheTrue,cacheFalse) *
                        getNumWaysToGetResult(exp, false, i+1, end, cacheTrue, cacheFalse);
                c+=getNumWaysToGetResult(exp, false, begin, i-1,cacheTrue,cacheFalse) *
                        getNumWaysToGetResult(exp, false, i+1, end, cacheTrue, cacheFalse);
            }
            else if(op=='|')
                c+=getNumWaysToGetResult(exp, false, begin, i-1,cacheTrue,cacheFalse) *
                        getNumWaysToGetResult(exp, false, i+1, end, cacheTrue, cacheFalse);
            else if(op=='^'){
                c+=getNumWaysToGetResult(exp, true, begin, i-1,cacheTrue,cacheFalse) *
                        getNumWaysToGetResult(exp, true, i+1, end, cacheTrue, cacheFalse);
                c+=getNumWaysToGetResult(exp, false, begin, i-1,cacheTrue,cacheFalse) *
                        getNumWaysToGetResult(exp, false, i+1, end, cacheTrue, cacheFalse);
            }
        }
        cacheFalse[interval] = c;
    }
    return c;
}

int getNumWaysToGetResult(string expression, bool desiredResult){
    map< pair<int,int>, int> cacheTrue;
    map< pair<int,int>, int> cacheFalse;
    return getNumWaysToGetResult(expression, desiredResult, 0, expression.size() -1, cacheTrue, cacheFalse);
}

main(){
    string expression("1^0|0|1");
    bool desiredResult=false;
    int numWays;
    numWays = getNumWaysToGetResult(expression, desiredResult);
    cout<<"There are "<<numWays<<" ways to get a false result from ";
    cout<<expression<<endl;


}

