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
        void flatten(TreeNode* root){
            TreeNode* curr = root;
            while(curr){
                if(curr->left){
                    TreeNode* pre = curr->left;
                    while(pre->right){
                        pre=pre->right;
                    }
                    pre->right = curr->right;
                    curr->right=curr->left;
                    curr->left=nullptr;
                }
                curr=curr->right;
            }
        }
};

void printPreOrder(TreeNode* root){
    if(!root) return;
    cout<<root->data<<" ";
    printPreOrder(root->left);
    printPreOrder(root->right);
}

void printFlattenTree(TreeNode* root){
    if(!root) return;
    cout<<root->data<<" ";
    printFlattenTree(root->right);
}

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right= new TreeNode(5);
    root->left->right->right=new TreeNode(6);
    root->right->right = new TreeNode(7);
    root->right->left= new TreeNode(8);

    Solution obj;

    cout<<"Binary tree Preorder: ";
    printPreOrder(root);
    cout<<endl;

    obj.flatten(root);

    cout<<"Binary Tree After Flatten: ";
    printFlattenTree(root);
    cout<<endl;

    return 0;
}
