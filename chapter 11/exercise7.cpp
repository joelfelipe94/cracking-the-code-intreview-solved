#include<iostream>
#include<string>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;

int getTallerTower(vector< pair<int, int> > people){
    if(people.empty())
        return 0;

    sort(people.begin(), people.end());
    vector<int> count(people.size(), 1);      //lis in the weight

    for(int i=1;i<people.size();i++)
        for(int j=0;j<i;j++){
            if(people[i].second>people[j].second && count[i]<count[j]+1)
                count[i]=count[j]+1;
        }
    return *max_element(count.begin(),count.end());
}

main(){
    vector< pair<int,int> > people;
    people.push_back(pair<int,int>(65, 100));
    people.push_back(pair<int,int>(70, 150));
    people.push_back(pair<int,int>(56, 90));
    people.push_back(pair<int,int>(75, 190));
    people.push_back(pair<int,int>(60, 95));
    people.push_back(pair<int,int>(68, 110));
    cout<<getTallerTower(people)<<endl;

}
