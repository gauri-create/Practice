#include<iostream>
#include<vector>
using namespace std;

class ArrayQueue {
private:
    int* Qarray;
    int start, end;
    int currSize, maxSize;
   
public:
    ArrayQueue() {
        Qarray=new int [10];
        start=-1;
        end=-1;
        currSize=0;
        maxSize=10;
    }
    ~ArrayQueue(){
        delete[] Qarray;
    }
    
    void push(int x) {
        if(currSize == maxSize){
            cout<<"stack overfow"<<endl;
            exit(1);
        }
        
        if(end ==-1){
            start = 0;
            end = 0;
        }

        else{
            end = (end+1)%maxSize;
        }
        Qarray[end]=x;
        currSize++;
    }
    
    int pop() {
        if(start==-1){
            cout<<"Queue Empty \nExisting..."<<endl;
            exit(1);
        }
        int popped = Qarray[start];
        if(currSize ==1){
            start = -1;
            end = -1;
        }  
        else{
            start = (start +1)%maxSize;
        }
        currSize--;
        return popped;
    }
    
    int peek() {
        if(start == -1){
            cout<<"Queue is Empty"<<endl;
            exit(1);
        }
        return Qarray[start];
    }
    
    bool isEmpty() {
        return (currSize==0);
    }
};

int main(){
    ArrayQueue Q;
    vector<string> commands ={"ArrayQueue", "isEmpty"};
    vector<vector<int>> inputs={{}};
    for(int i=0; i<commands.size();i++){
        if(commands[i]=="ArrayQueue"){
            cout<<" null ";            
        }
        else if(commands[i]=="push"){
            Q.push(inputs[i][0]);
            cout<<" null ";
        }
        else if(commands[i]=="pop"){
            cout<<Q.pop()<<" ";
        }
        else if(commands[i]=="peek"){
            cout<<Q.peek()<<" ";
        }
        else if(commands[i]=="isEmpty"){
            cout<<(Q.isEmpty()?"true":"false");
        }
    }
    return 0;
}