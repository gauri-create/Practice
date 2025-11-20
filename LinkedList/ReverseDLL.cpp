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

Node* ReverseDLL(Node* head){
    Node* current=head;
    Node* temp=NULL;
    while(current!=NULL){
        temp=current->prev;
        current->prev=current->next;
        current->next=temp;
        current=current->prev;
    }
    return temp->prev;
}

//Print ll
void print (Node* head){
    while(head != NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
}



int main(){
    vector<int>arr={2,5,8,7};
    Node* head = ConvertArr2DLL(arr);
    Node*temp=ReverseDLL(head);

    print(temp);
    return 0;
}