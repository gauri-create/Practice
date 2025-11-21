#include<iostream>
#include<vector>
using namespace std;

class Node{
    public:
    int data;
    Node* next;
    Node* child;

    public:
    Node(){
        data=0;
        next=nullptr;
        child=nullptr;
    }
    Node(int data1){
        data=data1;
        next=nullptr;
        child=nullptr;
    }
    Node(int data1, Node* next1, Node* child1){
        data=data1;
        next=next1;
        child=child1;
    }
};

class Solution{

    public:
    Node* merge(Node* list1, Node* list2){
        Node* dummyNode = new Node(-1);
        Node* res=dummyNode;
        while(list1 != nullptr && list2 != nullptr){
            if(list1->data < list2->data){
                res->child=list1;
                res=list1;
                list1=list1->child;
            }
            else{
                res->child=list2;
                res=list2;
                list2=list2->child;
            }
            res->next=nullptr;
        }
        if(list1) res->child=list1;
        else res->child = list2;
        if(dummyNode->child) dummyNode->child->next=nullptr;
        return dummyNode->child;
    }

    Node* flattenLinkedList(Node* head){
        if(head==nullptr || head->next==nullptr) return head;
        Node* mergedHead = flattenLinkedList(head->next);
        head=merge(head, mergedHead);
        return head;
    }


    Node* buildNextList(const vector<int>&arr){
        if(arr.empty()) return nullptr;
        
        Node* head = new Node(arr[0]);
        Node* curr = head;

        for(int i=1; i<arr.size(); i++){
            curr->next=new Node(arr[i]);
            curr=curr->next;
        }
        return head;
    }

    Node* buildChildList(const vector<int>&arr){
        if(arr.empty()) return nullptr;

        Node* head=new Node(arr[0]);
        Node* curr = head;
        for(int i=1; i<arr.size(); i++){
            curr->child=new Node(arr[i]);
            curr=curr->child;
        }
        return head;
    }

    Node* buildBranchedList(){
        //main chain
        vector<int> mainNodes={3,10,7,11,12};
        Node* head =buildNextList(mainNodes);

        //brach 1 from node 3
        vector<int>branch1={2,1,4,5};
        head->child=buildChildList(branch1);

        //Branch 2 from node7
        Node* temp = head;
        while(temp && temp->data != 7)
            temp=temp->next;

        vector<int>branch2={9,8};
        temp->child = buildChildList(branch2);
        return head;
    }

    void printBranched(Node* head){
        while(head){
            cout<<head->data<<" ";
            if(head->child) cout <<"( child->"<<head->child->data<<")";
            cout<<endl;
            head=head->next;
        }
        cout<<endl<<endl;
    }

    void Print(Node* head){
        while(head!=nullptr){
            cout<<head->data<<" ";
            head=head->child;
        }

    }


    Node* buildBranchedFrom2D(const vector<vector<int>> & arr){
        if(arr.empty()) return nullptr;

        //first row = main chain 
        vector<int> mainNodes = arr[0];
        Node* head = buildNextList(mainNodes);

        //Now attach children
        Node*temp = head;
        for(int i=1; temp!=nullptr && i<arr.size(); i++, temp=temp->next){
            if(!arr[i].empty()){
                temp->child=buildChildList(arr[i]);
            }
        }
        return head;

    }
};

int main(){
    Solution obj;
    // Node* head=obj.buildBranchedList();

    vector<vector<int>> arr={
        {3,2,1,4,5},
        {},
        {10},
        {7,11,12},
        {9},
        {6,8}
    };
    Node* head=obj.buildBranchedFrom2D(arr);

    obj.printBranched(head);
    Node* temp= obj.flattenLinkedList(head);
    obj.Print(temp);
    return 0;
}

  