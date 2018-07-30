#include<iostream> 
#include<vector>
#include<utility>
#include<algorithm>
#include<set>
using namespace std; 

template<class T>
vector< set<T> > getAllSubSets(const set<T> &originalSet){
    vector< set<T> > subSets;
    subSets.push_back(set<T>()); //insert empty set
    set<T> copySet;
    for(typename set<T>::iterator it=originalSet.begin(); it != originalSet.end(); it++){
        int subSetsSize = subSets.size();
        for(int i=0;i<subSetsSize;i++){
            copySet = subSets[i];
            copySet.insert(*it);
            subSets.push_back(copySet);
        }
    }
    return subSets;
}
main(){ 
    int myints[]= {10,20,30,40,50};
    set<int> originalSet (myints,myints+5);
    vector< set<int> > allSubsets;
    allSubsets = getAllSubSets(originalSet);
    for(int i=0; i<allSubsets.size();i++){
        for(set<int>::iterator it = allSubsets[i].begin(); it != allSubsets[i].end(); it++){
            cout<<*it<<" ";
        }
        cout<<endl;
    }

} 

