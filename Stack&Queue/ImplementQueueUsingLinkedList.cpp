#include<iostream>
#include<vector>
using namespace std;

class Node{
    public:
    int val;
    Node* next;
    Node(int d){
        val=d;
        next=nullptr;
    }
};

class LinkedListQueue {
private:
    Node* start;
    Node* end;
    int size;

public:
    LinkedListQueue() {
        start=end=nullptr;
        size=0;
    }
    
    void push(int x) {
        Node* element = new Node(x);
        if(start == nullptr){
            start=end=element;
        }
        else{
            end->next=element;
            end=element;
        }
        size++;
    }
    
    int pop() {
        if(start==nullptr){
            return -1;
        }
        int value = start->val;
        Node *temp = start;
        start= start->next;
        delete temp;
        size--;
        return value;
    }
    
    int peek() {
        if(start==nullptr){
            return -1;
        }
        return start->val;
    }
    
    bool isEmpty() {
        return (size==0);
    }
};

int main(){
    LinkedListQueue llq;
    vector<string> commands={"LinkedListQueue", "push", "push", "peek", "pop", "isEmpty"};
    vector<vector<int>> input={{}, {3}, {7}, {}, {}, {}};
    for(int i=0; i<commands.size(); i++){
        if(commands[i]=="push"){
            llq.push(input[i][0]);
            cout<<"null ";
        }
        else if(commands[i]=="pop"){
            cout<<llq.pop()<<" ";
        }
        else if(commands[i]=="peek"){
             cout<<llq.peek()<<" ";
        }
        else if(commands[i]=="isEmpty"){
            cout<<(llq.isEmpty()?"true":"false")<<" ";
        }
        else if(commands[i]=="LinkedListQueue"){
            cout<<"null ";
        }
    }
    return 0;
}