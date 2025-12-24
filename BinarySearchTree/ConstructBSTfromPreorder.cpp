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
    public:
    TreeNode* bstFromPreorder(vector<int>& A){
        int i =0;
        return build(A, i, INT_MAX);
    }
    TreeNode* build(vector<int>& A, int& i, int bound){
        if(i==A.size() || A[i]>bound) return nullptr;
        TreeNode* root = new TreeNode(A[i++]);
        root->left=build(A,i,root->data);
        root->right = build(A, i, bound);
        return root;
    }
};

void print(TreeNode* root){
    if(!root) return;
    cout<<root->data<<" ";
    print(root->left);
    print(root->right);
 }
 
int main(){
    vector<int> preorder={8,5,1,7,10,12};
    Solution obj;
    TreeNode* root = obj.bstFromPreorder(preorder);
    print(root);
    return 0;
}