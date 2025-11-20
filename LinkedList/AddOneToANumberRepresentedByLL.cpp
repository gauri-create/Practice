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
    Node* AddOne(Node* head){
        Node* temp=head;
        int num=0;

        while(temp!=nullptr){
            num=num*10+temp->data;
            temp=temp->next;
        }
        num=num+1;
        

        Node* Nnode=nullptr;
        
        while(num>0){
            Nnode=inserthead(Nnode, num%10);
            num=num/10;
        }
        return Nnode;
    }

    Node* inserthead(Node* head, int val){
        Node* newNode= new Node(val);
        newNode->next=head;
        return newNode;
    }

//Optimal

    int addHelper(Node* temp){
        if(temp==nullptr){
            return 1;
        }
        int carry = addHelper(temp->next);
        temp->data+=carry;
        if(temp->data<10) return 0;
        temp->data=0;
        return 1;
    }
    Node* addOne(Node* head){
        int carry=addHelper(head);
        if(carry==1){
            Node* newNode=new Node(1);
            newNode->next=head;
            head=newNode;
        }
        return head;
    }
};

int main(){
    vector<int> arr ={9,9};
    Solution obj;
    Node* head = obj.ConvertArr2LL(arr);
    obj.Print(head);
    // Node* temp = obj.AddOne(head);
    Node* temp = obj.addOne(head);
    
    obj.Print(temp);
    return 0;
}