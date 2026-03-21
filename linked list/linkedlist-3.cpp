//LINKED LIST-3(doubly insertion at any pos ,start ,end and deletion)
#include <iostream>
using namespace std;
    class Node{
        public:
        int data;
        Node* prev;
        Node* next;
    
    Node(int data){
        this->data=data;
        this->next=NULL;
        this->prev=NULL;
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
void print(Node* &head){
    Node* temp=head;
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
int getlen(Node* head){
    Node* temp=head;
    int len=0;
    while(temp!=NULL){
        len++;
        temp=temp->next;
    }
    return len;
}
void insertathead(Node* &head,Node* &tail,int d){
    if(head==NULL){
        Node* temp=new Node(d);
        head=temp;
        tail=temp;
    }
    else{

    Node* temp=new Node(d);
    temp->next=head;
    head->prev=temp;
    head=temp;}
}
void insertattail(Node* &head,Node* &tail,int d){
    if(head==NULL){
       Node* temp=new Node(d);
        head=temp;
        tail=temp;
    }
    else{
     Node* temp=new Node(d);
     tail->next=temp;
     temp->prev=tail;
     tail=temp;}
}
void insertatpos(Node* &head,int pos,int d){
    Node* temp=new Node(d);
    int count=1;
    Node* curr=head;
    while(count<pos-1){
        count++;
        curr=curr->next;
    }
    Node* A=curr;
    Node* B=curr->next;
    A->next=temp;
    B->prev=temp;
    temp->prev=A;
    temp->next=B;
}
void delnode(Node* &head,int value){
    Node* temp=head;
    while(temp->data!=value){
        temp=temp->next;
    }
    temp->prev->next=temp->next;
    temp->next->prev=temp->prev;
    temp->next=NULL;
    temp->prev=NULL;
    delete temp;
}
int main() {
    Node* node1=new Node(10);
    Node* head=node1;
    Node* tail=node1;
    print(head);
    cout<<getlen(head)<<endl;
    insertathead(head,tail,11);
    print(head);
    insertattail(head,tail,7);
    print(head);
    insertatpos(head,2,6);
    print(head);
    delnode(head,6);
    print(head);

    return 0;
}