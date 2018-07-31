#include<iostream> 
#include<vector>
#include<utility>
#include<algorithm>
#include<list>
#include<string>
using namespace std; 

class Queen{
public:
    Queen();
    Queen(int i,int j);
    bool interset(const Queen& other) const;
    bool nextPosition(int width, int height);
    pair<int, int> getPosition() const;
private:
    int i, j;
};

Queen::Queen(){
    i=0;
    j=0;
}
Queen::Queen(int i, int j){
    this->i=i;
    this->j=j;
}

bool Queen::interset(const Queen &other) const{
    return i==other.i || j==other.j || abs(other.i-i) == abs(other.j-j);
}

bool Queen::nextPosition(int width, int height){
    if(j+1<width)
        j++;
    else{
        if(i+1<height){
            i++;
            j=0;
        }
        else
            return false;
    }
    return true;
}

pair<int, int> Queen::getPosition()const{
    pair<int, int> position(i, j);
    return position;
}

bool intersectOtherQueens(const Queen &q,const  vector<Queen> & queens){
    for(vector<Queen>::const_iterator it=queens.begin(); it!=queens.end(); it++){
        if(q.interset(*it))
            return true;
    }
    return false;
}

bool insert8Queens(vector<Queen> &queens){
    if(queens.size()==8) //if there is eight queens, the work is done.
        return true;

    pair<int,int> positionLastQueen;
    if(!queens.empty()){
        positionLastQueen = queens.back().getPosition();
    }
    else
        positionLastQueen = pair<int,int>(0,-1);
    Queen q (positionLastQueen.first,positionLastQueen.second);
    while(q.nextPosition(8,8)){
        if(!intersectOtherQueens(q,queens)){
            queens.push_back(q);
            if(insert8Queens(queens))
                return true;
            else
                queens.pop_back();
        }
    }
    return false;
}

main(){
    vector<Queen> queens;
    if(insert8Queens(queens)){
        for(int i=0;i<queens.size();i++){
            pair <int,int> position;
            position = queens[i].getPosition();
            cout<<"("<<position.first<<", "<<position.second<<") ";
        }
        cout<<endl;
    }
    else{
        cout<<"It was not possible to insert 8 queens."<<endl;
    }


} 

