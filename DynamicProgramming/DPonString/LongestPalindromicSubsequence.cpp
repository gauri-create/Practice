#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution{
   
    private:
 //Tabulation

    // int lcs(string s1, string s2){
    //     int n=s1.size();
    //     int m=s2.size();

    //     vector<vector<int>>dp(n+1, vector<int>(m+1, 0));
    //     for(int i=0; i<=n; i++){
    //         dp[i][0]=0;
    //     }
    //     for(int j=0; j<=m; j++){
    //         dp[0][j]=0;
    //     }

    //     for(int i=1; i<=n; i++){
    //         for(int j=1; j<=m; j++){
    //             if(s1[i-1]==s2[j-1]){
    //                 dp[i][j]=1+dp[i-1][j-1];
    //             }
    //             else{
    //                 dp[i][j]=max(dp[i-1][j], dp[i][j-1]);
    //             }
    //         }
    //     }
    //     return dp[n][m];
    // }

//Space Optimization
    int lcs(string s1, string s2){
        int n=s1.size();
        int m=s2.size();

        vector<int> prev(n+1, 0),cur(m+1, 0);
        int ans=0;

        for(int ind1=1; ind1<=n; ind1++){
            for(int ind2=1; ind2<=m; ind2++){
                if(s1[ind1]==s2[ind2]){
                    cur[ind2]=1+prev[ind2-1];
                }
                else{
                    cur[ind2]=max(prev[ind2], cur[ind2-1]);
                }
            }
            prev=cur;
        }   
        return prev[m];
    }

    public:
    int longestPalindromeSubseq(string s){
        string t=s;
        reverse(s.begin(), s.end());
        return lcs(s, t);
    }
};

int main(){
    string s="eeeme";
    Solution obj;
    int ans = obj.longestPalindromeSubseq(s);
    cout<<ans;
    return 0;
}