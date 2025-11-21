#include<iostream>
#include<vector>
#include<stack>
using namespace std;

class Solution{
public:
    stack<int> ReverseStack(stack<int> &s){
         if(s.empty()){
            return s;
        }
        int top = s.top();
        s.pop();

        ReverseStack(s);
        insert(top, s);

        return s;
    }

private:
    void insert(int element, stack<int> &s){
        if(s.empty()){
            s.push(element);
            return;
        }
        int top = s.top();
        s.pop();

        insert(element, s);
        s.push(top);
    }
public:
    void PrintStack(stack<int>st){
        while(!st.empty()){
            cout<<st.top()<<" ";
            st.pop();
        }
        cout<<endl;
    }
};

int main(){
    vector<int> arr={4,1,3,2};
    stack<int> st;
    for(int x : arr){
        st.push(x);
    }
    Solution obj;
    obj.PrintStack(st);
    stack<int> ans =  obj.ReverseStack(st);
    obj.PrintStack(ans);
    return 0;
}

