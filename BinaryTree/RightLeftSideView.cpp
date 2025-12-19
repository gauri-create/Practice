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
    void LeftDFS(TreeNode* node, int level, vector<int>& res){
        if(!node) return;
        if(res.size()==level) res.push_back(node->data);
        LeftDFS(node->left, level+1, res);
        LeftDFS(node->right, level+1, res);
    }

    void RightDFS(TreeNode* node, int level, vector<int> & res){
        if(!node) return;
        if(res.size() == level)res.push_back(node->data);
        RightDFS(node->right, level+1, res);
        RightDFS(node->left, level+1, res);
    }

    public:
    vector<int>rightSideView(TreeNode* root){
        vector<int>res;
        RightDFS(root, 0, res);
        return res;        
    }

    vector<int>leftSideView(TreeNode* root){
        vector<int>res;
        LeftDFS(root, 0, res);
        return res; 
    }
};

int main(){
    Solution obj;
    TreeNode* root=new TreeNode(1);
    root->left=new TreeNode(2);
    root->left->right=new TreeNode(5);
    root->right=new TreeNode(3);
    root->right->right=new TreeNode(4);

    vector<int> right=obj.rightSideView(root);
    vector<int> left = obj.leftSideView(root);
    for(auto it: right) cout<<it<<" ";
    cout<<endl;
    for(auto it: left) cout<<it<<" ";
    return 0;
}