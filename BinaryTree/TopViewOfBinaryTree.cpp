#include<iostream>
#include<vector>
#include<map>
#include<queue>
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
    vector<int> topView(TreeNode* root){
        vector<int> ans;
        if(root == nullptr) return ans;
        map<int, int>mpp;
        queue<pair<TreeNode*, int>>q;
        q.push({root, 0});
        while(!q.empty()){
            auto it= q.front();
            q.pop();
            TreeNode* node = it.first;
            int line=it.second;
            if(mpp.find(line)==mpp.end()) mpp[line]=node->data;
            if(node->left!=nullptr) q.push({node->left, line-1});
            if(node->right != nullptr) q.push({node->right, line+1});
        }
        for(auto it: mpp) ans.push_back(it.second);
        return ans;
    }
};

int main(){
    TreeNode* root = new TreeNode(1);
    root->left= new TreeNode(2);
    root->left->left= new TreeNode(4);
    root->left->right= new TreeNode(5);
    root->right= new TreeNode(3);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    Solution obj;

    vector<int> ans = obj.topView(root);
    for(auto x: ans){
       cout<<x<<" ";
    }
    return 0;
}