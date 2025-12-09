#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class MinStack {
    int mini;
    stack<int>st;
public:

    MinStack() {
   
    }

  void push(int value) {
    if(st.empty()) {
        mini=value;
        st.push(value);
        return;
    }
    
    if(value>mini){
        st.push(value);
    }
    else{
        st.push(2*value-mini);
        mini=value;
        }
    }
        
  

  void pop() {
    if(st.empty()) return ;
    int x=st.top();
    st.pop();
    if(x < mini){
        mini=2*mini-x;
    }
  
  }

    int top() {
      if(st.empty())return -1;
      int x=st.top();
        if(mini<x) return x;
        return mini;
    }

  int getMin() {
    return mini;
  }
};

int main(){
    MinStack ms;
    vector<string>commands={"MinStack", "push", "push", "push", "getMin", "pop", "top", "getMin"};
    vector<vector<int>> inputs={{},{-2}, {0}, {-3}, {}, {}, {}, {}};
    for(int i=0; i<commands.size(); i++){
        if(commands[i]=="push"){
            ms.push(inputs[i][0]);
            cout<<"null ";
        }
        else if(commands[i]=="pop"){
            ms.pop();
            cout<<"null ";
        }
        else if(commands[i]=="top"){
            cout<<ms.top()<<" ";
        }
        else if(commands[i]=="getMin"){
            cout<<ms.getMin()<<" ";
        }
        else if(commands[i]=="MinStack"){
            cout<<"null ";
        }
    }
    return 0;
}