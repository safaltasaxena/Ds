//QUEUE-4(doubly ended queue implementation using STL)
//(where push and pop both can be done from fornt and rear both,
//unlike the og one where pop is related to front whereas push is related to rear,
//from doubly ended queue we can implement stack and queue both.)

#include <iostream>
#include <queue>
using namespace std;

int main() {
    
    deque <int> q;//deque used for dubly ended queue

    q.push_front(12);
    q.push_back(14);

    cout<<q.front()<<endl;
    cout<<q.back()<<endl;
    
    q.pop_front();

    cout<<q.front()<<endl;
    cout<<q.back()<<endl;

    q.pop_back();

    if(q.empty()){
        cout<<"Queue is empty"<<endl;
    }
    else{
        cout<<"Queue is not empty"<<endl;
    }


    return 0;
}