#include<iostream>
#include<string>
using namespace std;

class Solution {
public:
    string removeOuterParentheses(string s) {
        // Your code goes here
        string ans;
        int cnt=0;
        for(char c : s){  
            if(c=='('){
                if(cnt>0){
                     ans += c;
                }
                cnt++;
            }
            else{
                cnt--;
                if(cnt>0){
                ans+=c;
                }
                
            }
        }
        return ans;
    }
};

int main(){
    Solution obj;
    
    string s;
    cout<<"Enter parantheses string: ";
    cin>>s;

    string ans=obj.removeOuterParentheses(s);
    cout<<"Output: "<<ans<< endl;
    return 0;
}
