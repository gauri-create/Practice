#include<iostream>
#include<vector>
using namespace std;

class Solution{
    // //Memoization
    // private:
    // int helper(const vector<int>&arr, int k, int start, vector<int>&memo){
    //     int n=(int)arr.size();
    //     if(start==n) return 0;
    //     if(memo[start]!=-1)return memo[start];
    //     int maxSum=0;
    //     int maxElem=0;
    //     for(int length=1; length<=k && start+length<=n; length++){
    //         maxElem=max(maxElem,arr[start+length-1]);
    //         int currentSum=maxElem*length+helper(arr, k, start+length, memo);
    //         maxSum=max(maxSum, currentSum);
    //     }
    //     return memo[start]=maxSum;
    // }
    // public:
    // int maxSumAfterPartitioning(vector<int>& arr, int k){
    //     int n=(int) arr.size();
    //     vector<int>memo(n, -1);
    //     return helper(arr, k, 0, memo);
    // }

    //Tabulation
    public:
    int maxSumAfterPartitioning(vector<int>& arr, int k){
        int n=(int)arr.size();
        vector<int>dp(n+1, 0);
        for(int i=n-1; i>=0; i--){
            int maxElem=0; 
            int maxSum=0;
            for(int length=1; length<=k && i+length<=n; length++){
                maxElem=max(maxElem, arr[i+length-1]);
                int currentSum=maxElem*length+dp[i+length];
                maxSum=max(maxSum, currentSum);
            }
            dp[i]=maxSum;
        }
        return dp[0];
    }
};

int main(){
    vector<int> arr={1, 15, 7, 9, 2, 5, 10};
    int k=3;
    Solution obj;
    int ans=obj.maxSumAfterPartitioning(arr, k);
    cout<<ans;
    return 0;
}