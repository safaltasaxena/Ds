#include <iostream>
#include <stack>
using namespace std;

class node {
    public:
      int data;
      node* left;
      node* right;

      node(int d){
        this->data=d;
        this->left=NULL;
        this->right=NULL;
      }

};

node* buildTree(node* root){
     
    cout<<"Enter the data: "<<endl;
    int data;
    cin >> data;
    root=new node(data) ;

    if(data==-1){
        return NULL;
    }

    cout<<"Enter data for inserting in left of "<<data<<endl;
    root->left=buildTree(root->left);
    cout<<"Enter data for inserting in right of  "<<data<<endl;
    root->right=buildTree(root->right);
    return root;

}

void inorder(node* root){

    //base case
    if(root==NULL){
        return;
    }
    
    stack <node*> s;
    node* curr=root;

    while(curr!=NULL || !s.empty()){
        while(curr!=NULL){
            s.push(curr);
            curr=curr->left;
        }
        curr=s.top();
        s.pop();
        cout<<curr->data<<" ";
        curr=curr->right;
    }
    cout<<endl;

}

void preorder(node* root){

    //base case
    if(root==NULL){
        return;
    }
    stack  <node*> s;
    s.push(root);
    while(!s.empty()){
        node* temp = s.top();
        cout<<temp->data<<" ";
        s.pop();
        if(temp->right)s.push(temp->right);
        if(temp->left)s.push(temp->left);
    }
    cout<<endl;
}

void postorder(node* root){

    //base case
    if(root==NULL){
        return;
    }
    
    stack <node*> s;
    node* curr=root;
    while(curr!=NULL|| !s.empty()){
        if(curr!=NULL){
            s.push(curr);
            curr=curr->left;
        }
        else{
            node* temp=s.top()->right;
            if(temp==NULL){
                temp=s.top();
                s.pop();      
            
            cout<<temp<<" ";
                while(!s.empty() && temp==s.top()->right){
                    temp=s.top();
                    s.pop();
                    cout<<temp->data<<" ";
                }
            }
            else{
                curr=temp;
            }
        }

    }  
    cout<<endl;
}



int main () {
    
    node* root=NULL;

    //creating a tree
    root=buildTree(root);
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    cout<<"inorder traversal is: ";
    inorder(root);
    cout<<endl;

    cout<<"preorder traversal is: ";
    preorder(root);
    cout<<endl;

    cout<<"postorder traversal is: ";
    postorder(root);
    cout<<endl;

    return 0;
}




