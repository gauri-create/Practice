#include<iostream>
#include<vector>
using namespace std;

struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val){
        data = val;
        left=nullptr;
        right=nullptr;
    }
};

class Solution{
    bool inorder (TreeNode* node, int& k, int& ans){
        if(!node) return false;
        if(inorder(node->left, k, ans)) return true;
        if(--k == 0){
            ans = node->data;
            return true;
        }
        return inorder(node->right, k, ans);
    }

    bool reverseInorder(TreeNode* node, int& k, int& ans){
        if(!node) return false;
        if(reverseInorder(node->right, k, ans)) return true;
        if(--k == 0){
            ans = node->data;
            return true;
        }
        return reverseInorder(node->left, k, ans);
    }

    public:
    int kthSmallest(TreeNode* root, int k){
        if(k<=0) return -1;
        int ans=-1;
        inorder(root, k, ans);
        return ans;
    }

    int kthLargest(TreeNode* root, int k){
        if(k<=0) return -1;
        int ans =-1;
        reverseInorder(root, k, ans);
        return ans;
    }
    vector<int>kLargeSmall(TreeNode* root, int k){
        return {kthSmallest(root, k), kthLargest(root, k)};
    }
};

int main(){
    TreeNode* root=new TreeNode(3);
    root->left=new TreeNode(1);
    root->left->right=new TreeNode(2);
    root->right=new TreeNode(4);

    Solution obj;
    int k=1;
    vector<int>result=obj.kLargeSmall(root, k);
    cout<<result[0]<<" "<<result[1]<<endl;
    return 0;
}