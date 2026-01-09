#include<iostream>
#include<vector>
using namespace std;

class Solution{
    //Memoization
    // private:
    // int solve(vector<int>coins, int n, int amount, vector<vector<int>>&dp){
    //     if(n==0) return (amount%coins[0]==0);
    //     if(dp[n][amount] != -1) return dp[n][amount];
    //     int notTake=solve(coins, n-1, amount,dp);
    //     int take=0;
    //     if(coins[n]<=amount){
    //         take=solve(coins,n, amount-coins[n], dp);
    //     }
    //     return dp[n][amount]=take+notTake;
    // }
    // public:
    // int count(vector<int>&coins, int n, int amount){
    //     vector<vector<int>> dp(n, vector<int>(amount+1, -1));
    //     return solve(coins, n-1, amount, dp);
    // }

    // //Tabulation
    // public:
    int count(vector<int>& coins, int n, int amount){
        vector<vector<int>>dp(n, vector<int>(amount+1, 0));
        for(int i=0; i<=amount; i++){
            if(i % coins[0]==0) dp[0][i]=1;
        }
        for(int ind=1; ind<n; ind++){
            for(int target=0; target<=amount; target++){
                int notTake=dp[ind-1][target];
                int take=0;
                if(coins[ind] <=target) 
                    take=dp[ind][target-coins[ind]];
                dp[ind][target]=notTake+take;
            }
        }
        return dp[n-1][amount]; 
    }

    //Space Optimization
    public:
    int count(vector<int>&coins, int n, int amount){
        vector<int>prev(amount+1, 0);
        for(int i=0; i<=amount; i++){
            if(i% coins[0] == 0) prev[i]=1;
         }
         for(int ind=1; ind<n; ind++){
            vector<int>curr(amount+1, 0);
            for(int target=0; target<=amount; target++){
                int notTake=prev[target];
                int take=0;
                if(coins[ind]<=target) 
                    take=curr[target-coins[ind]];
                curr[target]=notTake+take;
            }
            prev=curr;
        }
        return prev[amount];
    }
};

int main(){
    int n=3;
    vector<int>coins={2, 4, 10};
    int amount=10;
    Solution obj;
    int ans = obj.count(coins, n ,amount);
    cout<<ans;
    return 0;
}