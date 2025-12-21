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
    public:
    //preorder
    vector<int>getPreorder(TreeNode* root){
        vector<int>preorder;
        TreeNode* cur = root;
        while(cur!= nullptr){
            if(cur->left == nullptr){
                preorder.push_back(cur->data);
                cur=cur->right;
            }
            else{
                TreeNode* prev=cur->left;
                while(prev->right && prev->right!=cur){
                    prev=prev->right;
                }
                if(prev->right==nullptr){
                    prev->right=cur;
                    preorder.push_back(cur->data);
                    cur=cur->left;
                }
                else{
                    prev->right=nullptr;
                    cur=cur->right;
                }
            }
        }
        return preorder;
    }
};

int main(){
    Solution obj;
    TreeNode* root=new TreeNode(1);
    root->left = new TreeNode(4);
    root->left->left=new TreeNode(4);
    root->left->right=new TreeNode(2);

    vector<int>pre = obj.getPreorder(root);
    for(auto it: pre) cout<<it<<" ";

    return 0;
}