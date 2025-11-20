#include<iostream>
#include<vector>
#include<stack>
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
    }
//Brute force
    bool CheckPalindromeLL1(Node* head){
        if(!head || !head->next) return true;
        Node* fast = head;
        Node* slow = head;
        stack<int> st;
        while(fast && fast->next){
            st.push(slow->data);
            fast=fast->next->next;
            slow=slow->next;
        }
        if(fast!= nullptr){
            slow=slow->next;
        }
        while(slow!=nullptr){
            if(!st.empty() && st.top() == slow->data){
                st.pop();
            }
            slow=slow->next;
        }
        if(st.empty()) return true;
        return false;
    }
//Optimal 
    Node* ReverseLinkedList(Node* head ){
        if(head==nullptr || head->next==nullptr ) return head;
        Node* newHead = ReverseLinkedList(head->next);
        Node*front=head->next;
        front->next=head;
        head->next=nullptr;
        return newHead;
    }


    bool CheckPalindromeLL2(Node* head){
        if(!head || !head->next) return true;
        Node* fast = head;
        Node* slow = head;
        while(fast->next != nullptr && fast->next->next != nullptr){
            slow=slow->next;
            fast=fast->next->next;
        }
        Node* newHead = ReverseLinkedList(slow->next);
        Node* first= head;
        Node* second = newHead;
        while(second!=nullptr){
            if(first->data != second->data){
                ReverseLinkedList(newHead);
                return false;
            }
            first = first->next;
            second=second->next;
        }
        ReverseLinkedList(newHead);
        return true;
    }

    

};

int main(){
    vector<int> arr={1,1,2,1,1};
    Solution obj;
    Node* head = obj.ConvertArr2LL(arr);
    bool temp = obj.CheckPalindromeLL1(head);
    // bool temp = obj.CheckPalindromeLL2(head);

    if(temp==true) cout<<"Linked List is palindrome"<<endl;
    else cout<<"linked list is not palindrome"<<endl;
    obj.Print(head);
}