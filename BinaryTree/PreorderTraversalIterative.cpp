#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class TreeNode{
    public:
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
    vector<int>PreorderTraversal(TreeNode* root){
        vector<int> preorder;
        if(root==nullptr) return preorder;

        stack<TreeNode*>st;
        st.push(root);
        while(!st.empty()){
            root=st.top();
            st.pop();
            preorder.push_back(root->data);
            if(root->right != nullptr){
                st.push(root->right);
            }
            if(root->left != nullptr){
                st.push(root->left);
            }
        }
        return preorder;
    }
};

int main(){
    TreeNode* root = new TreeNode(1);

    root->left=new TreeNode(4);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(2);
    Solution obj;
    vector<int> result = obj.PreorderTraversal(root);
    for(auto val : result){
        cout<<val<<" ";
    }
    return 0;
}