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
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root==nullptr || root==p ||root==q) return root;
        TreeNode* left=lowestCommonAncestor(root->left, p, q);
        TreeNode* right = lowestCommonAncestor(root->right, p, q);
        if(left==nullptr) return right;
        else if(right == nullptr) return left;
        else return root;
    }
};

int main(){
    TreeNode* root=new TreeNode(1);
    root->left=new TreeNode(5);
    root->left->left=new TreeNode(6);
    root->left->right=new TreeNode(2);
    root->left->right->left=new TreeNode(7);
    root->left->right->right=new TreeNode(4);
    root->right=new TreeNode(1);
    root->right->left=new TreeNode(0);
    root->right->right=new TreeNode(8);

    TreeNode* p=root->left;
    TreeNode* q=root->left->left->right;

    Solution obj;
    TreeNode* ans = obj.lowestCommonAncestor(root, p, q);
    cout<<ans->data;
    return 0;
}