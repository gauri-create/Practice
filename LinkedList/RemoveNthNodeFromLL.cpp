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
    Node* RemoveNthNode(Node* head, int n){
        Node* front=head;
        Node* back=nullptr;
        while(n>0){
            front=front->next;
            n--;
        }
        back=head;
        while(front->next != nullptr){
            front=front->next;
            back=back->next;
        }
        
        front=back->next->next;
        free(back->next);
        back->next=front;
        return head;
    }
    //Optimal
    Node* RemoveKthNode(Node* head, int k){
        Node* fast=head;
        Node*slow=head;
        for(int i=0;i<k; i++) fast=fast->next;
        if(fast==NULL) return head->next;
        while(fast->next != NULL){
            fast=fast->next;
            slow=slow->next;
        }
        Node* delNode=slow->next;
        slow->next=slow->next->next;
        free(delNode);
        return head;
    }

};    

int main(){
    vector<int> arr = {1,2,3,4,5};
    int n=5;
    Solution obj;
    Node* head=obj.ConvertArr2LL(arr);
    obj.Print(head);
    // Node* temp= obj.RemoveNthNode(head, n);
    Node* temp= obj.RemoveKthNode(head, n);

    obj.Print(temp);
    return 0;
}