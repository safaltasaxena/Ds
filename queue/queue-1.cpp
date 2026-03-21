//QUEUE-1(push,pop,peek,empty,size,generation using STL)
#include <iostream>
#include <queue>
using namespace std;
int main() {
    //generation of queue
    queue <int> q;

    //push operation
    q.push(17);
    q.push(2);
    q.push(4);

    //pop operation
    q.pop();
    q.pop();

    //isEmpty? operation
    if(q.empty()){
        cout<<"Queue is empty"<<endl;
    }
    else{
        cout<<"Queue is not empty"<<endl;
    }

    //checking size of queue operation
    cout<<"size is : "<<q.size()<<endl;

    //seeing the front most element from following FIFO order operation
    cout<<q.front()<<endl;

    return 0;
}