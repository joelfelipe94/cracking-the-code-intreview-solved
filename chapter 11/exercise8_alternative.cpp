#include<iostream>
#include<string>
#include<vector>
#include<utility>
#include<algorithm>
using namespace std;

struct Node{
    Node();
    Node(int data);
    Node *left;
    Node *right;
    int data;
    int rank;
};

Node::Node(){
    left=NULL;
    right=NULL;
    data=0;
    rank=0;
}

Node::Node(int data){
    left=NULL;
    right=NULL;
    this->data=data;
    rank=0;
}


class Stream{
public:
    Stream();
    void track(int x);
    int getRankOfNumber(int x);
private:
    Node *root;
};

Stream::Stream(){
    root=NULL;
}
void Stream::track(int x){
    Node *n = root;
    if(root==NULL){
        root= new Node(x);
        return;
    }
    while(true) {
       if(n->data>=x){
           n->rank++;
           if(n->left==NULL){
               n->left= new Node(x);
               return;
           }
           else
            n=n->left;
       }
       else{
           if(n->right==NULL){
               n->right = new Node(x);
               return;
           }
           else
            n=n->right;
       }
    }
}
int Stream::getRankOfNumber(int x){
    Node *n=root;
    int sumRank=0;
    while(n!=NULL){
        if(n->data==x)
            return sumRank + n->rank;
        else if(n->data > x){
            n=n->left;
        }
        else{
            sumRank+=n->rank+1;
            n=n->right;
        }
    }
    return -1;
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
    cout<<"getRankOfNumber(5) = "<<stream.getRankOfNumber(5)<<endl;
    cout<<"getRankOfNumber(1) = "<<stream.getRankOfNumber(1)<<endl;
    cout<<"getRankOfNumber(3) = "<<stream.getRankOfNumber(3)<<endl;
    cout<<"getRankOfNumber(4) = "<<stream.getRankOfNumber(4)<<endl;
}
