#include<iostream>
#include<vector>
using namespace std;

class Solution{
    // private:
    // bool isAllStars(string pat, int j){
    //     for(int k=0; k<=j; k++){
    //         if(pat[k]!='*') return false;
    //     }
    //     return true;
    // }

    // bool wildCardMatching(string &str, string &pat, int i, int j, vector<vector<int>> &dp){
    //     if(i<0 && j<0) return true;
    //     if(j<0 && i>=0) return false;
    //     if(i<0 && j>=0) return isAllStars(pat, j);
    //     if(dp[i][j] != -1) return dp[i][j];
    //     if(str[i]==pat[j] || pat[j]=='?'){
    //         return dp[i][j]=wildCardMatching(str, pat, i-1, j-1, dp);
    //     }
    //     if(pat[j]=='*'){
    //         return dp[i][j]=wildCardMatching(str, pat, i-1, j, dp) || wildCardMatching(str, pat, i, j-1, dp);
    //     }
    //     return dp[i][j]=false;

    // }
    // public:
    // bool wildCard(string str, string pat){
    //     int n=str.size();
    //     int m=pat.size();

    //     vector<vector<int>>dp(n, vector<int>(m, -1));
    //     return wildCardMatching(str, pat, n-1, m-1, dp);
    // }

    // //Tabulation
    // public:
    // bool isAllStars(string &s1, intn i){
    //     for(int j=0; j<i; j++){
    //         if(s1[j] != '*') return false;
    //     }
    //     return true;
    // }

    // bool wildCard(string &s1, string &s2){
    //     int n=s1.size();
    //     int m=s2.size();
    //     vector<vector<bool>> dp(n+1, vector<bool>(m+1, false));
    //     dp[0][0]=true;
    //     for(int j=1; j<=m; j++){
    //         dp[0][j]=false;
    //     }
    //     for(int i=1; i<=n; i++){
    //         dp[i][0]=isAllStars(s1, i);
    //     }
    //     for(int i=1; i<=n; i++){
    //         for(int j=1; j<=m; j++){
    //             if(s1[i-1] == s2[j-1] || s1[j-1] == '?'){
    //                 dp[i][j]=dp[i-1][j-1];
    //             }
    //             else if(s1[i-1]=='*'){
    //                 dp[i][j]=dp[i-1][j] || dp[i][j-1];
    //             }
    //             else{
    //                 dp[i][j]=false;
    //             }
    //         }
    //     }
    //     return dp[n][m];
    // }

    //Space Optimization
    bool isAllStars(string s1, int i){
        for(int j=1; j<=i; j++){
            if(s1[j-1]!='*') return false;
        }
        return true;
    }

    public:
    bool wildCard(string &s1, string &s2){
        int n=s1.size();
        int m=s2.size();
        vector<bool>prev(m+1, false);
        vector<bool>cur(m+1, false);
        prev[0]=true;
        for(int i=1; i<=n; i++){
            cur[0]=isAllStars(s1, i);
            for(int j=1; j<=m; j++){
                if(s1[i-1] == s2[j-1] || s1[i-1] == '?'){
                    cur[j]=prev[j-1];
                }
                else if(s1[i-1]=='*'){
                    cur[j]=prev[j]||cur[j-1];
                }
                else{
                    cur[j]=false;
                }
            }
            prev=cur;
        }
        return prev[m];
    }
};

int main(){
    string str="xaylmz";
    string pat="x?y*z";
    Solution obj;
    bool ans= obj.wildCard( pat, str);
    cout<<(ans?"True":"False");
    return  0;
}