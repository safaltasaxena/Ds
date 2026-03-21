//left subtree all the nodes will be smaller than the root and right subtree all the nodes will be greater than the root node 
#include <iostream>
#include <queue>
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

//insertion-o(logn)
node* insertIntoBST(node* root,int val){

    //base case
    if(root==NULL){

        root=new node(val);
        return root;

    }

    if(val>root->data){

        root->right=insertIntoBST(root->right,val);

    }

    else{

        root->left=insertIntoBST(root->left,val);

    }

    return root;

}

void takeInput(node* &root){

    int val;
    cin >> val;

    while(val!=-1){

        root=insertIntoBST(root,val);
        cin >> val;

    }
    
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

//inorder of BST is sorted 
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

//search key using iteration,tc-o(n)
void searchIterative(node* root){

    cout<<"enetr Key value(iterative): ";
    int key;
    cin >> key;

       while (root != NULL) {

        if (root->data == key) {

            cout << "Found" << endl;
            return;

        }

        else if (key < root->data) {

            root = root->left;

        }

        else {

            root = root->right;

        }

    }

    cout << "Not Found" << endl;
    
}

//search key using recursion
//in recursion its not optimized as much as it is in iterative bcz of space complexity
bool searchRecursive(node* root,int k){

    if(root==NULL){

        return false;

    }

    if(root->data==k){

        return true;

    }

    if(root->data>k){

        return searchRecursive(root->left,k);

    }

    else{

        return searchRecursive(root->right,k);

    }

}

node* minVal(node* root){

    node* temp=root;

    while(temp->left){

        temp=temp->left;

    }

    return temp;

}

node* maxVal(node* root){

    node* temp=root;

    while(temp->right){

        temp=temp->right;

    }

    return temp;
    
}

//deletion
node* deleteFromBST(node* root,int val){

    //base case
    if(root==NULL)
       return root;
    
    if(root->data==val){

        //0 child
        if(root->left==NULL && root->right==NULL){
           delete root;
           return NULL;
        }

        //1 child

        //left child
        if(root->left!=NULL && root->right==NULL){

            node* temp=root->left;
            delete root;
            return temp;

        }

        //right child
        if(root->left==NULL && root->right!=NULL){

            node* temp=root->right;
            delete root;
            return temp;

        }

        //2 child
        if(root->left!=NULL && root->right!=NULL){

            int mini = minVal(root->right) -> data;
            root->data =mini;
            root->right=deleteFromBST(root->right,mini);
            return root;

        }

    }

    else if(root->data>val){

        root->left=deleteFromBST(root->left,val);

    }

    else{
        
        root->right=deleteFromBST(root->right,val);

    }

}



int main(){

    node* root=NULL;

    cout<<"Enter data to create BST "<<endl;
    takeInput(root);

    cout<<"Printing the BST"<<endl;
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

    searchIterative(root);
    cout<<endl;

    cout<<"Enter key of serch(recursive): ";
    int k;
    cin >> k;
    if(searchRecursive(root,k)){

        cout<<"Found";

    }
    else{

        cout<<"Not Found";

    }
    cout<<endl;
    
    cout<<"Min value: "<<minVal(root) -> data <<endl;
    cout<<"Max value: "<<maxVal(root) -> data <<endl;
    
    cout<<"enter key u wanna delete: ";
    int key;
    cin >> key;
    root=deleteFromBST(root,key);
    
    return 0;

}