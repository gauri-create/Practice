#include <iostream>
#include <vector>
using namespace std;

class Solution
{
//     //Memoization   
// private:
//     int helper(int i, int j, string &s, string &t, vector<vector<int>> &dp)
//     {
//         if (j == t.size())
//             return 1;
//         if (i == s.size())
//             return 0;
//         if (dp[i][j] != -1)
//             return dp[i][j];
//         if (s[i] == t[j])
//         {
//             int take = helper(i + 1, j + 1, s, t, dp);
//             int notTake = helper(i + 1, j, s, t, dp);
//             return dp[i][j] = take + notTake;
//         }
//         else
//             return dp[i][j] = helper(i + 1, j, s, t, dp);
//     }

// public:
//     int distinctSubsequence(string s, string t)
//     {
//         vector<vector<int>> dp(s.size(), vector<int>(t.size(), -1));
//         return helper(0, 0, s, t, dp);
//     }

// //Tabulation
// public:
//     int distinctSubsequence(string s, string t){
//         int n=s.size();
//         int m=t.size();

//         vector<vector<int>>dp(n+1, vector<int>(m+1, 0));
 
//         for(int i=0; i<=n; i++){
//             dp[i][m]=1;
//         }
//         for(int i=n-1; i>=0; i--){
//             for(int j=m-1; j>=0; j--){
//                 if(s[i]==t[j]){
//                     dp[i][j]=dp[i+1][j+1]+dp[i+1][j];
//                 }
//                 else{
//                     dp[i][j]=dp[i+1][j];
//                 }
//             }
//         }
//         return dp[0][0];
//     }

// //Space Optimization
// public:
    int distinctSubsequence(string s, string t){
        int n=s.size();
        int m=t.size();
        vector<int>dp(m+1, 0);
        dp[m]=1;
        for(int i=n-1; i>=0; i--){
            vector<int>cur=dp;
            for(int j=m-1; j>=0; j--){
                if(s[i]==t[j]) cur[j]=dp[j+1]+dp[j];
                else cur[j]=dp[j];
            }
            dp=cur;
        }
        return dp[0];
    }
};

int main()
{
    string s = "axbxax";
    string t = "axa";
    Solution obj;
    int ans = obj.distinctSubsequence(s, t);
    cout << ans;
    return 0;
}