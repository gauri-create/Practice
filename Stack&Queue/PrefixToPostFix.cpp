#include<iostream>
#include<stack>
using namespace std;

class Solution{
    public:
    string PrefixToPostfix(string s){
        int i=s.size()-1;
        stack<string>st;
        string p, t1, t2;
        while(i>=0){
            p=s[i];
            if((p>="A" && p<="Z") || (p>="a" && p<="z") || (p>="0" && p<="9")) st.push(p);
            else{
                t1=st.top();
                st.pop();
                t2=st.top();
                st.pop();
                st.push(t1+t2+p);
            }
            i--;
        }
        return st.top();
    }

};

int main(){
    Solution obj;
    string s="/-AB*+DEF";
    string ans=obj.PrefixToPostfix(s);
    cout<<ans;
    return 0;
}