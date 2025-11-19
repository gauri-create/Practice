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
        next = nullptr;
    }
};
//convert array to linked list
Node* convertArr2LL(vector<int> &arr){
    Node* head = new Node(arr[0]);
    Node* mover = head;
    for(int i=1; i<arr.size(); i++){
        Node* temp = new Node(arr[i]);
        mover->next=temp;
        mover=temp;
    }
    return head;
}
//Give length of linked list
int LengthLL(Node* head){
    int cnt=0;
    Node* temp=head;
    while(temp){
        cnt++;
        temp=temp->next;
    }
    return cnt;
}
//search value in linked list
int SearchVal(Node* head, int val){
    Node* temp=head;
    while(temp){
        if(temp->data==val) return 1;
        temp=temp->next;
    }
    return 0;
}
//deleting head in linked list
Node* DeleteHead(Node* head){
    if(head==NULL) return head;
    Node* temp=head;
    head=head->next;
    delete temp;
    return head;
}
//Deleate last node or tail
Node* DeleteTail(Node* head){
    if(head==NULL || head->next==NULL) return NULL;
    Node* temp=head;
    while(temp->next->next!=NULL){
        temp=temp->next;
    }
    delete temp->next;
    temp->next=NULL;;
    return head;
}

//Delete kth element of Linked list
Node* DeleteK(Node* head, int k){
    if(head==NULL) return head;
    if(k==1){
        Node* temp=head;
        head=head->next;
        free(temp);
        return head;
    }
    int cnt=0;
    Node* temp=head;
    Node* prev=NULL;
    while(temp!=NULL){
        cnt++;
        if(cnt==k){
            prev->next=prev->next->next;
            free(temp);
            break;
        }
        prev=temp;
        temp=temp->next;
    }
    return head;
}

//Delete k val element of Linked list
Node* DeleteKVal(Node* head, int k){
    if(head==NULL) return head;
    if(k==head->data){
        Node* temp=head;
        head=head->next;
        free(temp);
        return head;
    }
    Node* temp=head;
    Node* prev=NULL;
    while(temp!=NULL){
        if(temp->data==k){
            prev->next=prev->next->next;
            free(temp);
            break;
        }
        prev=temp;
        temp=temp->next;
    }
    return head;
}

//Insert head in LL
Node* InsertHead(Node* head, int val){
    Node* temp = new Node(val);
    temp->next=head;
    return temp;
}

//Insert tail or last node
Node*InsertTail(Node*head, int val){
    if(head->next==NULL){
        Node* Nnode = new Node(val);
        head->next=Nnode;
        return head;
    }

    Node*temp=head;

    while(temp->next!=NULL){
        temp=temp->next;
    }
    Node* Nnode = new Node(val);
    temp->next=Nnode;
    return head;
}

//Insert at Kth place
Node* InsertK(Node* head, int k, int val){
    if(head==NULL) {
        Node * Nnode = new Node(val);
        head=Nnode;
        return head;
    }
    if(head->next==NULL){
        Node* Nnode =new Node(val);
        head->next=Nnode;
        return head;
    }
    int cnt=0;
    Node* temp = head;
    while(temp->next!=NULL){
        cnt++;
        if(cnt==k){
            Node* Nnode = new Node(val);
            Nnode->next=temp->next;
            temp->next=Nnode;
            return head;
        }
        temp=temp->next;
    }
    return head;
}

//Insert element before value X
Node* InsertBeforeVal(Node* head, int el, int val){
    if(head==NULL) {
        Node * Nnode = new Node(val);
        head=Nnode;
        return head;
    }
    if(head->next==NULL){
        Node* Nnode =new Node(val);
        head->next=Nnode;
        return head;
    }
    int cnt=0;
    Node* temp = head;
    while(temp->next!=NULL){
        if(temp->next->data==el){
            Node* Nnode = new Node(val);
            Nnode->next=temp->next;
            temp->next=Nnode;
            return head;
        }
        temp=temp->next;
    }
    return head;
}


//Print linked list data
void print(Node* head){
    while(head!= NULL){
        cout<<head->data<<" ";
        head=head->next;
    }
    cout<<endl;
}

int main(){
    vector<int>arr={2,5,8,7};
    Node* head = convertArr2LL(arr);
    Node* temp = head;
    // cout<<LengthLL(head)<<endl;
    // if(SearchVal(head, 8)==1) cout<<"Value is found"<<endl;
    // else cout<< "Value is not found"<<endl;
    // temp=DeleteHead(head); 
    // temp=DeleteTail(head);
    // temp=DeleteK(head,3);
    // temp=DeleteKVal(head, 5);
    // temp=InsertHead(head, 100);
    // temp=InsertTail(head, 20);
    // temp=InsertK(head, 3, 19);
    temp=InsertBeforeVal(head, 5, 9);
    print(temp);
    return 0;
}