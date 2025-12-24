#include<iostream>
using namespace std;

struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val){
        data=val;
        left=nullptr;
        right = nullptr;
    }
};

class Solution{
    public:
    TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q){
        if(root == nullptr) return nullptr;
        int curr= root->data;
        if(curr<p->data && curr<q->data) 
            return lowestCommonAncestor(root->right, p, q);
        if(curr>p->data && curr>q->data)
            return lowestCommonAncestor(root->left, p, q);
        return root;
    }
};

int main(){
    TreeNode* root = new TreeNode(5);
    root->left = new TreeNode(3);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(4);
    root->right = new TreeNode(6);
    root->right->right = new TreeNode(7);

    Solution obj;
    TreeNode* p = root->left->left;
    TreeNode* q = root->left->right;
    TreeNode* lca = obj.lowestCommonAncestor(root, p, q);
    if(lca != nullptr)
        cout<<lca->data;
    else cout<<"lca not found";
    return 0;
}