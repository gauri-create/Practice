#include<iostream>
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

class Solution{
    public:
    vector<int>succPredBST(TreeNode* root, int key){
        TreeNode* curr=root;
        TreeNode* succ=nullptr;
        TreeNode* pred=nullptr;

        while(curr!=nullptr){
            if(curr->data==key){
                if(curr->right!=nullptr){
                    TreeNode* temp=curr->right;
                    while(temp->left!=nullptr){
                        temp=temp->left;
                    }
                    succ=temp;  
                }
                if(curr->left!=nullptr){
                    TreeNode* temp=curr->left;
                    while(temp->right!=nullptr){
                        temp=temp->right;
                    }
                    pred=temp;
                }
                break;
            }
            else if(key<curr->data){
                succ=curr;
                curr=curr->left;
            }
            else{
                pred=curr;
                curr=curr->right;
            }
        }
        int succVal=(succ==nullptr)?-1:succ->data;
        int predVal=(pred==nullptr)?-1:pred->data;
        return {predVal, succVal};
    }
};

int main(){
    TreeNode* root=new TreeNode(5);
    root->left= new TreeNode(2);
    root->left->left = new TreeNode(1);
    root->left->right = new TreeNode(4);
    root->right = new TreeNode(10);
    root->right->left= new TreeNode(7);
    root->right->right = new TreeNode(12);
    Solution obj;
    int key=10;
    vector<int>ans = obj.succPredBST(root, key);
    cout<<ans[0]<<" "<<ans[1]<<endl;
    return 0;
}