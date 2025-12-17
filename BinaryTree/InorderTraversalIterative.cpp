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
    vector<int>InorderTraversal(TreeNode* root){
        stack<TreeNode*>st;
        TreeNode* node=root;
        vector<int>inorder;
        while(true){
            if(node != nullptr){
                st.push(node);
                node=node->left;
            }
            else{
                if(st.empty() == true)break;
                node=st.top();
                st.pop();
                inorder.push_back(node->data);
                node=node->right;
            }
        }
        return inorder;
    }
};
int main(){
    TreeNode* root = new TreeNode(1);

    root->left=new TreeNode(4);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(2);
    Solution obj;
    vector<int> result = obj.InorderTraversal(root);
    for(auto val : result){
        cout<<val<<" ";
    }
    return 0;
}