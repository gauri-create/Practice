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
        Node* head= new Node(arr[0]);
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

    Node* ReverseLinkList(Node* head){
        if(head==nullptr || head->next==nullptr)return head;
        Node* newHead=ReverseLinkList(head->next);
        head->next->next=head;
        head->next=nullptr;
        return newHead;

    }

    Node* getKthNode(Node* temp, int k){
        k-=1;
        while(temp!=NULL && k>0){
            k--;
            temp=temp->next;
        }
        return temp;
    }

    Node* kReverse(Node* head, int k){
        Node* temp=head;
        Node* prevLast = nullptr;
        while(temp!=nullptr){
            Node* KthNode= getKthNode(temp, k);
            if(KthNode == nullptr){
                if(prevLast) prevLast->next=temp;
                break;
            }
            Node* nextNode = KthNode->next;
            KthNode->next=nullptr;
            ReverseLinkList(temp);
            if(temp==head){
                head=KthNode;
            }
            else{
                prevLast->next=KthNode;
            }
            prevLast = temp;
            temp = nextNode;
        }
        return head;
    }

};

int main(){
    vector<int> arr={1,2,3,4,5,6,7,8,9,10};
    Solution obj;
    Node* head = obj.ConvertArr2LL(arr);
    obj.Print(head);

    Node* temp =obj. kReverse(head,3);
    obj.Print(temp);
    return 0;
}