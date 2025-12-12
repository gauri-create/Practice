#include<iostream>
#include<stack>
using namespace std;

class Solution{
    public:
    string PrefixToInfix(string s){
        int i=s.size()-1;
        stack<string>st;
        string p, t1, t2, temp;
        
        while(i>=0){
            p=s[i];
            if((p>="A" && p<="Z") || (p>="a"&&p<="z") || (p>="0" && p<="9")) st.push(p);
            else{
                t1=st.top();
                st.pop();
                t2=st.top();
                st.pop();
                temp='('+t1+p+t2+')';
                st.push(temp);
            }
            i--;
        }
        return st.top();
    }
};

int main(){
    Solution obj;
    string s="*+PQ-MN";
    string ans=obj.PrefixToInfix(s);
    cout<<ans;
    return 0;
}