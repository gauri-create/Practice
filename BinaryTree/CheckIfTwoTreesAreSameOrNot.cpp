#include<iostream>
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
    bool isSameTree(TreeNode* p, TreeNode* q){
        if(p==nullptr || q==nullptr) return (p==q);
        return (p->data == q->data) && isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }
};

int main(){
    TreeNode* p = new TreeNode(1);
    p->left= new TreeNode(2);
    p->right = new TreeNode(3);

    TreeNode* q = new TreeNode(1);
    q->left= new TreeNode(3);
    q->right = new TreeNode(2);

    Solution obj;

    bool ans = obj.isSameTree(p, q);
    if(ans==1) cout<<"true";
    else cout<<"false";
    return 0;
}