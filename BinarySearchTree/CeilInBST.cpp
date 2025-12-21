#include<iostream>
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
    int findCeil(TreeNode* root, int key){
        int ceil=-1;
        while(root){
            if(root->data == key){
                ceil=root->data;
                return ceil;
            }
            if(key>root->data){
                root=root->right;
            }
            else{
                ceil=root->data;
                root=root->left;
            }
        }
        return ceil;
    }
};

int main(){
    TreeNode* root=new TreeNode(8);
    root->left=new TreeNode(4);
    root->left->left = new TreeNode(2);
    root->left->right = new TreeNode(6);
    root->right=new TreeNode(12);
    root->right->left = new TreeNode(10);
    root->right->right=new TreeNode(14);
    int key=11;
    Solution obj;
    int ans = obj.findCeil(root, key);
    cout<<ans;
    return 0;
}