#include<iostream> 
#include<vector>
#include<utility>
#include<algorithm>
#include<set>
#include<string>
using namespace std; 
struct Point{
    Point(int x,int y);
    int x;
    int y;
};

Point::Point(int x, int y){
    this->x=x;
    this->y=y;
}

struct Color{
    unsigned char red;
    unsigned char green;
    unsigned char blue;
    Color (){

    }

    Color(char red, char green, char blue){
        this->red=red;
        this->green=green;
        this->blue=blue;
    }
    bool operator==(const Color &other)const{
        return  this->red == other.red &&
                this->green == other.green &&
                this->blue == other.blue;
    }
    Color operator =(const Color & other){
        this->red = other.red;
        this->green = other.green;
        this->blue = other.blue;
        return other;
    }
};

ostream& operator <<(ostream& os, const Color &c ){
    os<<"(" << int(c.red) << ", " << int(c.green) <<", " << int(c.blue) << ")";
    return os;
}

bool checkLimits(Point p, int width, int height){
    return p.x<width && p.x>=0 && p.y<height && p.y>=0;
}

void paintFill(vector< vector<Color> > &screen, int width, int height, Point initial, Color newColor,Color oldColor){
    if(checkLimits(initial, width, height)){
        if(screen[initial.y][initial.x]==oldColor){
            screen[initial.y][initial.x]= newColor;
            Point pUp(initial.x,initial.y-1);
            Point pDown(initial.x,initial.y+1);
            Point pRight(initial.x+1,initial.y);
            Point pLeft(initial.x-1,initial.y);
            paintFill(screen, width, height, pUp, newColor, oldColor);
            paintFill(screen, width, height, pDown, newColor, oldColor);
            paintFill(screen, width, height, pRight, newColor, oldColor);
            paintFill(screen, width, height, pLeft, newColor, oldColor);
        }
    }
}

void paintFill(vector< vector<Color> > &screen, int width, int height, Point initial, Color newColor){
    Color oldColor;
    if(checkLimits(initial, width, height)){
        oldColor = screen[initial.x][initial.y];
        paintFill(screen, width, height, initial, newColor, oldColor);
    }
}

main(){
    int width=4, height=4;
    vector< vector<Color> > screen;
    screen.resize(height);
    for(int i=0;i<screen.size();i++){
        screen[i].resize(width);
    }

    for(int i=0;i<width;i++){
        screen[0][i]=Color(255, 0, 0);
        screen[height-1][i]=Color(255, 0, 0);
    }

    for(int i=1;i<height-1;i++){
        for(int j=0;j<width;j++){
            screen[i][j]=Color(0, 255, 0);
        }
    }

    for(int i=0; i<height; i++){
        for(int j=0; j<width; j++){
            cout<<screen[i][j]<<" ";
        }
        cout<<endl;
    }

    paintFill(screen,width,height,Point(1,1),Color(0,0,255));

    cout<<endl;

    for(int i=0; i<height; i++){
        for(int j=0; j<width; j++){
            cout<<screen[i][j]<<" ";
        }
        cout<<endl;
    }


} 

