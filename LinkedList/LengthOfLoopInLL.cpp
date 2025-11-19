#include<iostream>
#include<vector>
using namespace std;

class Node{
    public:
    int data;
    Node* next;

    Node(int data1){
        data = data1;
        next = nullptr;
    }

    Node(int data1, Node* next1){
        data = data1;
        next = next1;
    }
};

Node* ConvertArr2LL(vector<int> &arr){
    if(arr.size() == 0) return nullptr;

    Node* head = new Node(arr[0]);
    Node* prev = head;

    for(int i = 1; i < arr.size(); i++){
        Node* temp = new Node(arr[i]);
        prev->next = temp;
        prev = temp;
    }
    return head;
}

void print(Node* head){
    while(head){
        cout << head->data << " ";
        head = head->next;
    }
    cout << "\n";
}

// Correct Floyd's Cycle Length Code
int LengthOfLoop(Node* head){
    if(!head || !head->next) return 0;

    Node* slow = head;
    Node* fast = head;

    while(fast && fast->next){
        slow = slow->next;
        fast = fast->next->next;

        if(slow == fast){  
            // Count loop length
            int length = 1;
            Node* cur = slow->next;
            while(cur != slow){
                length++;
                cur = cur->next;
            }
            return length;
        }
    }
    return 0;
}

// Simple, safe, predictable loop creation
Node* CreateLoop(Node* head){
    if(!head || !head->next) return head;

    // make last node point to 3rd node
    Node* last = head;
    while(last->next) last = last->next;

    Node* loopNode = head->next->next;  // 3rd node
    last->next = loopNode;

    return head;
}

int main(){
    vector<int> arr = {1,3,2,5,7,9};
    Node* head = ConvertArr2LL(arr);

    cout << "List elements: ";
    print(head);

    head = CreateLoop(head);

    int loopLength = LengthOfLoop(head);
    cout << "Length of loop is " << loopLength << endl;

    return 0;
}
