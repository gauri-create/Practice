#include<iostream>
#include<vector>
using namespace std;

class Solution{
    // //Memoization
    // int getAns(const vector<int>&arr, int ind, int buy, int n, vector<vector<int>> &dp){
    //     if(ind >=n) return 0;
    //     if(dp[ind][buy] != -1) return dp[ind][buy];
    //     int profit;
    //     if(buy==0){
    //         profit=max(getAns(arr, ind+1, 0, n, dp), -arr[ind]+getAns(arr, ind+1, 1, n, dp));
    //     }
    //     if(buy==1){
    //         profit=max(getAns(arr, ind+1, 1, n, dp), arr[ind]+getAns(arr, ind+2, 0, n, dp));
    //     }
    //     return dp[ind][buy]=profit;
    // }
    // public:
    // int maxProfit(const vector<int>& prices){
    //     int n=prices.size();
    //     vector<vector<int>> dp(n, vector<int>(2, -1));
    //     int ans=getAns(prices, 0, 0, n, dp);
    //     return ans;
    // }

    // //Tabulation
    // public:
    // int maxProfit(vector<int>& arr){
    //     int n=arr.size();
    //     vector<vector<int>>dp(n+2, vector<int>(2, 0));
    //     for(int ind=n-1; ind>=0; ind--){
    //         for(int buy=0; buy<=1; buy++){
    //             int profit;
    //             if(buy==0){
    //                 profit=max(0+dp[ind+1][0], -arr[ind]+dp[ind+1][1]);
    //             }
    //             if(buy==1){
    //                 profit=max(0+dp[ind+1][1], arr[ind]+dp[ind+2][0]);
    //             }
    //             dp[ind][buy]=profit;
    //         }
    //     }
    //     return dp[0][0];
    // }

    //Space Optimization
    public:
    int maxProfit(vector<int>& arr){
        int n=arr.size();
        vector<int>cur(2, 0);
        vector<int>front1(2, 0);
        vector<int>front2(2, 0);

        for(int ind=n-1; ind>=0; ind--){
            for(int buy=0; buy<=1; buy++){
                int profit;
                if(buy==0){
                    profit=max(0+front1[0], -arr[ind]+front1[1]);
                }
                if(buy==1){
                    profit=max(0+front1[1], arr[ind]+front2[0]);
                }
                cur[buy]=profit;
            }
            front2=front1;
            front1=cur;
        }
        return cur[0];
    }
};

int main(){
    vector<int>prices={1, 2, 3, 0, 2};
    Solution obj;
    int ans=obj.maxProfit(prices);
    cout<<ans;
    return 0;
}
