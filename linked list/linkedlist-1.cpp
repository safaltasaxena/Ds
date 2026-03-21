//LINKED LIST-1(insertion at front end and kth pos,deletion)
#include <iostream>
using namespace std;
class Node {
    public:
     int data;
     Node* next;

//constructor(name same as class)
Node(int data){
    this->data=data;
    this->next=NULL;
}
//destructor(again same name as class with ~)used to free up memory and avoid memroy leak
  ~Node(){
    int value=this->data;
    if(this->next!=NULL){//in this case this loop is not even used bcz we set it to null alr 
        delete next;//the line delete next; is not ignored.It immediately starts deleting the next node (20), and that node's destructor begins running before 10 is fully deleted.
        this->next=NULL;//??
    }
    cout<<"memory free for node with data"<<value<<endl;
  }
};
void insertathead(Node* &head,int d){
    Node* temp = new Node(d);
    temp->next=head;
    head=temp;
}
void print(Node* &head){
    Node* temp=head;//so that using this temp var we can traverse otherwise if we directly use head then we cant account it.
    while(temp!=NULL){
        cout<<temp->data<<" ";
        temp=temp->next;
    }
    cout<<endl;
}
void insertattail(Node* &tail,int d){
    Node* temp=new Node(d);
    tail->next=temp;
    tail=tail->next;
}
void insertatpos(int pos,int d,Node* &head){
     Node* temp=head;
     int cnt=1;
     while(cnt<pos-1){
          temp=temp->next;
          cnt++;
     }
    Node* newnode=new Node(d);
    newnode->next=temp->next;
    temp->next=newnode;

}
void delnode(int pos,Node* &head){
    if(pos==1){
        Node* temp=head;
        head=head->next;
        temp->next=NULL;
        delete temp;
    }
    else{
        Node* prev=NULL;
        Node* curr=head;
        int cnt=1;
        while(cnt<pos){
          cnt++;
          prev=curr;
          curr=curr->next;
        }
        prev->next=curr->next;
        curr->next=NULL;//poiting the next of curr and temp to null to avoid the recursve deleteion of code
        delete curr;
    }

}
   
int main () {
    //Node* to create heap memory instead of stack memory
     Node* node1= new Node(10);//object if the class
     cout<<node1->data<<endl;
     cout<<node1->next<<endl;
     Node* head =node1;
     Node* tail=node1;
     print(head);
     insertathead(head,12);
     print(head);
     insertattail(tail,22);
     print(head);
     insertatpos(3,15,head);
     print(head);
     delnode(2,head);
     print(head);
     return 0;
}