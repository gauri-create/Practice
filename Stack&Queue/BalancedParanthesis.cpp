#include<iostream>
#include<stack>
using namespace std;

class Solution {
public:
    bool isValid(string str) {
        stack<char> st;
        for(int i=0; i<str.size(); i++){
            if(str[i]=='('||str[i]=='['||str[i]=='{')
                st.push(str[i]);
            else{
                char ch=st.top();
                
                if((str[i]==')'&&ch=='(') || (str[i]==']'&&ch=='[') || (str[i]=='}'&&ch=='{')){
                    st.pop();
                }
                else
                   return false;
            }
        }
        return st.empty();
    }
};

int main(){
    Solution obj;
    string s="[()";
    bool ans=obj.isValid(s);
    if(ans==true) cout<<"Paranthesis is balanced";
    else 
        cout<<"Paranthesis is not balanced";
    return 0;
}