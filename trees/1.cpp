//creation/build a binary tree,BFS,inorder,preorder,postorder,buildfromlevelorder

#include <iostream>
#include <queue>//for Breadth-First Search and level order creation
using namespace std;

class node {
    public:
      //indvidual node structure
      int data;
      node* left;
      node* right;

      //constructor
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

//level-wise printing or Breadth-First Search
void levelOrderTraversal(node* root){
    queue <node*> q;
    //stores pointers to node objects (not the nodes themselves)
    //q is a queue that holds addresses of nodes (i.e., pointers to node objects).
    //🧠 Why not just queue<node>?
    //Because nodes are connected via pointers in trees — we usually don’t want to copy entire nodes around.
    //We just need to refer to existing nodes using their pointers.
    q.push(root);//insert node address into queue
    q.push(NULL);

    while(!q.empty()){
        node* temp=q.front();//get pointer to the front node
        q.pop();

        if(temp==NULL){
            //old level complete traversal is done
            cout<<endl;
            if(!q.empty()){
                //queue still has some child nodes
                q.push(NULL);
            }
        }

        else{
            cout<< temp->data << " ";
            if(temp->left){
                q.push(temp->left);
            }
            if(temp->right){
                q.push(temp->right);
            }
        }

    }
}

void inorder(node* root){

    //base case
    if(root==NULL){
        return;
    }

    inorder(root->left);
    cout<<root->data<<" ";
    inorder(root->right);

}

void preorder(node* root){

    //base case
    if(root==NULL){
        return;
    }

    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);

}

void postorder(node* root){

    //base case
    if(root==NULL){
        return;
    }

    postorder(root->left);
    postorder(root->right);
    cout<<root->data<<" ";

}

void buildFromLevelOrder(node* &root){

    queue <node*> q;
    cout<<"Enter data for root"<<endl;
    int data;
    cin >> data;
    root=new node(data);
    q.push(root);

    while(!q.empty()){

        node* temp=q.front();
        q.pop();

        cout<<"Enter left node for: "<<temp->data<<endl;
        int leftData;
        cin >> leftData;

        if(leftData!=-1){
            
            temp->left=new node(leftData);
            q.push(temp->left);

        }

        cout<<"Enter right node for: "<<temp->data<<endl;
        int rightData;
        cin >> rightData;

        if(rightData!=-1){

            temp->right=new node(rightData);
            q.push(temp->right);

        }
    }

    
}

int main () {
    
    node* root=NULL;

    //creating a tree
    root=buildTree(root);
    // 1 3 7 -1 -1 11 -1 -1 5 17 -1 -1 -1

    //level order
    cout<<"printing BFS\n";
    levelOrderTraversal(root);

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