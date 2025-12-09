//Using two stacks where Push Operation is O(N)
#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class StackQueue{
    private:
    stack<int> input, output;

    public:
    StackQueue(){}

    void push(int x){
        input.push(x);
    }

    int pop(){
        if(output.empty()){
            while(!input.empty()){
                output.push(input.top());
                input.pop();
            }
        }
        if(output.empty()){
            cout<<"Queue is empty, cannot pop"<<endl;
            return -1;
        }
        int x= output.top();
        output.pop();
        return x;
    }

    int peek(){
        if(output.empty()){
            while(!input.empty()){
                output.push(input.top());
                input.pop();
            }
        }
        if(output.empty()){
            cout<<"Queue is empty, cannot peek"<<endl;
            return -1;
        }   
        return output.top();
    }

    bool isEmpty(){
        return input.empty() && output.empty();
    }
};

int main(){
    StackQueue sq;
    vector<string> commands={"StackQueue", "push", "push", "pop", "peek", "isEmpty"};
    vector<vector<int>> inputs={{}, {4}, {8}, {}, {}, {}};
    for(int i=0; i<commands.size();i++){
        if(commands[i]=="push"){
            sq.push(inputs[i][0]);
            cout<<"null ";
        }
        else if(commands[i]=="pop"){
            cout<<sq.pop()<<" ";
        }
        else if(commands[i]=="peek"){
            cout<<sq.peek()<<" ";
        }
        else if(commands[i]=="isEmpty"){
            cout<<(sq.isEmpty()?"true":"false")<<" ";
        }
        else if(commands[i]=="StackQueue"){
            cout<<"null ";
        }
    }
    return 0;
}