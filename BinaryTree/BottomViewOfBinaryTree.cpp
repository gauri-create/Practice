#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<map>
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
} ;

class Solution{
    public:
    vector<int> bottomView(TreeNode* root){
        vector<int>ans;
        if(root == nullptr) return ans;
        map<int,int>mpp;
        queue<pair<TreeNode* , int>>q;
        q.push({root, 0});
        while(!q.empty()){
            auto it=q.front();
            q.pop();
            TreeNode* root=it.first;
            int line=it.second;
            mpp[line]=root->data;

            if(root->left != nullptr) q.push({root->left, line-1});
            if(root->right != nullptr) q.push({root->right, line+1});
        }
        for(auto it:mpp) ans.push_back(it.second);
        return ans;
    }

    TreeNode* buildTree(vector<int>& arr) {
    if (arr.empty() || arr[0] == -1) return nullptr;

    TreeNode* root = new TreeNode(arr[0]);
    queue<TreeNode*> q;
    q.push(root);

    int i = 1;
    while (!q.empty() && i < arr.size()) {
        TreeNode* curr = q.front();
        q.pop();

        // left child
        if (i < arr.size() && arr[i] != -1) {
            curr->left = new TreeNode(arr[i]);
            q.push(curr->left);
        }
        i++;

        // right child
        if (i < arr.size() && arr[i] != -1) {
            curr->right = new TreeNode(arr[i]);
            q.push(curr->right);
        }
        i++;
    }
    return root;
}

};

int main() {
    Solution obj;
    vector<int> arr = {20,8,22,5,3,-1,25,-1,-1,10,14};

    TreeNode* root = obj.buildTree(arr);
    vector<int> ans=obj.bottomView(root);
    for(auto it: ans) cout<<it<<" ";
    return 0;
}
