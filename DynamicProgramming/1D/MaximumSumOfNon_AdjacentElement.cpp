#include<iostream>
#include<vector>
using namespace std;

class Solution{
    // //Memoization
    // int f(int ind, vector<int> &nums, vector<int> &dp){
    //     if(ind == 0) return nums[ind];
    //     if(ind<0) return 0;

    //     if(dp[ind] != -1) return dp[ind];

    //     int pick = nums[ind] + f(ind -2, nums, dp);
    //     int notPick = 0+f(ind -1, nums, dp);

    //     return dp[ind]=max(pick, notPick);
    // }
    // public:
    // int nonAdjacent(vector<int>& nums){
    //     int n=nums.size();
    //     vector<int> dp(n, -1);
    //     return f(n-1, nums, dp);
    // }

    //Tabulation
    // public:
    // int nonAdjacent(vector<int> nums){
    //     int n=nums.size();
    //     if(n==1) return nums[0];
    //     vector<int>dp(n);
    //     dp[0] = nums[0];
    //     dp[1]=max(nums[0], nums[1]);
    //     for(int i=2; i<n; i++){
    //         dp[i]=max(nums[i]+dp[i-2], dp[i-1]);
    //     }
    //     return dp[n-1];
    // }

    //Space Optimization
    public:
    int nonAdjacent(vector<int> & nums){
        int n=nums.size();
        int prev=nums[0];
        int prev2=0;
        for(int i=1; i<n; i++){
            int take=nums[i];
            if(i>1) take+=prev2;
            int notTake=0+prev;
            int curi=max(take, notTake);
            prev2=prev;
            prev=curi;
        }
        return prev;
    }
};

int main(){
    vector<int>nums={1,2,4};
    Solution obj;
    int ans=obj.nonAdjacent(nums);
    cout<<ans;
    return 0;
}