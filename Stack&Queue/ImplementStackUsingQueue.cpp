#include<iostream>
#include<vector>
#include<queue>
using namespace std;

class QueueStack {
    queue<int>q;
public:
    QueueStack() {
    }
    
    void push(int x) {
        int s=q.size();
        q.push(x);
        for(int i=0; i<s; i++){
            q.push(q.front());
            q.pop();
        }
    }
    
    int pop() {
        int n=q.front();
        q.pop();
        return n;
    }
    
    int top() {
        return q.front();
    }
    
    bool isEmpty() {
        return q.empty();
  
    }
};

int main(){
    QueueStack qs;

    vector<string>commands={"QueueStack", "push", "push", "pop", "top", "isEmpty"};
    vector<vector<int>> inputs={{}, {4}, {8}, {}, {},{}};
    for(int i=0; i<commands.size(); i++){
        if(commands[i]=="push"){
            qs.push(inputs[i][0]);
            cout<<"null ";
        }
        if(commands[i]=="pop"){
            cout<<qs.pop()<<" ";
        }
        if(commands[i]=="top"){
            cout<<qs.top()<<" ";
        }
        if(commands[i]=="isEmpty"){
            cout<<(qs.isEmpty()?"true":"false")<<" ";
        }
        else if(commands[i]=="QueueStack"){
            cout<<"null ";
        }
    }
    return 0;
}