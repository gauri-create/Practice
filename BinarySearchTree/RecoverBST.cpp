#include<iostream>
#include<stack>
#include<algorithm>
#include<climits>
using namespace std;

struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val){
        data= val;
        left=nullptr;
        right=nullptr;
    }
}; 

class Solution{
    TreeNode* first;
    TreeNode* prev;
    TreeNode* middle;
    TreeNode* last;
    private:
    void inorder(TreeNode* root){
        if(root==nullptr) return;
        inorder(root->left);
        if(prev!=nullptr && (root->data < prev->data)){
            if(first==nullptr){
                first=prev;
                middle=root;
            }
            else
                last=root;
        }
        prev=root;
        inorder(root->right);
    }
    public:
    void recoverTree(TreeNode* root){
        first=middle=last=nullptr;
        prev= new TreeNode(INT_MIN);
        inorder(root);
        if(first && last) swap(first->data,last->data);
        else if(first && middle) swap(first->data, middle->data);
    }
};

void preorder(TreeNode* root){
    if(root==nullptr){
        cout<<"null ";
        return;
    } 
    cout<<root->data<<" ";
    preorder(root->left);
    preorder(root->right);
}

int main(){
    TreeNode* root=new TreeNode(1);
    root->left=new TreeNode(3);
    root->left->right = new TreeNode(2);
    Solution obj;
    obj.recoverTree(root);
    preorder(root);
    return 0;
}