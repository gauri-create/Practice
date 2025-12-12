#include<iostream>
#include<algorithm>
#include<stack>
using namespace std;

class Solution{
    private:
    int priority(char c){
        if(c=='^') return 3;
        if(c=='*'||c=='/') return 2;
        if(c=='+' || c== '-') return 1;
        return 0;
    }

    public:
    string infixToPrefix(string sr){
        //reverse string
        string s=sr;
        reverse(s.begin(), s.end());
        //swap ( and )
        for(char &c : s){
            if(c=='(') c=')';
            else if(c==')') c='(';
        }
        //convert post fix
        stack<char>st;
        string postfix;
        for(char c: s){
            if(isalnum(c)){
                postfix += c;
            }
            else if(c=='('){
                st.push(c);
            }
            else if(c==')'){
                while(!st.empty()&&st.top()!='('){
                    postfix += st.top();
                    st.pop();
                }
                st.pop();
            }
            else{
                while(!st.empty() && priority(c)<=priority(st.top())){
                    postfix += st.top();
                    st.pop();
                }
                st.push(c);
            }
        }
        while(!st.empty()){
            // if((st.top()!='(')&& (st.top()!=')')){
                postfix += st.top();
                
            // }
            st.pop();
        }

        reverse(postfix.begin(), postfix.end());
        return postfix;
    }
};

int main(){
    string s="(a+b)*c";
    Solution obj;
    string ans=obj.infixToPrefix(s);
    cout<<ans;
    return 0;
}