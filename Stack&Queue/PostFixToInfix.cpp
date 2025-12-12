#include<iostream>
#include<stack>
#include<algorithm>
using namespace std;

class Solution{
    private:
    int priority(char c){
        if(c=='^') return 3;
        else if(c=='*' || c=='/') return 2;
        else if(c=='+'|| c=='-') return 1;
        else return 0;
    }
    public:
    string PostfixToInfix(string s){
        
        int i=0;
        int n=s.size();
        stack<string> st;
        while(i<n){
            string p;
            p += s[i]; 
            if((p>="A" && p<= "Z")||(p>="a" && p<="z")||(p>="0" && p<="9")){
                st.push(p);
            }
            else{
                string t1=st.top();
                st.pop();
                string t2=st.top();
                st.pop();
                string temp = '('+t2+p+t1+')';
                st.push(temp);
            }
            i++;
        }

        return st.top();
    }
};

int main(){
    Solution obj;
    string s="AB-DE+F*/";
    string ans=obj.PostfixToInfix(s);
    cout<<ans;
    return 0;
}