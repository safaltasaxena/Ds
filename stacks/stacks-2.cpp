//STACKS-2(implementation using array,push,pop,peek,empty,size,generation)
#include <iostream>
using namespace std;

class Stack{
    //properties
    public:
    int *arr;//we used ptr for array bcz we dynamically allocated memory for it , we need to do that bcz the size is unknown at compile run at that time or when heap memory allocated.
    int top;
    int size;

    //behaviour
    Stack(int size){
        this->size = size;//constructor is initializing the size
        arr = new int[size];//dynamically memory allocated for array
        top=-1;//intialising top with -1;
    }

    void push (int element){
         if(size-top>1){
            top++;
            arr[top]=element;
         }
         else{
            cout<<"Stack overflow"<<endl;
         }
    }

    void pop(){//not removing anything rather just shifting top variable's place.
        if(top>=0){
           top--;
        }
        else{
            cout<<"Stack underflow"<<endl;
        }
    }

    int peek(){
       if(top>=0){
        return arr[top];
       }
       else{
        cout<<"Stack is empty "<<endl;
        return -1;
       }
    }

    bool isEmpty(){//this fnc returns bool ture or false dont think it will print true or false
        if(top==-1){
            return true;
        }
        else{
            return false;
        }
    }
    //all fncs are implemented in O(1) here

};

int main () {
    Stack st(5);
    st.push(22);
    st.push(43);
    st.push(44);
    st.push(70);
    st.push(5);
    cout<<st.peek()<<endl;
    st.pop();
    cout<<st.peek()<<endl;
    st.pop();
    cout<<st.peek()<<endl;
    st.pop();
    cout<<st.peek()<<endl;
    if(st.isEmpty()){
        cout<<"Stack is empty mere dost"<<endl;
    }
    else{
        cout<<"Stack is not empty mere dost"<<endl;
    }
    return 0;
}