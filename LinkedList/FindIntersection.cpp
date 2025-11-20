#include <iostream>
#include <vector>
using namespace std;

class Node
{
public:
    int data;
    Node *next;

public:
    Node(int data1)
    {
        data = data1;
        next = nullptr;
    }

public:
    Node(int data1, Node *next1)
    {
        data = data1;
        next = next1;
    }
};

class Solution
{
public:
    Node *ConvertArr2LL(vector<int> &arr)
    {
        Node *head = new Node(arr[0]);
        Node *prev = head;
        for (int i = 1; i < arr.size(); i++)
        {
            Node *temp = new Node(arr[i], nullptr);
            prev->next = temp;
            prev = temp;
        }
        return head;
    }

    Node* CreateIntersection(Node* head1, Node* head2){
        Node* fast=head1;
        Node* slow=head1;
        while(fast!=nullptr&&fast->next!=nullptr){
            fast=fast->next->next;
            slow=slow->next;
        }
        Node* temp=head2;
        while(temp->next!=nullptr){
            temp=temp->next;
        }
        temp->next=slow;
        return head2;
    }
    void Print(Node *head)
    {
        while (head != nullptr)
        {
            cout << head->data << " ";
            head = head->next;
        }
        cout << endl;
    }

    Node* FindIntersection(Node* firstHead, Node* secondHead){
        if(firstHead==nullptr || secondHead==nullptr) return nullptr;
        Node* temp1 = firstHead;
        Node* temp2 = secondHead;
        while(temp1 != temp2){
            temp1 = temp1->next;
            temp2 = temp2->next;

            if(temp1==temp2){
                temp1->next=nullptr;
                return temp1;
            } 

            if(temp1==nullptr) temp1=secondHead;
            if(temp2==nullptr) temp2=firstHead;
        }
        return nullptr;
    }
};

int main(){
    vector<int> arr1 = {3,1,4,6,2};
    vector<int> arr2= {1,2,4,5};
    Solution obj;
    Node *head1 = obj.ConvertArr2LL(arr1);
    Node* head2 = obj.ConvertArr2LL(arr2);
    Node* Ihead = obj.CreateIntersection(head1, head2);
    obj.Print(head1);
    obj.Print(head2);
    Node *temp = obj.FindIntersection(head1, head2);
    
    obj.Print(temp);
    return 0;
}