#include<iostream>
#include<vector>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* random;

    
    Node(){
        data=0;
        next=nullptr;
        random=nullptr;
    }

    Node(int data1){
        data=data1;
        next=nullptr;
        random=nullptr;
    }
};

class Solution{
    public:
    

    Node* ConvertArr2LL1(vector<vector<int>> & arr){
        int n=arr.size();
        if(n==0) return nullptr;

        //step1: create nodes
        vector<Node*> nodes(n);
        for(int i=0; i<n; i++){
            nodes[i] = new Node(arr[i][0]);
        }

        //step2: link next pointers
        for(int i=0; i<n-1; i++){
            nodes[i]->next=nodes[i+1];
        }

        //step3: link random pointers
        for(int i=0; i<n; i++){
            int r=arr[i][1];
            if(r==-1){
                nodes[i]->random=nullptr;
            }
            else{
                nodes[i]->random=nodes[r];
            }
        }
        return nodes[0];
    }

    void Print(Node* head){
        Node* temp=head;
        
        while(temp!=nullptr){
            cout<<temp->data<<" -> ";
            if(temp->random){
                cout<<temp->random->data;
            }
            else{
                cout<<"Null";
            }
            cout<<endl;
            temp=temp->next;
        }
        cout<<endl;
    }

    void insertCopyInBetween(Node* head){
        Node* temp = head;
        while(temp!= nullptr) {
            Node* nextElement = temp->next;
            Node* copy = new Node(temp->data);

            temp->next=copy;
            copy->next=nextElement;
            temp=nextElement;
        }
    }

    void connectRandomPointers(Node* head){
        Node* temp=head;
        while(temp!=nullptr){
            Node* copyNode = temp->next;
            if(temp->random){
                copyNode->random=temp->random->next;
            }
            else{
                copyNode->random=nullptr;
            }
            temp=temp->next->next;
        }
    }

    Node* getDeepCopyList(Node* head){
        Node* temp=head;
        Node* dummyNode = new Node(-1);
        Node* res = dummyNode;

        while(temp!=nullptr){
            //creating new list
            res->next = temp->next;
            res=res->next;

            //disconnecting and going back to initial state of the LL
            temp->next=temp->next->next;
            temp=temp->next;
        }
        return dummyNode->next;
    }

    Node* CloneLL(Node* head){
        insertCopyInBetween(head);
        connectRandomPointers(head);
        return getDeepCopyList(head);
    }
};

int main(){
    Solution obj;
    vector<vector< int>> arr={
        {1,-1},
        {2,0},
        {3,4},
        {4,1},
        {5,2}
    };
    Node* head = obj.ConvertArr2LL1(arr);
    obj.Print(head);
    
    Node* temp = obj.CloneLL(head);
    obj.Print(head);
    return 0;
}