#include<iostream>
#include<vector>
using namespace std;

class Solution{
    // //Memoization
    // private:
    // int func(string& s1, string& s2, int ind1, int ind2, vector<vector<int>>& dp){
    //     if(ind1<0 || ind2<0) return 0;

    //     if(dp[ind1][ind2] != -1) return dp[ind1][ind2];

    //     if(s1[ind1] == s2[ind2]){
    //         return dp[ind1][ind2] = 1+func(s1, s2, ind1-1, ind2-1, dp);
    //     }
       
    //         return dp[ind1][ind2] = max(func(s1, s2, ind1, ind2-1, dp), func(s1, s2, ind1-1, ind2, dp));
        
    // }

    // public:
    // int lcs(string str1, string str2){
    //     int n=str1.size();
    //     int m=str2.size();
    //     vector<vector<int>>dp(n, vector<int>(m, -1));
    //     return func(str1, str2, n-1, m-1, dp);
    // }

    // //Tabulation
    // public:
    // int lcs(string str1, string str2){
    //     int n=str1.size();
    //     int m=str2.size();

    //     vector<vector<int>>dp(n+1, vector<int>(m+1, -1));

    //     for(int i=0; i<=m; i++){
    //         dp[i][0]=0;
    //     }
    //     for(int i=0; i<=m; i++){
    //         dp[0][i]=0;
    //     }

    //     for(int ind1=1; ind1<=n; ind1++){
    //         for(int ind2=1; ind2<=m; ind2++){
    //             if(str1[ind1-1] == str2[ind2-1]){
    //                 dp[ind1][ind2]=1+dp[ind1-1][ind2-1];
    //             }
    //             else{
    //                 dp[ind1][ind2]=max(dp[ind1-1][ind2], dp[ind1][ind2-1]);
    //             }
    //         }
    //     }
    //     return dp[n][m];
    // }

    //Space Optimization
    public:
    int lcs(string str1, string str2){
        int n=str1.size();
        int m=str2.size();

        vector<int>prev(n+1, 0) , cur(m+1, 0);

        for(int ind1=1; ind1<=n; ind1++){
            for(int ind2=1; ind2<=m; ind2++){
                if(str1[ind1-1]==str2[ind2-1]){
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

};

int main(){
    string str1="bdefg";
    string str2="bfg";
    Solution obj;
    int ans=obj.lcs(str1, str2);
    cout<<ans;
    return 0;
}