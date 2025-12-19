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
    int countNodes(TreeNode* root){
        if(root==nullptr) return 0;
        int lh = findHeightLeft(root);
        int rh = findHeightRight(root);

        if(lh == rh) return (1<< lh)-1;
        return 1+countNodes(root->left)+ countNodes(root->right);
    }

    int findHeightLeft(TreeNode* node){
        int height = 0;
        while(node){
            height++;
            node = node->left;
        }
        return height;
    }

    int findHeightRight(TreeNode* node){
        int height = 0;
        while(node){
            height++;
            node = node->right;
        }
        return height;
    }
};

int main(){
    TreeNode* root= new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);
    root->right= new TreeNode(3);
    root->right->left = new TreeNode(6);

    Solution obj;
    int ans = obj.countNodes(root);
    cout<<ans;
    return 0;
}
