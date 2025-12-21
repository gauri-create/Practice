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
    TreeNode* insertIntoBST(TreeNode* root, int val){
        if(root==nullptr) return new TreeNode(val);
        TreeNode* cur=root;
        while(true){
            if(cur->data<=val){
                if(cur->right = nullptr) cur=cur->right;
                else{
                    cur->right = new TreeNode(val);
                    break;
                }
            }
            else{
                if(cur->left != nullptr) cur=cur->left;
                else{
                    cur->left=new TreeNode(val);
                    break;
                }
            }
        }
        return root;
    }
};

void preorder(TreeNode* root){
    if(root==nullptr) return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

int main(){
    TreeNode* root = new TreeNode(4);
    root->left=new TreeNode(2);
    root->left->left=new TreeNode(1);
    root->left->right = new TreeNode(3);
    root->right=new TreeNode(7);
    int val=5;
    Solution obj;
    TreeNode* ans = obj.insertIntoBST(root, val);
    preorder(ans);
    return 0;
}