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
    bool SymmetricalCheck(TreeNode* root1, TreeNode* root2){
        if(root1==nullptr || root2==nullptr) return root1==root2;
        return (root1->data == root2->data) && SymmetricalCheck(root1->left, root2->right) && SymmetricalCheck(root1->right, root2->left );
    }

    public:
    bool isSymmetric(TreeNode* root){
        if(!root) return true;
        return SymmetricalCheck(root->left, root->right);
    }
};

int main(){
    Solution obj;

    TreeNode* root= new TreeNode(1);

    root->left=new TreeNode(2);
    root->left->left=new TreeNode(3);
    root->left->right = new TreeNode(4);

    root->right = new TreeNode(2);
    root->right->left= new TreeNode(4);
    root->right->right=new TreeNode(3);

    bool ans = obj.isSymmetric(root);
    if(ans==1) cout<<"true";
    else cout<<"false";
    return 0;
}