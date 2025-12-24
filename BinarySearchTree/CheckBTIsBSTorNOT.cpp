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
    bool isValid(TreeNode* root){
        return isValidBST(root, INT_MIN, INT_MAX);
    }
    private:
    bool isValidBST(TreeNode* root, long minVal, long maxVal){
        if(root== nullptr) return true;
        if(root->data >= maxVal || root->data <= minVal) return false;
        return isValidBST(root->left, minVal, root->data) && isValidBST(root->right, root->data, maxVal);
    }
};

int main(){
    TreeNode* root=new TreeNode(5);
    root->left = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(2);
    root->right= new TreeNode(6);
    root->right->right= new TreeNode(7);

    Solution obj;
    if(obj.isValid(root)){
        cout<<"The given Binary Tree is a BST"<<endl;
    }
    else{
        cout<<"The given Binary Tree is NOT a BST"<<endl;
    }
    return 0;
}