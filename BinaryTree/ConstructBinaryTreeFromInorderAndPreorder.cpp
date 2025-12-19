#include<iostream>
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
};

class Solution{
    public:
    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder){
        map<int, int>inMap;
        for(int i=0; i<inorder.size(); i++){
            inMap[inorder[i]]=i;
        }
        TreeNode* root = buildTree1(preorder, 0, preorder.size()-1, inorder, 0, inorder.size()-1, inMap);
        return root;
    }

    TreeNode* buildTree1(vector<int>& preorder, int preStart, int preEnd, vector<int>& inorder, int inStart, int inEnd, map<int, int> inMap){
        if(preStart>preEnd || inStart>inEnd) return nullptr;
        TreeNode* root=new TreeNode(preorder[preStart]);
        int inRoot = inMap[root->data];
        int numsLeft= inRoot-inStart;
        root->left=buildTree1(preorder, preStart+1, preStart+numsLeft, inorder, inStart, inRoot-1, inMap);
        root->right = buildTree1(preorder, preStart+numsLeft+1, preEnd, inorder, inRoot+1, inEnd, inMap);
        return root;
    }

    private:
    void dfs(TreeNode* root, vector<int>& res){
        if(root == nullptr) return;
        res.push_back(root->data);
        dfs(root->left, res);
        dfs(root->right, res);
    }
    public:
    vector<int> Preorder(TreeNode* root){
        vector<int>res;
        dfs(root, res);
        return res;
    }
};

int main(){
    Solution obj;
    vector<int> preorder={3,9,20,15,7};
    vector<int> inorder={9,3,15,20,7};
    TreeNode* ans = obj.buildTree(preorder, inorder);;

    vector<int> result = obj.Preorder(ans);
    for(auto val : result){
        cout<<val<<" ";
    }
    return 0;
}