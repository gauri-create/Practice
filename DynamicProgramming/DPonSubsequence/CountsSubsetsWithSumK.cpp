#include<iostream>
#include<vector>
using namespace std;

class Solution{
    // private:
    // int solve(int index, int target, vector<int>& nums, vector<vector<int>>& dp){
    //     if(target == 0) return 1;
    //     if(index == 0) return (nums[0] == target ? 1: 0);
    //     if(dp[index][target] != -1) return dp[index][target];
    //     int notTaken = solve(index-1, target, nums, dp);

    //     int take=0;
    //     if(nums[index] <= target){
    //         take = solve(index-1, target-nums[index], nums, dp);
    //     }
    //     return dp[index][target] = take+notTaken;
    // }
    // public:
    // int perfectSum(vector<int>& arr, int k){
    //     vector<vector<int>> dp(arr.size(), vector<int>(k+1, -1));
    //     return solve(arr.size()-1, k, arr, dp);
    // }

    // //Tabulation
    // public:
    // int perfectSum(vector<int>& arr, int k){
    //     int n=arr.size();
    //     vector<vector<int>>dp(n, vector<int>(k+1, 0));
    //     dp[0][0]=1;
    //     if(arr[0] <= k) dp[0][arr[0]]=1;
    //     for(int i=1; i<n; i++){
    //         for(int target=0; target<=k; target++){
    //             int notTake=dp[i-1][target];
    //             int take=0;
    //             if(arr[i]<=target) take=dp[i-1][target-arr[i]];
    //             dp[i][target]=notTake+take;
    //         }
    //     }     
    //     return dp[n-1][k];
    // }

    //Space Optimization
    public:
    int perfectSum(vector<int>& arr, int k){
        vector<int> dp(k+1, 0);
        dp[0]=1;
        if(arr[0] <=k) dp[arr[0]] += 1;
        for(int i=1; i<arr.size(); i++){
            vector<int>curr(k+1, 0);
            curr[0]=1;
            for(int t=0; t<=k; t++){
                int notTake = dp[t];
                int take=0; 
                if(arr[i] <=t){
                    take=dp[t-arr[i]];
                }
                curr[t]=take+notTake;
            }
            dp = curr;
        }
        return dp[k];
    }
};

int main(){
    int k=10;
    vector<int>arr={2, 3, 5, 16,8, 10};
    Solution obj;
    int ans =obj.perfectSum(arr, k);
    cout<<ans;
    return 0;
}