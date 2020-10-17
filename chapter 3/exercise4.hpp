// In the classic problem of the Towers of Hanoi, you have 3 towers and N disks of
// different sizes which can slide onto any tower. The puzzle starts with disks sorted
// in ascending order of size from top to bottom (i.e., each disk sits on top of an
// even larger one). You have the following constraints:
// (1) Only one disk can be moved at a time.
// (2) A disk is slid off the top of one tower onto the next tower.
// (3) A disk can only be placed on top of a larger disk.
// Write a program to move the disks from the first tower to the last using stacks.

#include <stack>
class Tower{
public:
    std::stack<int> stk;
    Tower(int size=0);
    void moveToTower(int n,Tower &buffer,Tower &dest);
    void moveTop(Tower & dest);

};

bool operator==(const Tower& lhs, const Tower& rhs)
{
    return lhs.stk == rhs.stk;
}
Tower::Tower(int size){
    for(auto i=size; i>0; i--)
        stk.push(i);
}

void Tower::moveTop(Tower &dest){
    int value = stk.top();
    stk.pop();
    dest.stk.push(value); 
}
void Tower::moveToTower(int n, Tower &buffer, Tower &dest){
    if( n > 0){
        moveToTower(n-1, dest, buffer);
        moveTop(dest);
        buffer.moveToTower(n-1, *this, dest);
    }
}
