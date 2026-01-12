#include<iostream>
#include<vector>
using namespace std;

class Solution{
    // //Memoization
    // private:
    // int helper(string s, string t, int i, int j, vector<vector<int>>& dp){
    //     if(i<0) return j+1;
    //     if(j<0) return i+1;
    //     if(dp[i][j]!= -1) return dp[i][j];
    //     if(s[i]==t[j])
    //         return dp[i][j]=0+helper(s, t, i-1, j-1, dp);
    //     else
    //         return dp[i][j]=1+min(helper(s, t, i-1, j-1, dp), min(helper(s, t, i-1, j, dp), helper(s, t, i, j-1, dp)));
    // }
    // public:
    // int editDistance(string start, string target){
    //     int n=start.size();
    //     int m=target.size();
    //     vector<vector<int>>dp(n,vector<int>(m, -1));
    //     return helper(start, target, n-1, m-1, dp);
    // }

    // //Tabulation
    // public:
    // int editDistance(string start, string target){
    //     int n=start.size();
    //     int m=target.size();
    //     vector<vector<int>>dp(n+1, vector<int>(m+1, 0));

    //     for(int i=0; i<=n;i++){
    //         dp[i][0]=i;
    //     }
    //     for(int j=0; j<=m; j++){
    //         dp[0][j]=j;
    //     }

    //     for(int i=1; i<=n; i++){
    //         for(int j=1; j<=m; j++){
    //             if(start[i-1]==target[j-1]){
    //                 dp[i][j]=dp[i-1][j-1];
    //             }
    //             else{
    //                 dp[i][j]=1+min(dp[i-1][j-1], min(dp[i-1][j], dp[i][j-1]));
    //             }
    //         }
    //     }
    //     return dp[n][m];
    // }

    //Space Optimization
    public:
    int editDistance(string start, string target){
        int n=start.size();
        int m=target.size();
        vector<int>prev(m+1, 0);
        vector<int>cur(m+1, 0);

        for(int j=0; j<=m; j++){
            prev[j]=j;
        }
        for(int i=1; i<=n; i++){
            cur[0]=i;
            for(int j=1; j<=m; j++){
                if(start[i-1] == target[j-1]){
                    cur[j]=prev[j-1];
                }
                else{
                    cur[j]=1+min(prev[j-1], min(prev[j], cur[j-1]));
                }
            }
            prev=cur;
        }
        return cur[m];
    }
};

int main(){
    string start="planet";
    string target="plan";
    Solution obj;
    int ans=obj.editDistance(start, target);
    cout<<ans;
    return 0;
}