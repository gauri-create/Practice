#include<iostream>
#include<string>
#include<unordered_map>
using namespace std;

class Solution{
    public:
    bool ValidString1(string s, string t){
        if(s.length()!=t.length()) return false;
        unordered_map<char, int> mpp;
        // int i=0;
        for(int i=0; i<s.length();i++){
            mpp[s[i]]++;
        }
        for(int i=0;i<t.length();i++){
            mpp[t[i]]--;
        }
        for(auto it : mpp){
            if(it.second!=0) return false;
        }
        return true;
    }
};

int main(){
    string s, t;
    
    cout<<"Enter first string:"<<endl;
    cin>>s;
    cout<<"Enter second string:"<<endl;
    cin>>t;
    Solution obj;
    bool ans = obj.ValidString1(s,t);
    if(ans==1) cout<<"string is valid anagram";
    else cout<<"string is not valid anagram";


}