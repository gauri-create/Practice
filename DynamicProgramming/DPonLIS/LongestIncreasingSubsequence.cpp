#include<iostream>
#include<vector>
using namespace std;

class Solution{
    private:
    int func(int i, int prevInd, vector<int>& arr, vector<vector<int>>& dp){
        if(i==arr.size()-1){
            if(prevInd==-1 || arr[prevInd]<arr[i]) return 1;
            return 0;
        }
        if(dp[i][prevInd+1]  != -1) return dp[i][prevInd+1];
        int notTake=func(i+1, prevInd, arr, dp);
        int take=0;
        if(prevInd==-1){
            take=func(i+1, i, arr, dp)+1;
        }
        else if(arr[i]>arr[prevInd]){
            take=func(i+1, i, arr,dp)+1;
        }
        return dp[i][prevInd+1]=max(take, notTake);
    }
    public:
    int LIS(vector<int>& nums){
        int n=nums.size();
        vector<vector<int>>dp(n, vector<int>(n+1, -1));
        return func(0, -1, nums, dp);
    }
};

int main(){
    vector<int>nums={10, 9, 2, 5, 3, 7, 101, 18};
    Solution obj;
    int ans= obj.LIS(nums);
    cout<<ans;
    return 0;
}