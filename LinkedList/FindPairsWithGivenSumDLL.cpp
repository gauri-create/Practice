#include<iostream>
#include<vector>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;

    public:
    Node(int data1){
    data=data1;
    next=nullptr;
    prev=nullptr;
    }

    public:
    Node(int data1, Node* next1, Node* prev1){
        data=data1;
        next = next1;
        prev = prev1;
    }
};

class Solution{
    public:

//convert array into linkedlist 
Node* ConvertArr2DLL(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* prev = head;
    for(int i=1; i<arr.size(); i++){
        Node* temp = new Node(arr[i], nullptr, prev);
        prev->next=temp;
        prev=temp;
    }
    return head;
}


     //Print ll
 void print (Node* head){
    while(head != NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
}

Node* findTail(Node* head){
    Node* tail=head;
    while(tail->next!=nullptr) tail=tail->next;
    return tail;
}

vector<pair<int, int>>FindPairs(Node* head, int k){
    vector<pair<int,int>> ans;
    if(head==nullptr) return ans;
    Node* left = head;
    Node* right = findTail(head);
    while(left->data < right->data){
        if(left->data+right->data == k){
            ans.push_back({left->data, right->data});
            left=left->next;
            right=right->prev;
        }
        else if(left->data + right->data <k){
            left=left->next;
        }
        else right = right ->prev;
    }
    return ans;
}


};

int main(){
    vector<int>arr={1,2,4,5,6,8,9};
    int k=7;
    Solution obj;
    Node* head = obj.ConvertArr2DLL(arr);

    vector<pair<int, int>> temp=obj.FindPairs(head, k);
    for(auto &p : temp){
        cout<<"("<<p.first<<","<<p.second<<")";
    }
    return 0;
}