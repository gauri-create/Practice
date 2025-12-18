#include<iostream>
#include<vector>
#include<stack>
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
    vector<vector<int>> treeTraversal(TreeNode* root){
        vector<int>pre, in, post;
        if(root==nullptr) return {};
        stack<pair<TreeNode*, int>> st;
        st.push({root, 1});

        while(!st.empty()){
            auto it = st.top();
            st.pop();
            if(it.second==1){
                pre.push_back(it.first->data);
                it.second=2;
                st.push(it);

                if(it.first->left != nullptr)st.push({it.first->left, 1});
            }

            else if(it.second==2){
                in.push_back(it.first->data);
                it.second=3;
                st.push(it);
                if(it.first->right!=nullptr) st.push({it.first->right, 1});
            }

            else{
                post.push_back(it.first->data);
            }
        }

        vector<vector<int>>result;
        result.push_back(pre);
        result.push_back(in);
        result.push_back(post);
        return result;
    }
};

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    Solution obj;
    vector<int> pre, in, post;
    vector<vector<int>> traversal=obj.treeTraversal(root);

    pre=traversal[0];
    in=traversal[1];
    post=traversal[2];

    cout<<"Preorder traversal: ";
    for(int val: pre)cout<<val<<" ";

    cout<<"\nInorder traversal: ";
    for(int val: in)cout<<val<<" ";

    cout<<"\nPostorder traversal: ";
    for(int val: post)cout<<val<<" ";

    return 0;
}