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

    void Print(Node *head)
    {
        while (head != nullptr)
        {
            cout << head->data << " ";
            head = head->next;
        }
        cout << endl;
    }

    Node* findMiddle(Node* head){
        Node* slow=head;
        Node*fast=head;
        Node* prev= nullptr;
        while(fast!=nullptr && fast->next != nullptr){
            prev=slow;
            slow=slow->next;
            fast=fast->next->next;
        }
        return prev;
    }

    Node *mergeTwoLists(Node *list1, Node* list2){
        Node* dummyNode=new Node(-1);
        Node* temp= dummyNode;

        while(list1 != nullptr && list2 != nullptr){
            if (list1->data < list2->data)
            {
                temp->next=list1;
                list1=list1->next; 
            }
            else{
                temp->next=list2;
                list2=list2->next;
            }
            temp=temp->next;
        }
        temp->next= list1 ? list1 : list2;
        Node* head1 = dummyNode->next;
        delete dummyNode;
        return head1;
    }

    Node*SortLL(Node* head){
        if(!head || !head->next) return head;

        Node* middle=findMiddle(head);
        Node* right= middle->next;
        middle->next=nullptr;

        Node* left =head;

        left = SortLL(left);
        right = SortLL(right);
        return mergeTwoLists(left, right);
    }
};

int main(){
    vector<int> arr = {5,6,2,1,4,5};
    Solution obj;
    Node *head = obj.ConvertArr2LL(arr);
    obj.Print(head);
    Node *temp = obj.SortLL(head);

    obj.Print(temp);
    return 0;
}