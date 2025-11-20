#include<iostream>
#include<vector>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    public:
    Node(int data1){
        data=data1;
        next=nullptr;
    }

    public:
    Node(int data1, Node* next1){
        data=data1;
        next=next1;
    }
};

class Solution{
    public:

     Node* ConvertArr2LL(vector<int> &arr){
        Node* head=new Node(arr[0]);
        Node* prev=head;
        for(int i=1; i<arr.size(); i++){
            Node* temp = new Node(arr[i], nullptr);
            prev->next=temp;
            prev=temp;
        }
        return head;
    }

    void Print(Node* head){
        while(head!=nullptr){
            cout<<head->data<<" ";
            head=head->next;
        }
        cout<<endl;
    }
//brute force
    Node* DeleteMiddleNode(Node* head){
        if(!head || !head->next)return nullptr;
        Node* fast=head;
        Node* slow = head;
        Node* prev=nullptr;
        while(fast!=nullptr && fast->next!=nullptr){
            fast=fast->next->next;
            prev=slow;
            slow=slow->next;
        }
       
        prev->next=slow->next;
        delete slow;
        return head;
    }
//Optimal


};    

int main(){
    vector<int> arr = {7};
    Solution obj;
    Node* head=obj.ConvertArr2LL(arr);
    obj.Print(head);
    Node* temp= obj.DeleteMiddleNode(head);

    obj.Print(temp);
    return 0;
}