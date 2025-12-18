#include<iostream>
#include<vector>
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
    int height(TreeNode* node, int& diameter){
        if(!node) return 0;
        int lh = height(node->left, diameter);
        int rh = height(node->right, diameter);
        diameter = max(diameter, lh+rh);
        return 1+max(lh, rh);
    }
    public:
    int diameterOfBinaryTree(TreeNode* root){
       int diameter = 0;
       height(root, diameter);
       return diameter;
    }
};

int main(){
    TreeNode* root = new TreeNode(1);
    root->left= new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left= new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution obj;
    int ans = obj.diameterOfBinaryTree(root);
    cout<<ans;
    return 0;
}