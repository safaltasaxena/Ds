//QUEUE-4(doubly ended queue implementation using array)
//(where push and pop both can be done from fornt and rear both,
//unlike the og one where pop is related to front whereas push is related to rear,
//from doubly ended queue we can implement stack and queue both.)

#include <iostream>
#include <queue>
using namespace std;

class Deque {
 
    public: 

    int *arr;
    int front;
    int rear;
    int size;
    
    //intializing the queue from constructor
    Deque(int size){
        this->size=size;
        arr=new int[size];
        front=-1;
        rear=-1;
    }

    void pushFront(int x){

        //check if queue is full??
        if(front==0 && rear==size-1 || rear==(front-1+size)%size){
            cout<<"Queue is full"<<endl;
        }

        //single element in queue
        else if(front==-1){
            front=rear=0;
            arr[front]=x; 
        }

        //to maintain cyclic nature
        else if(front==0 && rear!=size-1){
             front=size-1;
             arr[front]=x;
        }

        //normal case;
        else{
            front--;
            arr[front]=x;
        }

    }

    //same as normal queue
    void pushRear(int x){

        //check if queue is full??
        if(front==0 && rear==size-1 || rear==(front-1+size)%size){
            cout<<"Queue is full"<<endl;
        }

        //single element in queue
        else if(front==-1){
            front=rear=0;
            arr[rear]=x; 
        }

        //to maintain cyclic nature
        else if(rear==size-1 && front!=0){
             rear=0;
             arr[rear]=x;
        }

        //normal case;
        else{
            rear++;
            arr[rear]=x;
        }

    }
 
    //same as normal queue
    void popFront(){

        //empty queue case
        if(front==-1){
            cout<<"Queue is empty"<<endl;
        }

        //single element case
        else if(front==rear){
            arr[front]=-1;
            front=-1;
            rear=-1;
        }

        //circular queue case
        else if(front==size-1){
            arr[front]=-1;
            front=0;//to maintain cyclic nature
        }

        //normal;
        else{
           arr[front]=-1;
           front++;
        }

    }

    void popRear(){

        //empty queue case
        if(front==-1){
            cout<<"Queue is empty"<<endl;
        }

        //single element case
        else if(front==rear){
            arr[front]=-1;
            front=-1;
            rear=-1;
        }

        //circular queue case
        else if(rear==0){
            arr[rear]=-1;
            rear=size-1;//to maintain cyclic nature
        }

        //normal;
        else{
           arr[rear]=-1;
           rear--;
        }

    }
    
    int getFront(){

        if(front==-1){
            cout<<"empty queue"<<endl;
            return -1;
        }

        else{
            return arr[front];
        }

    }

    int getRear(){

        if(front==-1){
            cout<<"empty queue"<<endl;
            return -1;
        }

        else{
            return arr[rear];
        }

    }

    bool isEmpty(){

        if(front==-1){
            return true;
        }

        else{
            return false;
        }

    }

    bool isFull(){

        if(front ==0 && rear==size-1 || rear==(front-1+size)%size){
            return true;
        }

        else{
            return false;
        }

    }

};
//all fncs are in O(1);
int main(){

    Deque d(5);
    d.popRear();
    if(d.isEmpty()){
        cout<<"Empty"<<endl;
    }
    cout<<d.getFront()<<endl;
    cout<<d.getRear()<<endl;
    d.pushFront(1);
    cout<<d.getFront()<<endl;
    cout<<d.getRear()<<endl;
    cout<<"NNNN"<<endl;
    d.popRear();
    cout<<d.getRear()<<endl;
    cout<<" "<<endl;
    d.pushFront(69);
    cout<<d.getFront()<<endl;
    cout<<d.getRear()<<endl;
    d.popRear();
    cout<<d.getFront()<<endl;
    cout<<d.getRear()<<endl;
    d.pushFront(0);
    d.pushFront(8);
    d.pushFront(3);
    d.pushFront(4);
    d.popRear();
    d.pushFront(6);
    d.pushFront(5);
    cout<<d.getFront()<<endl;
    cout<<d.getRear()<<endl;
    if(d.isFull()){
        cout<<"Full"<<endl;
    }
    d.popRear();
    cout<<d.getFront()<<endl;
    cout<<d.getRear()<<endl;
    
    return 0;
}
