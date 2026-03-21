//QUEUE-2(implementation using array,push,pop,peek,empty,size,generation)
#include <iostream> 
using namespace std;

class Queue{
    public:
    int* arr;
    int front;
    int rear;
    int size;

    Queue(int size){
        this->size=size;
        arr=new int[size];
        front=0;//intiating front and rear at 0th pos
        rear=0;
    }
 
    //push operation
    void enqueue(int data){
        if(rear==size){
            cout<<"Queue is full"<<endl;
        } 
        else{
            arr[rear]=data;
            rear++;
        }
    }

    //pop operation
    void dequeue(){
        if(front==rear){
            cout<<"Queue is empty"<<endl;
        }
        else{
            arr[front]=-1;
            front++;
            //basically if after popping queue is empty fo that we do this so that we dont consume extra space
            if(front==rear){
               front=0;
               rear=0;
            }
        }
    }

    //front operation
    int peek(){
        if(front==rear){
            return -1;
        }
        else{
            return arr[front];
        }
    }

    //is queue Empty operation??
    bool isEmpty(){
        if(front==rear){
            return true;
        }
        else{
            return false;
        }
    }
};
//all fncs have time complexity of O(1) here
int main () {
    Queue q(5);
    q.enqueue(17);
    q.enqueue(5);
    q.enqueue(4);
    q.enqueue(3);
    q.dequeue();
    cout<<q.peek()<<endl;
    if(q.isEmpty()){
        cout<<"Queue is empty"<<endl;
    }
    else{
        cout<<"Queue is not empty"<<endl;
    }
    return 0;
}