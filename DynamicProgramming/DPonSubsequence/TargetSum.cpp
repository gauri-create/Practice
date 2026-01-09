#include<iostream>
#include<vector>
#include<numeric>
using namespace std;

class Solution{
    //Memoization
    // private:
    // int solve(vector<vector<int>>& dp, int n, int target, vector<int>& nums){

    //     if(n==0){
    //         if(target==0 && nums[0]==0) return 2;
    //         if(target==0 || target==nums[0]) return 1;
    //         return 0;
    //     }

    //     if(dp[n][target] != -1) return dp[n][target];
    //     int notPick=solve(dp, n-1, target, nums);
    //     int pick=0;
    //     if(nums[n] <= target) {
    //         pick=solve(dp, n-1, target-nums[n], nums);
    //     }
    //     return dp[n][target]=pick+notPick;
    // }

    // public:
    // int targetSum(int n, int target, vector<int>& nums){
    //     int totalSum=accumulate(nums.begin(), nums.end(), 0);
    //     if((totalSum-target) <0 || (totalSum-target) %2 != 0) return 0;
    //     int subsetSum=(totalSum-target)/2;
    //     vector<vector<int>>dp(n, vector<int>(subsetSum+1, -1));
    //     return solve(dp, n-1, subsetSum, nums);
    // }

    //Tabulation
    // public:
    int targetSum(int n, int target, vector<int>&nums){
        int totalSum=accumulate(nums.begin(), nums.end(), 0);
        if((totalSum+target)%2 != 0 || abs(target)>totalSum) return 0;
        int newTarget=(totalSum+target)/2;
        vector<vector<int>>dp(n+1, vector<int>(newTarget+1, 0));
        for(int i=0; i<=n; i++)dp[i][0]=1;
        for(int i=1; i<=n; i++){
            for(int j=0; j<=newTarget; j++){
                dp[i][j]=dp[i-1][j];
                if(nums[i-1]<=j){
                    dp[i][j]+=dp[i-1][j-nums[i-1]];
                }
            }
        }
        return dp[n][newTarget];
    }
 
    //Space Optimization
    public:
    int targetSum(int n, int target, vector<int>& nums){
        int total=accumulate(nums.begin(), nums.end(), 0);
        if((total+target) %2!=0 || abs(target)>total) return 0;
        int newTarget=(total+target)/2;
        vector<int>dp(newTarget+1, 0);
        dp[0]=1;
        for(int num:nums){
            for(int j=newTarget; j>=num; j--){
                dp[j] += dp[j-num];
            }
        }
        return dp[newTarget];
    }
};

int main(){
    vector<int>nums={1,2,7,1,5};
    int target=4;
    int n=5;
    Solution obj;
    int ans=obj.targetSum(n, target, nums);
    cout<<ans;
    return 0;
}