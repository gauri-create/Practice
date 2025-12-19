#include<iostream>
#include<map>
#include<queue>
using namespace std;

struct BinaryTreeNode{
    int data;
    BinaryTreeNode* left;
    BinaryTreeNode* right;

    BinaryTreeNode(int val){
        data=val;
        left=nullptr;
        right=nullptr;
    }
};

class Solution{
    public:
    int findMaxDistance(map<BinaryTreeNode*, BinaryTreeNode*>&parent, BinaryTreeNode*target){
        queue<BinaryTreeNode*>q;
        map<BinaryTreeNode*, bool>vis;
        q.push(target);
        vis[target]=true;
        int time=0;
        while(!q.empty()){
            int sz = q.size();
            bool spread=false;

            for(int i=0; i<sz; i++){
                BinaryTreeNode* node = q.front();
                q.pop();

                if(node->left && !vis[node->left]){
                    vis[node->left]=true;
                    q.push(node->left);
                    spread=true;
                }
                if(node->right && !vis[node->right]){
                    vis[node->right]=true;
                    q.push(node->right);
                    spread=true;
                }
                if(parent.count(node) && !vis[parent[node]]){
                    vis[parent[node]]=1;
                    q.push(parent[node]);
                    spread=true;
                }
            }
            if(spread) time++;
        }
        return time;
    }

    BinaryTreeNode* bfsToMapParents(BinaryTreeNode* root, map<BinaryTreeNode*, BinaryTreeNode*>&parent, int start){
        queue<BinaryTreeNode*>q;
        q.push(root);

        BinaryTreeNode* target=nullptr;

        while(!q.empty()){
            BinaryTreeNode* node = q.front();
            q.pop();

            if(node->data == start) target = node;

            if(node->left){
                parent[node->left] = node;
                q.push(node->left);
            }

            if(node->right){
                parent[node->right]=node;
                q.push(node->right);
            }
        }
        return target;
    }

    int timeToBurnTree(BinaryTreeNode* root, int start){
        map<BinaryTreeNode*, BinaryTreeNode*>mpp;
        BinaryTreeNode* target = bfsToMapParents(root, mpp, start);
        int maxi = findMaxDistance(mpp, target);
        return maxi;
    }
};

int main(){
    BinaryTreeNode* root= new BinaryTreeNode(1);
    root->left= new BinaryTreeNode(2);
    root->left->left=new BinaryTreeNode(4);
    root->left->left->right = new BinaryTreeNode(7);
    root->right=new BinaryTreeNode(3);
    root->right->left = new BinaryTreeNode(5);
    root->right->right = new BinaryTreeNode(6);

    Solution obj;
    int ans= obj.timeToBurnTree(root, 1);
    cout<<ans;
    return 0;
}