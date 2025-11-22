#include<iostream>
#include<vector>
using namespace std;

class Solution{
    public:
    vector<vector<string>> PalindromePartition(string s){
        vector<vector<string>>ans;
        vector<string>ds;
        partition(0,s.size(),s,ans, ds);
        return ans;
    }

    private:
    void partition(int ind,int n, string &s, vector<vector<string>> &ans, vector<string>&ds){
        if(ind==n){
            ans.push_back(ds);
            return;
        }
        for(int i=ind; i<s.size(); i++){
            if(isPalindrome(s,ind,i)){
                ds.push_back(s.substr(ind, i-ind+1));
                partition(i+1, n, s,ans, ds);
                ds.pop_back();
            }
        }
    }
    bool isPalindrome(string s, int start, int end){
        while(start<=end){
            if(s[start++]!=s[end--]) return false;
        }
        return true;
    }
};

int main(){
    Solution obj;
    string st="aabb";
    vector<vector<string>> ans=obj.PalindromePartition(st);
    for(auto x: ans){
        cout<<"[";
        for(auto i: x){
            cout<<i<<" ";
        }
        cout<<"]";
    }
    return 0;
}
