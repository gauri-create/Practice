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
        next=next1;
        prev=prev1;
    }

};

void Print(Node* head){
    while(head != NULL){
    cout<<head->data<<" ";
    head=head->next;
    }
}

Node* ConvertArr2DLL(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* prev = head;
    for(int i=1; i<arr.size();i++){
        Node* temp = new Node(arr[i], nullptr, prev);
        prev->next=temp;
        prev=temp;
    }
    return head;
}

int  MiddleVal(Node* head){
    Node* Hare=head;
    Node* Tortoise=head;
    while(Hare->next!=NULL){
        Hare=Hare->next->next;
        Tortoise=Tortoise->next;
    }
    return Tortoise->data;
}

int main(){
    vector<int> arr={2,5,8,7,9};
    Node* head=ConvertArr2DLL(arr);
    // Node* temp=NULL;
    int temp=MiddleVal(head);
    cout<<"Middle value is "<<temp<<endl;
    Print(head);
    return 0;
}