#include<iostream>
#include<vector>
using namespace std;

class Solution{
    // //Memoization
    // private:
    // bool isPalindrome(const string& s, int start, int end){
    //     while(start<end){
    //         if(s[start]!=s[end]) return false;
    //         start++;
    //         end--;
    //     }
    //     return true;
    // }
    // int minCutsHelper(const string& s, int start, vector<int>& memo){
    //     int n=(int)s.size();
    //     if(start==n || isPalindrome(s, start, n-1)) return 0;
    //     if(memo[start] != -1)return memo[start];
    //     int minCuts=INT_MAX;
    //     for(int end=start; end<n; end++){
    //         if(isPalindrome(s, start, end)){
    //             int cuts=1+minCutsHelper(s, end+1, memo);
    //             minCuts=min(minCuts, cuts);
    //         }
    //     }
    //     return memo[start]=minCuts;
    // }
    // public:
    // int minCut(string s){
    //     int n=(int)s.size();
    //     vector<int>memo(n, -1);
    //     return minCutsHelper(s, 0, memo);
    // }

    //Tabulation
    private:
    bool isPalindrome(const string &s, int i, int j){
        while(i<j){
            if(s[i]!=s[j]) return false;
            i++;
            j--;
        }
        return true;
    }
    public:
    int minCut(string s){
        int n=(int)s.size();
        vector<int>dp(n+1, 0);
        dp[n]=-1;
        for(int i=n-1; i>=0; i--){
            int minCuts=INT_MAX;
            for(int j=0; j<n; j++){
                if(isPalindrome(s, i, j)){
                    minCuts=min(minCuts, 1+dp[j+1]);
                }
            }
            dp[i]=minCuts;
        }
        return dp[0];
    }

};

int main(){
    string s="aab";
    Solution obj;
    int ans=obj.minCut(s);
    cout<<ans;
    return 0;
}