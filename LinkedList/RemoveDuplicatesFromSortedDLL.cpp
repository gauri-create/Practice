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
    while(head != nullptr){
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}

Node*RemoveDuplicates(Node* head){
    Node* temp=head;
    while(temp!=nullptr && temp->next !=nullptr){
        Node* nextNode = temp->next;
        while(nextNode != nullptr && nextNode->data == temp->data){
            Node* duplicate = nextNode;
            nextNode = nextNode->next;
            delete(duplicate);
        }
        temp->next = nextNode;
        if(nextNode!=nullptr)  nextNode->prev=temp;

        temp=temp->next;
    }
    return head;
}

};

int main(){
    vector<int>arr={1,1,1,2,2,3,3,4};
    Solution obj;
    Node* head = obj.ConvertArr2DLL(arr);
    obj.print(head);
    Node* temp = obj.RemoveDuplicates(head);
    obj.print(temp);
    return 0;
}