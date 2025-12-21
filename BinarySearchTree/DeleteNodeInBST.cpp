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
    TreeNode* deleteNode(TreeNode* root, int key){
        if(root==nullptr) return nullptr;
        if(root->data == key) return helper(root);
        TreeNode* dummy =root;
        while(root != nullptr){
            if(root->data >key){
                if(root->left != nullptr && root->left->data == key){
                    root->left = helper(root->left);
                    break;
                }
                else{
                    root=root->left;
                }
            }
            else{
                if(root->right != nullptr && root->right->data == key){
                    root->right = helper(root->right);
                    break;
                }
                else{
                    root=root->right;
                }
            }
        }
        return dummy;
    }
    TreeNode* helper(TreeNode* root){
        if(root->left == nullptr) return root->right;
        else if(root->right == nullptr) return root->left;
        TreeNode* rightChild = root->right;
        TreeNode* lastRight = findLastRight(root->left);
        lastRight->right = rightChild;
        return root->left;
    }
    TreeNode* findLastRight(TreeNode* root){
        if(root->right == nullptr) return root;
        return findLastRight(root->right);
    }
};

void preorder(TreeNode* root){
    if(root==nullptr) return;
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

int main(){
    TreeNode* root = new TreeNode(5);
    root->left= new TreeNode(3);
    root->left->left= new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right=new TreeNode(6);
    root->right->right=new TreeNode(7);

    int key=3;
    Solution obj;

    TreeNode* del = obj. deleteNode(root, key);
    preorder(del);
    return 0;
}