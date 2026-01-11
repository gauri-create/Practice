#include<iostream>
#include<vector>
using namespace std;

class Solution{
    // //Tabulation
    // public:
    // int longestCommonSubstr(string str1, string str2){
    //     int n= str1.size();
    //     int m= str2.size();

    //     vector<vector<int>>dp(n+1, vector<int>(m+1, 0));

    //     int ans=0;

    //     for(int i=1; i<=n; i++){
    //         for(int j=1; j<=m; j++){
    //             if(str1[i-1]== str2[j-1]){
    //                 dp[i][j]=1+dp[i-1][j-1];
    //                 ans=max(ans, dp[i][j]);
    //             }
    //             else{
    //                 dp[i][j]=0;
    //             }
    //         }
    //     }
    //     return ans;
    // }

    //Space optimization
    public:
    int longestCommonSubstr(string str1, string str2){
        int n=str1.size();
        int m=str2.size();

        vector<int>prev(n+1, 0), cur(m+1, 0);
        int ans=0;

        for(int i=1; i<=n; i++){
            for(int j=1; j<=n; j++){
                if(str1[i-1]==str2[j-1]){
                    int val=1+prev[j-1];
                    cur[j]=val;
                    ans=max(ans, val);
                }
                else{
                    cur[j]=0;
                }
            }
            prev=cur;
        }
        return ans;
    }
};

int main(){
    string str1="abcde";
    string str2="abfce";
    Solution obj;
    int ans=obj.longestCommonSubstr(str1, str2);
    cout<<ans;
    return 0;
}