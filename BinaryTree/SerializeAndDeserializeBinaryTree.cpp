#include<iostream>
#include<queue>
#include<sstream>
#include<string>
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
    string serialize(TreeNode* root){
        if(!root) return "";
        string s="";
        queue<TreeNode*>q;
        q.push(root);
        while(!q.empty()){
            TreeNode* curNode = q.front();
            q.pop();
            if(curNode == nullptr) s.append("#,");
            else s.append(to_string(curNode->data)+',');
            if(curNode != nullptr){
                q.push(curNode->left);
                q.push(curNode->right);
            }
        }
        return s;
    }

    TreeNode* deserialize(string data){
        if(data.size() == 0) return nullptr;

        stringstream s(data);
        string str;

        getline(s, str, ',');
        TreeNode* root = new TreeNode(stoi(str));

        queue<TreeNode*>q;
        q.push(root);

        while(!q.empty()){
            TreeNode* node = q.front();
            q.pop();

            if(!getline(s, str, ',')) break;
            if(str != "#"){
                node->left = new TreeNode(stoi(str));
                q.push(node->left);
            }

            if(!getline(s, str, ',')) break;
            if(str != "#"){
                node->right = new TreeNode(stoi(str));
                q.push(node->right);
            }
        }
        return root;
    }
};

int main(){
    TreeNode* root = new TreeNode(7);
    root->left = new TreeNode(3);
    root->right = new TreeNode(15);
    root->right->left = new TreeNode(9);
    root->right->right = new TreeNode(20);

    Solution obj;
    string s= obj.serialize(root);
    cout<<"Serialize: "<<s<<endl;

    TreeNode* t=obj.deserialize(s);
    cout<<"Reserialized:"<<obj.serialize(t)<<endl;
    return 0;
}