#include<iostream>
#include<queue>
using namespace std;

struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(){
        data = 0;
        left=nullptr;
        right=nullptr;
    }

    TreeNode(int val){
        data=val;
        left=nullptr;
        right=nullptr;
    }
};

class Solution{
    private:
    void dfs(TreeNode* root, vector<int>& res){
        if(root == nullptr) return;
        dfs(root->left, res);
        res.push_back(root->data);
        dfs(root->right, res);
    }
    public:
    vector<int> postorder(TreeNode* root){
        vector<int>res;
        dfs(root, res);
        return res;
    }
};


int main(){
    TreeNode* root = new TreeNode(1);
    // root->left=new TreeNode(2);
    // root->right=new TreeNode(3);
    // root->left->left=new TreeNode(4);
    // root->left->right=new TreeNode(5);
    // root->right->right= new TreeNode(6);

    root->left=new TreeNode(4);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(2);
    Solution obj;
    vector<int> result = obj.postorder(root);
    for(auto val : result){
        cout<<val<<" ";
    }
    return 0;
}