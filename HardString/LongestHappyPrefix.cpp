#include<iostream>
#include<vector>
using namespace std;

class Solution{
    //Brute Force
    // public:
    // string lps(string s){
    //     int n=s.size();
    //     for(int len=n-1; len>0; len--){
    //         if(s.substr(0,len)==s.substr(n-len, len)){
    //             return s.substr(0,len);
    //         }
    //     }
    //     return "";
    // }

    //Optimal
    public:
    string lps(string s){
        vector<int>lps(s.length(), 0);
        int len=0;
        for(int i=1; i<s.length(); i++){
            if(s[i]==s[len]){
                len++;
                lps[i]=len;
            }
            else if(len!=0){
                len=lps[len-1];
                i--;
            }
        }
        return s.substr(0, lps[s.length()-1]);
    }
};

int main(){
    string s="ababab";
    Solution obj;
    string ans=obj.lps(s);
    cout<<ans;
    return 0;
}