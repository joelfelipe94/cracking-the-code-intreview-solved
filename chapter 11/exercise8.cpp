#include<iostream>
#include<string>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;

class Stream{
public:
    Stream();
    void track(int x);
    int getRankOfNumber(int x);
private:
    vector<int> buffer;
    int numSorted;
};

Stream::Stream(){
    numSorted=0;
}
void Stream::track(int x){
    buffer.push_back(x);
}
int Stream::getRankOfNumber(int x){
    int index=-1;
    sort(buffer.begin() + numSorted, buffer.end());
    inplace_merge(buffer.begin(), buffer.begin()+numSorted, buffer.end());
    numSorted = buffer.size();
    int begin=0,end=buffer.size()-1,middle;
    while(begin!=end){
        middle = (begin+end)/2;
        if(buffer[middle]==x)
            index=middle;
        if(buffer[middle]<=x)
            begin=middle+1;
        else
            end=middle;
    }
    if(begin==end && buffer[begin]==x)
        index=begin;
    return index;
}

main(){
    Stream stream;
    stream.track(5);
    stream.track(1);
    stream.track(4);
    stream.track(4);
    stream.track(5);
    stream.track(9);
    stream.track(7);
    stream.track(13);
    stream.track(3);
    cout<<"getRankOfNumber(1) = "<<stream.getRankOfNumber(1)<<endl;
    cout<<"getRankOfNumber(3) = "<<stream.getRankOfNumber(3)<<endl;
    cout<<"getRankOfNumber(4) = "<<stream.getRankOfNumber(4)<<endl;
}
