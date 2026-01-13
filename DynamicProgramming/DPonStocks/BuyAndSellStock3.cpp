#include<iostream>
#include<vector>
using namespace std;

class Solution{
    // //Memoization
    // int getAns(vector<int>& arr, int n, int ind, int buy, int cap, vector<vector<vector<int>>>& dp){
    //     if(ind == n || cap==0) return 0;
    //     if(dp[ind][buy][cap] != -1) return dp[ind][buy][cap];
    //     int profit;
    //     if(buy==0){
    //         profit=max(0+getAns(arr, n, ind+1, 0, cap, dp), -arr[ind]+getAns(arr, n, ind+1, 1, cap, dp));
    //     }
    //     if(buy==1){
    //         profit=max(0+ getAns(arr, n, ind+1, 1, cap, dp), arr[ind]+getAns(arr, n, ind+1, 0, cap-1, dp));
    //     }
    //     return dp[ind][buy][cap]=profit;
    // }
    // public:
    // int stockBuySell(vector<int>& arr, int n){
    //     vector<vector<vector<int>>>dp(n+1,vector<vector<int>>(2, vector<int>(3, -1)));
    //     return getAns(arr, n, 0, 0, 2, dp);
    // }

    // //Tabulation
    // public:
    // int stockBuySell(vector<int>& arr, int n){
    //     vector<vector<vector<int>>>dp(n+1, vector<vector<int>>(2, vector<int>(3, 0)));
    //     for(int ind =n-1; ind>=0; ind--){
    //         for(int buy=0; buy<=1; buy++){
    //             for(int  cap=1; cap<=2; cap++){
    //                 if(buy==0){
    //                     dp[ind][buy][cap]=max(0+dp[ind+1][0][cap], -arr[ind]+dp[ind+1][1][cap]);
    //                 }
    //                 if(buy==1){
    //                     dp[ind][buy][cap]=max(0+dp[ind+1][1][cap], arr[ind]+dp[ind+1][0][cap-1]);
    //                 }
    //             }
    //         }
    //     }
    //     return dp[0][0][2];
    // }

    //Space optimization
    public:
    int stockBuySell(vector<int>& arr, int n){
        vector<vector<int>>ahead(2, vector<int>(3, 0));
        vector<vector<int>>cur(2, vector<int>(3, 0));

        for(int ind=n-1; ind>=0; ind--){
            for(int buy=0; buy<=1; buy++){
                for(int cap=1; cap<=2; cap++){
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
        return ahead[0][2];
    }
};

int main(){
    vector<int> arr={4, 2, 7, 1, 11, 5};
    int n=arr.size();
    Solution obj;
    int ans=obj.stockBuySell(arr, n);
    cout<<ans;
    return 0;
}