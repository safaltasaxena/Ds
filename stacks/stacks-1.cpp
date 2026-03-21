//STACKS-1(push,pop,peek,empty,size,generation using STL)
#include <iostream>
#include <stack>
using namespace std;
int main () {
    //creation of stack
     stack <int> s;
    
     //push operation
     s.push(2);
     s.push(3);

     //pop operation
     s.pop();

     cout<< "Printing top element " << s.top() << endl;
    
     if(s.empty()){//this thing basically return true or false
        cout <<"stack is empty" <<endl;
     }
     else{
        cout <<"Stack is not empty"<<endl;
     }

     cout<<"Size of stack is "<<s.size()<<endl;
     return 0;

}