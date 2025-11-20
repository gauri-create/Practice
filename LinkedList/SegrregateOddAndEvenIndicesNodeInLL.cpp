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
//Beter
/*
In better approach we will use array to storedata
1. store data of odd node into array
2. store data of even node into array 
3. store data from array to linkedlist
*/

//Optimal
/*
change linkes of linked list
1)connect all odd node by links
2)connect all even node by links
*/
    Node* SegrregateOddEvenNode(Node* head){
        if(!head || !head->next) return head;
        Node* odd = head;
        Node* even = head->next;
        Node* evenHead=head->next;
        while(even!=nullptr && even->next != nullptr){
            odd->next=even->next;
            odd=odd->next;

            even->next=odd->next;
            even=even->next;
        }
       
        odd->next=evenHead;
        return head;
    }
};

int main(){
    vector<int> arr = {1,2,3,4,5};
    Solution obj;
    Node* head=obj.ConvertArr2LL(arr);
    obj.Print(head);
    Node* temp= obj.SegrregateOddEvenNode(head);
    obj.Print(temp);
    return 0;
}