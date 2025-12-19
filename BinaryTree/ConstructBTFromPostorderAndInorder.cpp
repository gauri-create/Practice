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
        right = nullptr;
    }
};

class Solution{
    public:
    TreeNode* buildTree(vector<int>& inorder, vector<int>& postorder){
        if(inorder.size() != postorder.size()) return nullptr;
        map<int, int>mpp;
        for(int i=0;i<inorder.size();i++)mpp[inorder[i]]=i;
        return buildTreePostIn(inorder, 0, inorder.size()-1, postorder, 0, postorder.size()-1, mpp);
    }

    TreeNode* buildTreePostIn(vector<int>& inorder, int is, int ie, vector<int>& postorder, int ps, int pe, map<int,int>& mpp){
        if(ps>pe || is>ie) return nullptr;
        TreeNode* root=new TreeNode(postorder[pe]);
        int inRoot=mpp[postorder[pe]];
        int numsLeft = inRoot-is;
        root->left=buildTreePostIn(inorder, is, inRoot-1, postorder, ps, ps+numsLeft-1, mpp);
        root->right= buildTreePostIn(inorder, inRoot+1, ie, postorder, ps+numsLeft,pe-1, mpp);
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
    vector<int> postorder={9,15,7,20,3};
    vector<int> inorder = {9,3,15,20,7};
    Solution obj;
    TreeNode* root = obj.buildTree(inorder, postorder);

    vector<int> result = obj.Preorder(root);
    for(auto val : result){
        cout<<val<<" ";
    }
    return 0;
}