#include<iostream>
#include<stack>
using namespace std;

class Solution{
    public:
    string PostfixToPrefix(string s){
        int i=0;
        stack<string>st;
        string p,t1,t2,temp;
        while(i<s.size()){
            p=s[i];
            if((p>="A" && p<="z") || (p>="a" && p<="z") || (p>="0" && p<="9")) st.push(p);
            else {
                t1=st.top();
                st.pop();
                t2=st.top();
                st.pop();
                st.push(p+t2+t1);
            }
            i++;
        }
        return st.top();
    }
};

int main(){
    Solution obj;
    string s="AB-DE+F*/";
    string ans=obj.PostfixToPrefix(s);
    cout<<ans;
    return 0;
}