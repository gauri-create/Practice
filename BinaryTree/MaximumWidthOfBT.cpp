#include<iostream>
#include<queue>
using namespace std;

struct TreeNode{
    int data;
    TreeNode* left;
    TreeNode* right;

    TreeNode(int val){
        data=val;
        left= nullptr;
        right=nullptr;
    }
};

class Solution{
    public:
    int widthOfBonaryTree(TreeNode* root){
        if(!root) return 0;
        int ans =0;
        queue<pair<TreeNode*, int>>q;
        q.push({root,0});
        while(!q.empty()){
            int size = q.size();
            int mmin = q.front().second;
            int first, last;
            for(int i=0; i<size; i++){
                int cur_id=q.front().second-mmin;
                TreeNode* node = q.front().first;
                q.pop();
                if(i==0) first=cur_id;
                if(i==size-1)last=cur_id;
                if(node->left) q.push({ node->left, cur_id*2+1});
                if(node->right) q.push({node->right, cur_id*2+2});
            }
            ans=max(ans, last-first+1);
        }
        return ans;
    }
};

int main(){
    TreeNode* root=new TreeNode(1);
    root->left = new TreeNode(3);
    root->left->left=new TreeNode(5);
    root->left->right = new TreeNode(3);
    root->right = new TreeNode(2);
    root->right->right = new TreeNode(9);

    Solution obj;
    int ans = obj.widthOfBonaryTree(root);
    cout<<ans;
    return 0;
}