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
    bool getPath(TreeNode* root, vector<int>&arr, int x){
        if(!root) return false;
        arr.push_back(root->data);
        if(root->data == x) return true;
        if(getPath(root->left, arr, x) || getPath(root->right, arr, x)) return true;
        arr.pop_back(); 
        return false;
    }

    public:
    vector<int> FindPath(TreeNode* root, int node){
        vector<int>arr;
        if(root == nullptr) return arr;
        getPath(root, arr, node);
        return arr;
    }
};

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->right = new TreeNode(5);
    root->right= new TreeNode(3);
    root->right->right= new TreeNode(4);

    Solution obj;

    vector<int> ans = obj.FindPath(root, 5);
    for(auto it: ans) cout<<it<<" ";
    return 0;
}