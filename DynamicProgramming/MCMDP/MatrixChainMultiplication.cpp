#include<iostream>
#include<vector>
using namespace std;

class Solution{
    // // recursion
    // int matrixChainOrder(vector<int>& arr, int i, int j){
    //     if(i==j) return 0;
    //     int minCost = INT_MAX;
    //     for(int k=i; k<j; k++) {
    //         int cost1=matrixChainOrder(arr, i, k);
    //         int cost2=matrixChainOrder(arr, k+1, j);
    //         int costMultiple=arr[i-1]*arr[k]*arr[j];
    //         int total = cost1+cost2+costMultiple;
    //         minCost=min(minCost, total);
    //     }       
    //     return minCost;
    // }
    // public:
    // int matrixMultiplication(vector<int>& nums){
    //     int n=nums.size();
    //     return matrixChainOrder(nums, 1, n-1);
    // }

    //Memoization
    private:
    int solve(vector<int>& arr, int i, int j, vector<vector<int>>& dp){
        if(i==j) return 0;
        if(dp[i][j]!= -1) return dp[i][j];
        int minCost=INT_MAX;
        for(int k=i; k<j; k++){
            int cost1=solve(arr, i, k, dp);
            int cost2=solve(arr, k+1, j, dp);
            int costMultiply = arr[i-1]*arr[k]*arr[j];

            int total=cost1+cost2+costMultiply;

            minCost=min(minCost, total);
        }
        dp[i][j]=minCost;
        return dp[i][j];
    }
    public:
    int matrixMultiplication(vector<int>& arr){
        int n=arr.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return solve(arr, 1, n-1, dp);
    }
};

int main(){
    vector<int>nums={10, 15, 20, 25};
    int n=nums.size();
    Solution obj;
    int ans= obj.matrixMultiplication(nums);
    cout<<ans;
    return 0;
}