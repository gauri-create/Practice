#include<iostream>
#include<stack>
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

int check(TreeNode* root){
        if(root==nullptr) return 0;
        int lh=check(root->left);
        int rh=check(root->right);
        if(lh==-1 && rh==-1) return -1;
        if(abs(lh-rh)>1)return -1;
        return max(lh, rh)+1;
}

class Solution{
    public:
    bool isBalances(TreeNode* root){
        int num = check(root);
        if(num==-1) return false;
        return true;   
    }
};

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->right->left = new TreeNode(15);
    root->right->right=new TreeNode(7);

    Solution obj;

    bool ans = obj.isBalances(root);
    if(ans==1)cout<<"Yes";
    else cout<<"No";
    return 0;
}