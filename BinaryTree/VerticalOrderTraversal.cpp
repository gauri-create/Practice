#include<iostream>
#include<vector>
#include<queue>
#include<map>
#include<set>
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
    vector<vector<int>>verticalTraversal(TreeNode* root){
        map<int, map<int, multiset<int>>> nodes;
        queue<pair<TreeNode*, pair<int, int>>> todo;
        todo.push({root, {0,0}});
        while(!todo.empty()){
            auto p= todo.front();
            todo.pop();
            TreeNode* node=p.first;
            int x=p.second.first,y=p.second.second;
            nodes[x][y].insert(node->data);
            if(node->left) todo.push({node->left, {x-1, y+1}});
            if(node->right) todo.push({node->right, {x+1, y+1}});
        }

        vector<vector<int>> ans;
        for(auto p: nodes){
            vector<int> col;
            for(auto q: p.second){
                col.insert(col.end(), q.second.begin(), q.second.end());
            }
            ans.push_back(col);
        }
        return ans;
    }
};

int main(){
    TreeNode* root = new TreeNode(1);
    root->left= new TreeNode(2);
    root->left->left= new TreeNode(4);
    root->left->right= new TreeNode(5);
    root->right= new TreeNode(3);
    root->right->left = new TreeNode(6);
    root->right->right = new TreeNode(7);

    Solution obj;

    vector<vector<int>> ans = obj.verticalTraversal(root);
    for(auto x: ans){
        for(auto y: x){
            cout<<y<<" ";
        }
        cout<<endl;
    }
    return 0;
}