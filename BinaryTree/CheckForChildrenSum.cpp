#include<iostream>
using namespace std;

struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val){
        data = val;
        left=nullptr;
        right=nullptr;
    }
};

class Solution{
    public:
    void changeTree(TreeNode* root){
        if(root == nullptr) return;
        int child = 0;
        if(root->left) child+=root->left->data;
        if(root->right) child+=root->right->data;

        if(child>=root->data) root->data=child;
        else{
            if(root->left) root->left->data = root->data;
            else if(root->right) root->right->data = root->data;
        }
        changeTree(root->left);
        changeTree(root->right);

        int tot=0;
        if(root->left) tot += root->left->data;
        if(root->right) tot += root->right->data;
        if(root->left || root->right) root->data = tot;
    }

    void inorderTraversal(TreeNode* root){
        if(root == nullptr)return;
        inorderTraversal(root->left);
        cout<<root->data<<" ";
        inorderTraversal(root->right);
    }
};

int main(){
    TreeNode* root = new TreeNode(3);
    root->left=new TreeNode(5);
    root->right = new TreeNode(1);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->right->left = new TreeNode(0);
    root->right->right = new TreeNode(8);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);

    Solution obj;
    obj.changeTree(root);
    
    obj.inorderTraversal(root);
    cout<<endl;
    return 0;
}