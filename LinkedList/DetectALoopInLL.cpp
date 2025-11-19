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
    Node* head =new Node(arr[0]);
    Node* prev = head;
    for(int i=1; i<arr.size(); i++){
        Node* temp = new Node(arr[i], prev);
        prev->next=temp;
        prev=temp;
    }
    return head;
}

void print(Node* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
}

bool DetectLoop(Node* head){
    Node* Hare = head;
    Node* Tortoise = head;
    while(Hare->next!=NULL){
        if(Hare==Tortoise) return true;
        Hare=Hare->next->next;
        Tortoise=Tortoise->next;
    }
    return false;
}

int main(){
    vector<int> arr={1,2,3,4,5};
    Node* head=ConvertArr2LL(arr);
    // print(head);
    bool temp= DetectLoop(head);
    if(temp==1) cout<<"Loop is detected";
    else cout<<"Loop is not detected";
    return 0;
}