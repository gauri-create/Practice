#include<iostream>
#include<vector>
using namespace std;

class Solution{
    // //Memoization
    // private:
    // int getAns(vector<int>& arr, int n, int ind, int buy, int cap, vector<vector<vector<int>>>& dp){
    //     if(ind==n || cap==0) return 0;
    //     if(dp[ind][buy][cap] != -1) return dp[ind][buy][cap];
    //     int profit;
    //     if(buy==0){
    //         profit=max(0+getAns(arr, n, ind+1, 0, cap, dp), -arr[ind]+getAns(arr, n, ind+1, 1, cap, dp));
    //     }
    //     if(buy == 1){
    //         profit=max(0+getAns(arr, n, ind+1, 1, cap, dp), arr[ind]+getAns(arr, n, ind+1, 0, cap-1, dp));
    //     }
    //     return dp[ind][buy][cap]=profit;
    // }

    // public:
    // int stockBuySell(vector<int>& arr, int n, int k){
    //     vector<vector<vector<int>>>dp(n,
    //                     vector<vector<int>>(2, vector<int>(k+1, -1)));
    //     return getAns(arr, n, 0, 0, k, dp);
    // }

    // //Tabulation
    // public:
    // int stockBuySell(vector<int>& arr, int n, int k){
    //     vector<vector<vector<int>>>dp(n+1, vector<vector<int>>(2, vector<int>(k+1, 0)));
    //     for(int ind=n-1; ind>=0; ind--){
    //         for(int buy=0; buy<=1; buy++){
    //             for(int cap=1; cap<=k; cap++){
    //                 if(buy==0){
    //                     dp[ind][buy][cap]=max(0+dp[ind+1][0][cap], -arr[ind]+dp[ind+1][1][cap]);
    //                 }
    //                 if(buy==1){
    //                     dp[ind][buy][cap]=max(0+dp[ind+1][1][cap], arr[ind]+dp[ind+1][0][cap-1]);
    //                 }
    //             }

    //         }
    //     }
    //     return dp[0][0][k];
    // }

    public:
    int stockBuySell(vector<int>&arr, int n, int k){
        vector<vector<int>>ahead(2, vector<int>(k+1, 0));
        vector<vector<int>>cur(2, vector<int>(k+1, 0));

        for(int ind=n-1; ind>=0; ind--){
            for(int buy=0; buy<=1; buy++){
                for(int cap=1; cap<=k; cap++){
                    if(buy == 0){
                        cur[buy][cap]=max(0+ahead[0][cap], -arr[ind]+ahead[1][cap]);
                    }
                    if(buy==1){
                        cur[buy][cap]=max(0+ahead[1][cap], arr[ind]+ahead[0][cap-1]);
                    }
                }
            }
            ahead=cur;
        }
        return ahead[0][k];
    }
};

int main(){
    vector<int> arr={3, 2, 6, 5, 0, 3};
    int n=arr.size();
    int k=2;
    Solution obj;
    int ans=obj.stockBuySell(arr, n, k);
    cout<<ans;
    return 0;
}
