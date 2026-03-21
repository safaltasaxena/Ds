//LINKED LIST-2(circular LL insertion at any pos ,start, end and deletion)
#include <iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;

Node(int d){
    this->data=d;
    this->next=NULL;
}
~Node(){
    int value=this->data;
    if(this->next!=NULL){
        delete next;
        this->next=NULL;
    }
     cout<<"memory free for node with data "<<value<<endl;
}
};
void insertnode(Node* &tail,int element,int d){
    if(tail==NULL){
        Node* newNode=new Node(d);
        tail=newNode;
        newNode->next=newNode;
    }
    else{
        Node* curr=tail;
        while(curr->data!=element){
            curr=curr->next;
        }
        //now current holds the element
        Node* temp=new Node(d);
        temp->next=curr->next;
        curr->next=temp;
    }
}
void print(Node* &tail){
    //we will uswe do while loop bcz the cnd in while loop fails for single node ll so in the do statement will execute no matter what thus it helps.
    if(tail==NULL){cout<<"Empty LL"<<endl;
                  return;} //for empty LL
    Node* temp=tail;
     do{ 
        cout<<temp->data<<" ";
        temp=temp->next;
     }
     while(tail!=temp);
     cout<<endl;
}
void delnode(Node* &tail,int value){
    if(tail==NULL){
        cout<<"List is empty";
        return ;
    }
    else{
       Node* prev=tail;
       Node* curr=prev->next;
        while(curr->data!=value){
            prev=curr;
            curr=curr->next;
        }
        prev->next=curr->next;
        //1 Node LL
        if(curr==prev){
            tail=NULL;
        }
        //>=2 LL
        else if(tail==curr){
            tail=prev;
        }
        curr->next=NULL;
        delete curr;
    }
}
int main () {
    Node* tail=NULL;
    //empty list
    insertnode(tail,5,3);
    print(tail);
    insertnode(tail,3,6);
    print(tail);
    insertnode(tail,6,7);
    print(tail);
    delnode(tail,3);
    print(tail);
    return 0;
}