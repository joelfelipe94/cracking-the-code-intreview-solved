#include<iostream> 
#include<vector>
#include<utility>
#include<algorithm>
#include<list>
#include<string>
using namespace std; 

class Box{
public:
    Box();
    Box(int width, int depth, int height);
    bool operator<(const Box &other) const;
    int getHeight()const;
    void setDimensions(int width, int depth, int height);
    int depth, height, width;
};

Box::Box(){
    depth=0;
    height=0;
    width=0;
}

Box::Box(int width, int depth, int height){
    this->width=width;
    this->height=height;
    this->depth=depth;
}

bool Box::operator <(const Box& other)const{
    if(this->width < other.width)
        return true;
    else if(this->width == other.width)
        return this->depth<other.depth;
    else
        return false;
}

int Box::getHeight() const{
    return this->height;
}

void Box::setDimensions(int width, int depth, int height){
    this->width = width;
    this->height = height;
    this->depth = depth;
}

ostream& operator<<(ostream& os, const Box &box){
    os<<"("<<box.width<<", "<<box.depth<<", "<<box.height<<")"<<endl;
    return os;
}

int getStackHeight(vector<Box> boxes){
    sort(boxes.begin(),boxes.end());
    vector<int> count(boxes.size());      //lis in the weight
    for(int i=0;i<boxes.size();i++)
        count[i]=boxes[i].getHeight();

    for(int i=1;i<boxes.size();i++)
        for(int j=0;j<i;j++){
            if(boxes[i].depth > boxes[j].depth && count[i]<count[j]+boxes[i].getHeight())
                count[i]=count[j]+boxes[i].getHeight();
        }
    return *max_element(count.begin(),count.end());
}

main(){
    vector<Box> boxes;
    boxes.push_back(Box(5,9,10));
    boxes.push_back(Box(9,5,5));
    boxes.push_back(Box(10,10,10));
    boxes.push_back(Box(1,1,1));
    cout<<getStackHeight(boxes)<<endl;


} 
/*
    1   5   9   10
    1   9   5   10
    1   10  5   10
*/
