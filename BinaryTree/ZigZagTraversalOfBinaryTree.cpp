#include<iostream>
#include<queue>
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
    vector<vector<int>>zigzagLevelOrder(TreeNode* root){
        vector<vector<int>> result;
        if(root==nullptr) return result;

        queue<TreeNode*>nodesQueue;
        nodesQueue.push(root);
        bool leftToRight = true;

        while(!nodesQueue.empty()){
            int size = nodesQueue.size();
            vector<int>row(size);
            for(int i=0; i<size; i++){
                TreeNode* node = nodesQueue.front();
                nodesQueue.pop();

                int index = (leftToRight)?i:(size-1-i);

                row[index]=node->data;
                if(node->left) nodesQueue.push(node->left);
                if(node->right) nodesQueue.push(node->right);
            }
            leftToRight = !leftToRight;
            result.push_back(row);
        }
        return result;
    }
};

int main(){
    TreeNode* root = new TreeNode(1);
    root->left= new TreeNode(2);
    root->left->right= new TreeNode(4);
    root->right=new TreeNode(3);
    root->right->left = new TreeNode(8);
    root->right->right = new TreeNode(5);

    Solution obj;

    vector<vector<int>>ans= obj.zigzagLevelOrder(root);
    for(auto x : ans){
        for(int y: x){
            cout<<y<<" ";
        }
        cout<<endl;
    }
    return 0;
}