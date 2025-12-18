#include<iostream>
#include<climits>
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
    int maxPathSum(TreeNode* root){
        int maxi INT_MIN;
        maxPathDown(root, maxi);
        return maxi;
    }

    int maxPathDown(TreeNode* node, int &maxi){
        if(node==nullptr) return 0;
        int left = max(0, maxPathDown(node->left, maxi));
        int right = max(0, maxPathDown(node->right, maxi));
        maxi = max(maxi, left+right+node->data);
        return max(left, right)+ node->data;
    }
};

int main(){
    TreeNode* root=new TreeNode(20);
    root->left = new TreeNode(9);
    root->right = new TreeNode(-10);
    root->right->left = new TreeNode(15);
    root->right->right = new TreeNode(7);

    Solution obj;
    int ans = obj.maxPathSum(root);
    cout<<ans;
    return 0;
}