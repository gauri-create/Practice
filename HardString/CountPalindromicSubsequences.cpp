#include<iostream>
#include<vector>
using namespace std;

class Solution{
    // //Brute Force Approach
    // bool isPalindrome(string s){
    //     int left=0, right=s.size()-1;
    //     while(left<right){
    //         if(s[left++] != s[right--]) return false;
    //     }
    //     return true;
    // }

    // int count(string s, string curr, int index){
    //     if(index==s.length()){
    //         if(!curr.empty() && isPalindrome(curr)) return 1;
    //         return 0;
    //     }
    //     int include=count(s, curr+s[index], index+1);
    //     int exclude=count(s, curr, index+1);
    //     return include+exclude;
    // }

    // public:
    // int countPalSubseq(const string &s){
    //     return count(s, "", 0);
    // }

    // //Memoization
    // private:
    // int count(string &s, int i, int j, vector<vector<int>>&dp){
    //     if(i>j) return 0;
    //     if(i==j) return 1;
    //     if(dp[i][j] != -1) return dp[i][j];
    //     if(s[i]==s[j]) dp[i][j]=count(s, i+1, j, dp)+ count(s, i, j-1, dp)+1;
    //     else dp[i][j]=count(s, i+1, j,  dp)+count(s, i, j-1, dp)-count(s, i+1, j-1, dp);
    //     return dp[i][j];
    // }
    // public:
    // int countPalSubseq(string s){
    //     int n=s.size();
    //     vector<vector<int>>dp(n, vector<int>(n, -1));
    //     return count(s, 0, n-1, dp);
    // }

    //Tabulation
    public:
    int countPalSubseq(string s){
        int n=s.size();
        vector<vector<int>>dp(n, vector<int>(n, 0));
        for(int i=0; i<n; i++){
            dp[i][i]=1;
        }
        for(int len=2; len<=n; len++){
            for(int i=0; i<=n-len; i++){
                int j=i+len-1;
                if(s[i]==s[j]) dp[i][j]=dp[i+1][j]+dp[i][j-1]+1;
                else dp[i][j]=dp[i+1][j]+dp[i][j-1]-dp[i+1][j-1];
            }
        }
        return dp[0][n-1];
    }
};

int main(){
    string s="abcd";
    Solution obj;
    int ans=obj.countPalSubseq(s);
    cout<<ans;
    return 0;
}