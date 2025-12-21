#include<iostream>
using namespace std;

struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val){
        data=val;
        left=nullptr;
        right=nullptr;
    }
};

class Solution{
    public:
    TreeNode* searchBST(TreeNode* root, int val){
        while(root!=nullptr && root->data !=val){
            root=val<root->data?root->left:root->right;
        }
        return root;
    }
};

void preorder(TreeNode* root){
    if(root==nullptr) return ;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

int main(){
    TreeNode* root= new TreeNode(4);
    root->left=new TreeNode(2);
    root->left->left=new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right=new TreeNode(7);
    int val=2;
    Solution obj;
    TreeNode* ans=obj.searchBST(root, val);
    preorder(ans);
    return 0;
}