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

Node* DeleteAllOcc(Node* head, int k){
    if(!head || (!head->next&&head->data!=k)) return nullptr;
    Node* temp = head;
    while(temp!=nullptr){
        if(temp->data==k){
            if(head==temp){
                head=head->next;
            }
            Node* nextNode=temp->next;
            Node* prevNode=temp->prev;
            if(nextNode!=nullptr) nextNode->prev=prevNode;
            if(prevNode!=nullptr) prevNode->next=nextNode;
            free(temp);
            temp=nextNode;
        }
        else temp=temp->next;
    }
    return head;
}

};

int main(){
    vector<int>arr={2,3,1,4,2};
    int k=2;
    Solution obj;
    Node* head = obj.ConvertArr2DLL(arr);
    Node*temp=obj.DeleteAllOcc(head, k);

    obj.print(temp);
    return 0;
}