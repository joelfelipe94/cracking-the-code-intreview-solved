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
private:
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
    return (this->width < other.width) && (this->depth<other.depth);
}

int Box::getHeight() const{
    return this->height;
}

void Box::setDimensions(int width, int depth, int height){
    this->width = width;
    this->height = height;
    this->depth = depth;
}

int getStackHeight(int topBox, int newBox, int height, const vector<Box>& boxes){
    int heightWithBox=0,heightWithoutBox, boxHeight;
    if(newBox == boxes.size())
        return height;
    if(topBox < 0 || boxes[topBox] < boxes[newBox]){//coloca caixa
        boxHeight = boxes[newBox].getHeight();
        heightWithBox = getStackHeight(newBox, newBox+1, height + boxHeight, boxes);
    }
    heightWithoutBox = getStackHeight(topBox, newBox+1, height, boxes); //nao coloca caixa
    return max(heightWithBox,heightWithoutBox);
}

int getStackHeight(vector<Box> boxes){
    sort(boxes.begin(),boxes.end());
    return getStackHeight(-1,0,0,boxes);
}

main(){
    vector<Box> boxes;
    boxes.push_back(Box(5,9,10));
    boxes.push_back(Box(9,5,5));
    boxes.push_back(Box(10,10,10));
    boxes.push_back(Box(1,1,1));
    cout<<getStackHeight(boxes)<<endl;


} 

