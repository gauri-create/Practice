#include<iostream>
#include<vector>
using namespace std;

class Solution{
    // //Memoization
    // bool solve( int n, int target, vector<int> arr, vector<vector<int>>&dp){
    //     if(target==0) return true;
    //     if(n==0) return arr[0]==target;
    //     if(dp[n][target] != -1) return dp[n][target];
    //     bool notTaken=solve(n-1, target, arr, dp);

    //     bool taken=false;
    //     if(arr[n]<=target)
    //     taken=solve(n-1, target-arr[n], arr, dp);

    //     return dp[n][target] = notTaken||taken;
    // }
    // public:
    // bool equalPartition(int n, vector<int> arr){
    //     int arrSum = 0;
    //     for(int i=0; i<n; i++) arrSum+=arr[i];
    //     if(arrSum%2 != 0) return false;

    //     int target=arrSum/2;
    //     vector<vector<int>> dp(n, vector<int>(target+1, -1)) ;
    //     return solve(n-1, target, arr, dp);
    // }

    // //Tabulation
    // public:
    // bool equalPartition(int n, vector<int> arr){
    //     int sum=0;
    //     for(int i=0; i<n; i++) sum+=arr[i];
    //     if(sum%2 != 0) return false;
    //     int target = sum/2;
    //     vector<vector<bool>>dp(n, vector<bool>(target+1, false));
        
    //     for(int i=0; i<n; i++) dp[i][0]=true;
    //     if(arr[0] <= target) dp[0][arr[0]] = true;

    //     for(int index=1; index<n; index++){
    //         for(int k=1; k<= target; k++){
    //             bool notTaken=dp[index-1][target];
    //             bool taken = false;
    //             if(arr[index] <= target){
    //                 taken=dp[index-1][target-arr[index]];
    //             }
    //             dp[index][target] = notTaken|| taken;
    //         }
    //     }
    //     return dp[n-1][target];
    // }

    //Space Optimization
    public:
    bool equalPartition(int n, vector<int> arr){
        int sum=0;
        for(int i=0; i<n; i++) sum+=arr[i];
        if(sum%2 != 0) return false;
        int target = sum/2;
        vector<bool>prev(target+1, false);
        prev[0]=true;
        
        if(arr[0] <= target) prev[arr[0]] = true;

        for(int index=1; index<n; index++){
            vector<bool>curr(target+1, false);
            curr[0]= true;
            for(int k=1; k<= target; k++){
                bool notTaken=prev[target];

                bool taken = false;
                if(arr[index] <= target){
                    taken=prev[target-arr[index]];
                }
                curr[target] = notTaken|| taken;
            }
            prev=curr;
        }
        return prev[target];
    }
};
int main(){
    vector<int> arr={1, 10, 21, 19};
    int n=4;
    Solution obj;
    bool ans = obj.equalPartition(n,arr);
    cout<<(ans?"True": "False");
    return 0;
}