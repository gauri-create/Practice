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

class NodeValue{
    public:
    int maxNode, minNode, maxSize;
    NodeValue(int minNode, int maxNode, int maxSize){
        this->maxNode = maxNode;
        this->minNode = minNode;
        this->maxSize=maxSize;
    }
};

class Solution{
    private: 
    NodeValue largestBSTSubtreeHelper(TreeNode* root){
        if(!root){
            return NodeValue(INT_MAX, INT_MIN, 0);
        }
        auto left=largestBSTSubtreeHelper(root->left);
        auto right=largestBSTSubtreeHelper(root->right);

        if(left.maxNode< root->data && root->data<right.minNode){
            return NodeValue(min(root->data, left.minNode), max(root->data, right.maxNode),(left.maxSize+right.maxSize+1));
        }
        return NodeValue(INT_MIN, INT_MAX, max(left.maxSize, right.maxSize));
    }
    public:
    int largestBSTSubtree(TreeNode* root){
        return largestBSTSubtreeHelper(root).maxSize;
    }
};

int main(){
    TreeNode* root=new TreeNode(20);
    root->left=new TreeNode(15);
    root->left->left = new TreeNode(14);
    root->left->left->right = new TreeNode(17);
    root->left->right = new TreeNode(18);
    root->left->right->left = new TreeNode(16);
    root->left->right->right = new TreeNode(19);
    root->right=new TreeNode(40);
    root->right->left = new TreeNode(30);
    root->right->right = new TreeNode(60);
    root->right->right->left=new TreeNode(50);
    Solution obj;
    int ans = obj.largestBSTSubtree(root);
    cout<<ans;
    return 0;
}