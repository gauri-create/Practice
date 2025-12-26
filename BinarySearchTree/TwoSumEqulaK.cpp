#include<iostream>
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


class BSTIterator{
    stack<TreeNode*> st;
    bool reverse = true;
    public:
    BSTIterator(TreeNode* root, bool isReverse){
        reverse = isReverse;
        pushAll(root);
    }
    bool hasNext(){
        return !st.empty();
    }

    int next(){
        TreeNode* temp = st.top();
        st.pop();
        if(!reverse) pushAll(temp->right);
        else pushAll(temp->left);
        return temp->data;
    }
    private:
    void pushAll(TreeNode* node){
        for(; node!=nullptr; ){
            st.push(node);
            if(reverse  == true) node=node->right;
            else node=node->left;
        }
    }
};

class Solution{
    public:
    bool twoSumBST(TreeNode* root, int k){
        if(!root) return false;
        BSTIterator l(root, false);
        BSTIterator r(root, true);

        int i=l.next();
        int j=r.next();
        while(i<j){
            if(i+j == k) return true;
            else if(i+j <k) i=l.next();
            else j=r.next();
        }
        return false;
    }
};

int main(){
    TreeNode* root= new TreeNode(5);
    root->left= new TreeNode(3);
    root->right= new TreeNode(6);
    root->left->left = new TreeNode(2);
    root->left->right= new TreeNode(4);
    root->right->right=new TreeNode(7);

    Solution obj;
    int k=4;
    bool ans= obj.twoSumBST(root, k);
    cout<<ans?"true":"false";
    return 0;
}