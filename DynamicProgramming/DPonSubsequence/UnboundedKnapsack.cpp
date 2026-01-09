#include<iostream>
#include<vector>
using namespace std;

class Solution{
    // //Memoization
    // private:
    // int solve(vector<int>&wt, vector<int>&val, int ind, int W, vector<vector<int>>&dp){
    //     if(ind==0) return (W/wt[0])*val[0];

    //     if(dp[ind][W] != -1) return dp[ind][W];

    //     int notTake=solve(wt, val, ind-1, W, dp);
    //     int take=INT_MIN;
    //     if(wt[ind]<=W) take=val[ind]+solve(wt,val, ind, W-wt[ind], dp);
    //     return dp[ind][W]= max(notTake, take);
    // }
    // public:
    // int unboundedKnapsack(vector<int>&wt, vector<int>& val, int n, int W){
    //     vector<vector<int>>dp(n, vector<int>(W+1, -1));
    //     return solve(wt, val, n-1, W, dp);
    // }

    // //Tabulation
    // public:
    // int unboundedKnapsack(vector<int>&wt, vector<int>&val, int n, int W){
    //     vector<vector<int>>dp(n,vector<int>(W+1, 0));
    //     for(int i=wt[0]; i<=W;i++){
    //         dp[0][i] =(i/wt[0])*val[0];
    //     }
    //     for(int ind=1; ind<n; ind++){
    //         for(int j=0; j<=W; j++){
    //             int notTake=dp[ind-1][j];
    //             int take=INT_MIN;
    //             if(wt[ind] <= j) take=val[ind]+dp[ind][j-wt[ind]];
    //             dp[ind][j]=max(notTake, take);
    //         }
    //     }
    //     return dp[n-1][W];
    // }

    //Specific Optimization
    public:
    int unboundedKnapsack(vector<int>&wt, vector<int>&val, int n, int W){
        vector<int>cur(W+1, 0);
        for(int i=wt[0]; i<=W; i++){
            cur[i]=(i/wt[0])*val[0];
        }
        for(int ind=1; ind<n; ind++){
            for(int j=0; j<=W; j++){
                int notTake=cur[j];
                int take=INT_MIN;
                if(wt[ind]<j){
                    take=val[ind]+cur[j-wt[ind]];
                }
                cur[j]=max(notTake, take);
            }
        }
        return cur[W];
    }
};

int main(){
    int n=3;
    vector<int>val={5, 11, 3};
    vector<int>wt={2, 4, 6};
    int W=10;
    Solution obj;
    int ans=obj.unboundedKnapsack(wt, val, n, W);
    cout<<ans;
    return 0;
}