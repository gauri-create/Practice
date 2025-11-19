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

Node* ConvertArr2LL(vector<int> &arr){
    Node* head= new Node(arr[0]);
    Node* prev=head;
    for(int i=1; i<arr.size(); i++){
        Node* temp=new Node(arr[i], nullptr);
        prev->next=temp;
        prev=temp;
    }
    return head;
}

void Print(Node* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}

Node* ReverseLL(Node* head){
    if(head==NULL || head->next==NULL) return head;
    Node* newHead=ReverseLL(head->next);
    head->next->next=head;
    head->next=NULL;
    return newHead;
}

int main(){
    vector<int> arr={2,3,4,5,6};
    Node* head = ConvertArr2LL(arr);
    Node* temp=ReverseLL(head);
    Print(temp);
    return 0;
}