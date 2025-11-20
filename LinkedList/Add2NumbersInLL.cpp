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
        Node* prev = head;
        for(int i=1; i<arr.size(); i++){
            Node* temp=new Node(arr[i]);
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
//Brute force
    Node* Add2LL(Node* head1, Node* head2){
        Node* dummyHead = new Node(-1);
        Node* curr = dummyHead;
        Node* temp1 = head1;
        Node* temp2 = head2;
        int carry =0;
        while(temp1 != nullptr || temp2 != nullptr){
            int sum=carry;
            if(temp1) sum+=temp1->data;
            if(temp2) sum+=temp2->data;
            Node* newNode = new Node(sum%10);
            carry = sum/10;

            curr->next=newNode;
            curr = curr->next;

            if(temp1) temp1=temp1->next;
            if(temp2) temp2=temp2->next;
        }
        if(carry){
            Node* newNode = new Node(carry);
            curr->next = newNode;
        }
        return dummyHead->next;

    }
};

int main(){
    vector<int> arr1 ={5,4};
    vector<int> arr2 = {4};
    Solution obj;
    Node* head1 = obj.ConvertArr2LL(arr1);
    Node* head2 = obj.ConvertArr2LL(arr2);
    obj.Print(head1);
    obj.Print(head2);
    Node* temp = obj.Add2LL(head1, head2);
    
    obj.Print(temp);
    return 0;
}