#include <iostream>
#include <vector>
#include<string>
#include<algorithm>
using namespace std;

class Solution
{
public:
// //Tabulation
//     int minOperations(string s1, string s2)
//     {
//         int n = s1.size();
//         int m = s2.size();
//         vector<vector<int>> dp(m + 1, vector<int>(m + 1, 0));
//         for (int i = 1; i <= n; i++)
//         {
//             for (int j = 1; j <= m; j++)
//             {

//                 if (s1[i - 1] == s2[j - 1]){
//                     dp[i][j]=1+dp[i-1][j-1];
//                 }
//                 else{
//                     dp[i][j]=max(dp[i][j-1], dp[i-1][j]);
//                 }
//             }
//         }
//         int lcs=dp[n][m];
//         return (n-lcs)+(m-lcs);
//     }

//Space Optimization
    int minOperations(string s1, string s2){
        int n=s1.size();
        int m=s2.size();
        
        vector<int>prev(m+1, 0), cur(m+1, 0);
        int lcs=0;
        for(int i=1; i<=n; i++){
            for(int j=1; j<=m; j++){
                if(s1[i-1]==s2[j-1]){
                    cur[j]=1+prev[j-1];
                }
                else{
                    cur[j]=max(prev[j], cur[j-1]);
                }
            }
            prev=cur;
        }
        lcs=prev[m];
        return (n-lcs)+(m-lcs);
    }
};

int main()
{
    string s1 = "sitting";
    string s2 = "kitten";
    Solution obj;
    int ans = obj.minOperations(s1, s2);
    cout << ans;
    return 0;
}