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
    Node* ConvertArr2LL(vector<int>&arr){
        Node* head = new Node(arr[0]);
        Node* prev = head;
        for(int i=1; i<arr.size();i++){
            Node* temp= new Node(arr[i], nullptr);
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

    Node* findNthNode(Node* temp, int k){
        int cnt=1;
        while(temp!=nullptr){
            if(cnt==k) return temp;
            cnt++;
            temp=temp->next;
        }
        return temp;
    }

    Node* Rotate(Node* head, int k){
        if(!head || k==0) return head;
        Node* tail=head;
        int len=1;
        while(tail->next!=nullptr){
            tail=tail->next;
            len+=1;
        }
        if(k%len==0) return head;
        k=k%len;
        //atach the tail to the head
        tail->next=head;
        Node* newLastNode=findNthNode(head, len-k);

        head=newLastNode->next;
        newLastNode->next=nullptr;
        return head;
    }
};

int main(){
    vector<int> arr ={ 1,2,3,4,5};
    Solution obj;
    Node* head=obj.ConvertArr2LL(arr);
    obj.Print(head);
    Node*temp=obj.Rotate(head, 2);
    obj.Print(temp);
    return 0;
}