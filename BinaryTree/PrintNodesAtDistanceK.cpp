#include<iostream>
#include<vector>
#include<unordered_map>
#include<queue>
#include<algorithm>
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
    void markParents(TreeNode* root, unordered_map<TreeNode*, TreeNode*>&parent_track, TreeNode* target){
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* current = q.front();
            q.pop();
            if(current->left){
                parent_track[current->left]=current;
                q.push(current->left);
            }
            if(current->right){
                parent_track[current->right] = current;
                q.push(current->right);
            }
        }
    }
    public:
    vector<int>distanceK(TreeNode* root, TreeNode* target, int k){
        unordered_map<TreeNode*, TreeNode*> parent_track;
        markParents(root, parent_track, target);

        unordered_map<TreeNode*, bool> visited;
        queue<TreeNode*>q;
        q.push(target);
        visited[target]=true;
        int curr_level=0;
        while(!q.empty()){
            int size = q.size();
            if(curr_level++== k) break;

            for(int i=0; i<size; i++){
                TreeNode* current=q.front();
                q.pop();
                if(current->left && !visited[current->left]){
                    q.push(current->left);
                    visited[current->left]=true;
                }
                if(current->right && !visited[current->right]){
                    q.push(current->right);
                    visited[current->right]=true;
                }
                if(parent_track[current] && !visited[parent_track[current]]){
                    q.push(parent_track[current]);
                    visited[parent_track[current]]=true;
                }
            }
        }
        vector<int>result;
        while(!q.empty()){
            TreeNode* current = q.front();
            q.pop();
            result.push_back(current->data);
        }
        sort(result.begin(), result.end());
        return result;
    }
};

int main(){
    TreeNode* root = new TreeNode(3);
    root->left=new TreeNode(5);
    root->left->left = new TreeNode(6);
    root->left->right = new TreeNode(2);
    root->left->right->left = new TreeNode(7);
    root->left->right->right = new TreeNode(4);
    root->right = new TreeNode(1);
    root->right->left=new TreeNode(0);
    root->right->right  = new TreeNode(8);

    TreeNode* target=root->left;
    int k=2;

    Solution obj;
    vector<int> dist = obj.distanceK(root, target, k);
    for(auto i: dist)cout<<i<<" ";
    return 0;
}