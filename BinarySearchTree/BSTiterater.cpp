#include<iostream>
#include<stack>
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

class BSTIterator{
    stack<TreeNode*> st;

    void pushAll(TreeNode* node){
        for(; node!=nullptr;
            st.push(node), node=node->left
        );
    }
    public:
    BSTIterator(TreeNode* root){
        pushAll(root);
    }

    bool hasNext(){
        return !st.empty();
    }

    int next(){
        TreeNode* temp=st.top();
        st.pop();
        pushAll(temp->right);
        return temp->data;
    }
};

int main(){
    TreeNode* root= new TreeNode(7);
    root->left= new TreeNode(3);
    root->right = new TreeNode(15);
    root->right->left = new TreeNode(9);
    root->right->right = new TreeNode(20);

    vector<string> command={
        "BSTIterator", "next", "next", "hasNext", "next",
        "hasNext", "next", "hasNext", "next", "hasNext"
    };
    BSTIterator* it = nullptr;
    for( const string& cmd : command){
        if(cmd=="BSTIterator"){
            it= new BSTIterator(root);
            cout<<"null"<<endl;
        }
        else if(cmd == "next"){
            cout<<it->next()<<endl;
        }
        else if(cmd == "hasNext"){
            cout<<(it->hasNext() ? "true": "false")<<endl;
        }
    }
    return 0;
}