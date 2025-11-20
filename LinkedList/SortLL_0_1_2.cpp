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

    Node* SortList(Node* head){
        if(!head || !head->next) return head;

        Node* zeroHead=new Node(-1);
        Node* oneHead = new Node(-1);
        Node* twoHead = new Node(-1);

        Node* zero = zeroHead;
        Node* one = oneHead;
        Node* two = twoHead;
        Node* temp = head;

        while(temp){
            if(temp->data == 0){
                zero->next=temp;
                zero= zero -> next;
            }
            else if(temp->data == 1){
                one->next= temp;
                one=one->next;
            }
            else{
                two->next=temp;
                two=two->next;
            }
            temp = temp -> next;
        }

        zero->next = (oneHead->next) ? (oneHead->next) : (twoHead->next);
        one->next = twoHead->next;
        two->next = nullptr;

        Node* newHead = zeroHead->next;

        delete zeroHead;
        delete oneHead;
        delete twoHead;
        return newHead;
    }
};

int main(){
    vector<int> arr = {1,0,2,0,1};
    Solution obj;
    Node *head = obj.ConvertArr2LL(arr);
    obj.Print(head);
    Node *temp = obj.SortList(head);

    obj.Print(temp);
    return 0;
}