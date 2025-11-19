#include<iostream>
#include<vector>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* prev;

    public:
    Node(int data1){
    data=data1;
    next=nullptr;
    prev=nullptr;
    }

    public:
    Node(int data1, Node* next1, Node* prev1){
        data=data1;
        next = next1;
        prev = prev1;
    }
};
//convert array into linkedlist 
Node* ConvertArr2DLL(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* prev = head;
    for(int i=1; i<arr.size(); i++){
        Node* temp = new Node(arr[i], nullptr, prev);
        prev->next=temp;
        prev=temp;
    }
    return head;
}

//Deleted head
Node* DeleteHead(Node* head){
    if(head==NULL || head->next==NULL) return NULL;
    Node* temp=head;
    head=head->next;
    head->prev=nullptr;
    temp->next=nullptr;
    free(temp);
    head->prev=NULL;
    return head;

}
//Delete node at last or tail
Node* DeleteTail(Node* head){
    if(head==NULL||head->next==NULL) return NULL;
    Node* temp=head;
    while(temp->next->next!=NULL){
        temp=temp->next;
    }
    temp->next->prev=nullptr;
    free(temp->next);
    temp->next=nullptr;
    return head;

}

//Delete node at kth place
Node* DeleteKthPlace(Node* head, int k){
    if(head==NULL || head->next==NULL) return NULL;
    if(k==1){
        Node* temp=head;
        while(temp->next->next!=NULL){
            temp=temp->next;
        }
        temp->next->prev=nullptr;
        free(temp->next);
        temp->next=nullptr;
        return head;

    }
    int cnt=0;
    Node* temp=head;
    while(temp!=0){
        cnt++;
        if(k==cnt){
            temp->prev->next=temp->next;
            temp->next->prev=temp->prev;
            free(temp);
            return head;
        }
        temp=temp->next;
    }
    return head;
}

//Delete node at kth val
Node* DeleteKVal(Node* head, int k){
    if(head==NULL || head->next==NULL) return NULL;
    if(k==head->data){
        Node* temp=head;
        while(temp->next->next!=NULL){
            temp=temp->next;
        }
        temp->next->prev=nullptr;
        free(temp->next);
        temp->next=nullptr;
        return head;

    }
    Node* temp=head;
    while(temp!=0){
        if(k==temp->data){
            temp->prev->next=temp->next;
            temp->next->prev=temp->prev;
            free(temp);
            return head;
        }
        temp=temp->next;
    }
    return head;
}
//Insert node at head or first
Node* InsertHead(Node* head, int val){
    Node* Nnode= new Node(val);
    Nnode->next=head;
    head->prev=Nnode;
    return Nnode;
}

//Insert node at last or tail
Node* InsertTail(Node* head, int val){
    Node* Nnode= new Node(val);
    Node* temp = head;
    while(temp->next!=NULL){
        temp=temp->next;
    }
    temp->next=Nnode;
    Nnode->prev=temp;
    return head;
}

//Insert node at kth place
Node* InsertKthPlace(Node* head, int k, int val){
    if(head==NULL){
        Node* Nnode = new Node(val);
        head=Nnode;
        return head;
    }
    if(k==1){
        Node* Nnode= new Node(val);
        Nnode->next=head;
        head->prev=Nnode;
        return Nnode;
    }
    int cnt=0;
    Node* temp=head;
    while(temp!=NULL){
        cnt++;
        if(cnt==k-1){
            Node* Nnode = new Node(val);
            Nnode->next=temp->next;
            Nnode->prev=temp;

            temp->next=Nnode;
            return head;
        }
        temp=temp->next;
    }
    return head;
}

//Insert node before k val
Node* InsertKVal(Node* head, int k, int val){
    if(head==NULL){
        Node* Nnode = new Node(val);
        head=Nnode;
        return head;
    }
    if(head->next==NULL && head->data!=k){
        Node* Nnode= new Node(val);
        Nnode->next=head;
        head->prev=Nnode;
        return Nnode;
    }
    Node* temp=head;
    while(temp!=NULL){
        if(temp->data==k){
            Node* Nnode = new Node(val);
            Nnode->next=temp;
            Nnode->prev=temp->prev;
            temp->prev->next=Nnode;
            temp->prev=Nnode;
            return head;
        }
        temp=temp->next;
    }
    return head;
}

//Print ll
void print (Node* head){
    while(head != NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
}

int main(){
    vector<int>arr={2,5,8,7};
    Node* head = ConvertArr2DLL(arr);
    Node*temp=head;
    // temp=DeleteHead(head);
    // temp=DeleteTail(head);
    // temp=DeleteKthPlace(head, 3);
    // temp=DeleteKVal(head,5);
    // temp=InsertHead(head, 10);
    // temp=InsertTail(head, 70);
    // temp=InsertKthPlace(head, 3, 10);
    temp=InsertKVal(head, 5, 60);
    print(temp);
    return 0;
}