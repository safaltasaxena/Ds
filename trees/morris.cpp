#include <bits/stdc++.h>
using namespace std;

class TreeNode{
    int val;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val){
        this->val=val;
        this->left=NULL;
        this->right=NULL;

    }
    

};

//inorder
vector<int> getInorder(TreeNode* root){
    vector <int> inorder;
    TreeNode *curr=root;
    while(curr!=NULL){
        //case1:where left subtree does not exist
        if(curr->left==NULL){
            inorder.push_back(curr->val);
            curr=curr->right;
        }
        //case2:left exists go to the rightmost guy in left subtree if not right then the leftout left guy
        else{
            TreeNode* prev=curr->left;
            while(prev->right && prev->right!=curr){
                prev=prev->right;
            }
            //case 2.1 if right comes out as null
            if(prev->right==NULL){
                prev->right=curr;
                curr=curr->left;
            }
            
            //case 2.2 if the prev right is alr pointing to curr ,means visited
            else{
                prev->right=NULL;
                inorder.push_back(curr->val);
                curr=curr->right;
            }
        }
    }
    return inorder;

}

//preorder
