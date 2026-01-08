#include<iostream>
#include<vector>
using namespace std;

class Solution{
    // //memoization
    // private:
    // bool solve(vector<vector<int>> &dp, int n, int target, vector<int>&arr){
    //     if(target == 0) return true;

    //     if(n==0) return arr[0]==target;

    //     if(dp[n][target] != -1) return dp[n][target];

    //     bool notTaken= solve(dp, n-1, target, arr);

    //     bool taken=false;
    //     if(arr[n] <= target){
    //         taken = solve(dp, n-1, target-arr[n], arr);
    //     }

    //     return dp[n][target] = notTaken || taken;
    // }
    // public:
    // bool isSubsetSum(vector<int>arr, int target){
    //     int n=arr.size();
    //     if(n==0) return false;
    //     vector<vector<int>>dp(n,vector<int>(target+1, -1));
    //     return solve(dp,n-1, target, arr);
    // }

    // //Tabulation
    // public:
    // bool isSubsetSum(vector<int>arr, int target){
    //     int n=arr.size();
    //     if(n==0 && target!=0) return false;
    //     vector<vector<bool>>dp(n, vector<bool>(target+1, false));
        
    //     for(int i=0; i<n; i++) dp[i][0]=true;

    //     if(arr[0] <= target) dp[0][arr[0]] =true;

    //     for(int ind=1; ind<n; ind++){
    //         for(int k=1; k<=target; k++){
    //             bool notTaken=dp[ind-1][target];

    //             bool taken=false;
    //             if(arr[ind]<=k){
    //                 taken=dp[ind-1][k-arr[ind]];
    //             }
    //             dp[ind][k] = notTaken || taken;
    //         }
    //     }
    //     return dp[n-1][target];
    // }

    //Space Optimization
    public:
    bool isSubsetSum(vector<int>arr, int target){
        int n=arr.size();
        if(n==0 && target!=0) return false;
        vector<bool> prev(target+1, false);
        prev[0]=true;

        if(arr[0]<=target){
            prev[arr[0]]=true;
        }

        for(int ind=1; ind<n; ind++){
            vector<bool>cur(target+1, false);
            cur[0]=true;
            for(int k=1; k<=target; k++){
                bool notTaken=prev[target];

                bool taken=false;
                if(arr[ind]<=k){
                    taken=prev[k-arr[ind]];
                }
                cur[k] = notTaken || taken;
            }
            prev=cur;
        }
        return prev[target];
    }
};

int main(){
    int target=6;
    vector<int>arr={ 1, 2, 3, 5};
    Solution obj;
    bool ans=obj.isSubsetSum(arr, target);
    cout<<(ans?"True":"False");
    return 0;
}