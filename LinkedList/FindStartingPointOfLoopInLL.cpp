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

Node* ConvertArr2LL(vector<int> &arr){
    Node* head =new Node(arr[0]);
    Node* prev = head;
    for(int i=1; i<arr.size(); i++){
        Node* temp = new Node(arr[i], nullptr);
        prev->next=temp;
        prev=temp;
    }
    return head;
}

void print(Node* head){
    while(head!=NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
}

Node* StartOfLoop(Node* head){
    if(head == NULL || head->next==NULL) return head;
    Node* Hare = head;
    Node* Tortoise = head;
    while(Hare->next!=NULL || Hare!=NULL){
       
        Hare=Hare->next->next;
        Tortoise=Tortoise->next;
        if(Hare==Tortoise) return Hare;
    }
    return NULL;
}

Node* CreateLoop(Node* head){
    if(!head) return head;
    if(!head->next) {
        head->next=head;
        return head;
    }

    Node* temp=head;
    Node* loop=head;
     while(temp->next!=NULL){
        temp=temp->next->next;
        loop=loop->next;
    }
    temp->next=loop;
    return temp->next;
}

int main(){
    vector<int> arr={1,2,3,4,5};
    Node* head=ConvertArr2LL(arr);
    print(head);
    Node* Loop=CreateLoop(head);
    Node* temp= StartOfLoop(Loop);

    cout<<temp->data;
    return 0;
}