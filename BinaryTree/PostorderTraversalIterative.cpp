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
    vector<int>PostOrderTraversal(TreeNode* root){
        vector<int>postorder;
        if(root == nullptr) return postorder;
        stack<TreeNode*>st1, st2;
        st1.push(root);
        while(!st1.empty()){
            root=st1.top();
            st1.pop();
            st2.push(root);
            if(root->left != nullptr){
                st1.push(root->left);
            }
            if(root->right != nullptr){
                st1.push(root->right);
            }
        }
        while(!st2.empty()){
            postorder.push_back(st2.top()->data);
            st2.pop();
        }
        return postorder;
    }
};

int main(){
    Solution obj;
    TreeNode* root = new TreeNode(1);
    root->left= new TreeNode(4);
    root->left->left=new TreeNode(4);
    root->left->right = new TreeNode(2);
    vector<int>ans = obj.PostOrderTraversal(root);
    for(int x:ans) cout<<x<<" ";
    return 0;
}