#include<iostream>
#include<vector>
using namespace std;

struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val){
        data=val;
        left = nullptr;
        right = nullptr;
    }
};

class Solution{
    bool isLeaf(TreeNode* cur){
        return cur && !cur->left && !cur->right;
    }

    void addLeftBoundary(TreeNode* root, vector<int>&res){
        TreeNode* cur = root->left;
        while(cur){
            if(!isLeaf(cur)) res.push_back(cur->data);
            if(cur->left) cur=cur->left;
            else cur = cur->right;
        }
    }

    void addRightBoundary(TreeNode* root, vector<int> &res){
        TreeNode* cur = root->right;
        vector<int> temp;
        while(cur){
            if(!isLeaf(cur)) res.push_back(cur->data);
            if(cur->right) cur=cur->right;
            else cur=cur->left;
        }
        for(int i=temp.size()-1; i>=0; i--){
            res.push_back(temp[i]);
        }
    }

    void addLeaves(TreeNode* root, vector<int>& res){
        if(isLeaf(root)){
            res.push_back(root->data);
            return;
        }
        if(root->left) addLeaves(root->left, res);
        if(root->right) addLeaves(root->right, res);
    }

    public:
    vector<int> boundary(TreeNode* root){
        vector<int>res;
        if(!root) return res;
        if(!isLeaf(root))res.push_back(root->data);
        addLeftBoundary(root, res);
        addLeaves(root, res);
        addRightBoundary(root, res);
        return res;
    }
};

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(4);
    root->left->right= new TreeNode(5);
    root->left->right->left= new TreeNode(8);
    root->left->right->right=new TreeNode(9);
    root->right=new TreeNode(3);
    root->right->left= new TreeNode(6);
    root->right->right= new TreeNode(7);

    Solution obj;
    vector<int>wall = obj.boundary(root);
    for(auto x: wall) cout<<x<<" ";
    return 0;
}