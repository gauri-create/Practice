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
    vector<int> PostorderTraversal(TreeNode* root){
        vector<int>postorder;
        if(root==nullptr) return postorder;
        TreeNode* curr = root;
        TreeNode* temp;
        stack<TreeNode*>st;
        while(curr!=nullptr || !st.empty()){
            if(curr != nullptr){
                st.push(curr);
                curr=curr->left;
            }
            else{
                temp=st.top()->right;
                if(temp==nullptr){
                    temp=st.top();
                    st.pop();
                    postorder.push_back(temp->data);
                    while(!st.empty() && temp == st.top()->right){
                        temp=st.top();
                        st.pop();
                        postorder.push_back(temp->data);
                    }
                }
                else curr=temp;
            }
        }
        return postorder;
    }
};

int main(){
    Solution obj;
    TreeNode* root = new TreeNode(1);
    root->left= new TreeNode(4);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(2);

    vector<int>ans = obj.PostorderTraversal(root);
    for(int i:ans) cout<<i<<" ";
    return 0;
}