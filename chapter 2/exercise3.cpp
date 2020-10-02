#include<forward_list>
#include<iostream>
using namespace std;
void deleteMiddle(forward_list<char> &lista){
    typename forward_list<char>::iterator slow, fast;
    cout<<"aqui"<<endl;
    if(!lista.empty()){
        for(slow=lista.before_begin(),fast=lista.begin();fast!=lista.end();slow++){
            fast++;
            if(fast==lista.end())
                break;
            fast++;
        }
        lista.erase_after(slow);
    }
}

ostream& operator<<(ostream &os, const forward_list<char> &lista){
    for(forward_list<char>::const_iterator it=lista.begin();it!= lista.end();it++)
        os<<*it<<"->";
    return os;
}

main(){
    forward_list<char> listChar;
    listChar.push_front('e');
    listChar.push_front('d');
    listChar.push_front('c');
    listChar.push_front('b');
    listChar.push_front('a');
    deleteMiddle(listChar);
    cout<<listChar<<endl;

}
