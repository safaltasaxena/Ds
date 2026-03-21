//QUEUE-3(circular queue push, pop, peek, generation implementation using array)
#include <iostream>
using namespace std;

class CircularQueue{
    public:
    int *arr;
    int front;
    int rear;
    int size;
    
    CircularQueue(int size){
        this->size=size;
        arr=new int[size];
        front=rear=-1;
    }

    void enqueue(int value){

        //so we +size so that front -1 dosent get -ve and %size to keep it in bound
        //to check whether queue is full
        if(front==0 && rear==size-1 || rear==(front-1+size)%size){
            cout<<"Queue is full"<<endl;
        }

        //first element to push
        else if (front==-1){
            front=rear=0;
            arr[rear]=value;
        }

        //circular queue case
        else if(rear==size-1 && front!=0){
            rear=0;
            arr[rear]=value;
        }

        //normal case
        else{
            rear++;
            arr[rear]=value;
        }
    }

    void dequeue(){

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

    void peek(){
        if(front==-1 && rear==-1){
            cout<<"QUEUE is empty"<<endl;
        }
        else{
            cout<<"peek : " <<arr[front]<<endl;
        }
    }

};
int main () {
    CircularQueue q(5);
    q.peek();
    q.dequeue();
    q.peek();
    q.enqueue(17);
    q.peek();
    q.dequeue();
    q.peek();
    q.enqueue(5);
    q.peek();
    q.enqueue(4);
    q.peek();
    q.enqueue(3);
    q.peek();
    q.enqueue(1);
    q.peek();
    q.enqueue(0);
    q.peek();
    q.enqueue(9);
    q.peek();
    q.dequeue();
    q.peek();
    q.enqueue(69);
    cout<<" "<<endl;
    q.peek();
    q.enqueue(90);
    q.dequeue();
    q.peek();
    q.dequeue();
    q.peek();
    q.dequeue();
    q.peek();
    q.dequeue();
    q.peek();
    q.enqueue(68);
    q.peek();


    return 0;
}