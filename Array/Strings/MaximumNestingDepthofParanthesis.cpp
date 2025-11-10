#include<iostream>
#include<string>
using namespace std;

class Solution{
public:
    int MaxDepthParanthesis(string s){
        int cnt=0;
        int maxcnt=0;
        for(int i=0;i<s.length(); i++){
            if(s[i]=='(') cnt++;
            else if(s[i]==')')cnt--;
            maxcnt=max(maxcnt,cnt);
        }
        return maxcnt;
    }

};

int main(){
    string s;
    cout<<"Enter string"<<endl;
    cin>>s;

    Solution obj;

    int ret=obj.MaxDepthParanthesis(s);
    cout<<"Maximum Nesting depth of paranthesis is "<<ret;
    return 0;
}