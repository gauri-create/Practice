#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

class Solution
{
    // //Memoization
    // private:
    // int getAns(vector<int>& arr, int ind, int buy, int n, vector<vector<int>>& dp){
    //     if(ind==n)return 0;
    //     if(dp[ind][buy]!=-1) return dp[ind][buy];
    //     int profit=0;
    //     if (buy == 0) {
    //         profit=max((0+getAns(arr, ind+1,0, n, dp)), (-arr[ind]+getAns(arr, ind+1, 1, n, dp)));
    //     }
    //     if(buy==1){
    //         profit=max((0+getAns(arr, ind+1, 1, n, dp)),( arr[ind]+getAns(arr, ind+1, 0, n, dp)));
    //     }
    //     return dp[ind][buy]=profit;
    // }

    // public:
    // int stockBuySell(vector<int>&arr, int n){
    //     vector<vector<int>>dp(n, vector<int>(2, -1));
    //     if(n==0)return 0;
    //     int ans=getAns(arr, 0, 0, n, dp);
    //     return ans;
    // }
// //Tabulation
// public:
//     int stockBuySell(vector<int> &arr, int n)
//     {
//         vector<vector<int>> dp(n + 1, vector<int>(2, -1));
//         dp[n][0] = dp[n][1] = 0;
//         int profit = 0;
//         for (int ind = n - 1; ind >= 0; ind--)
//         {
//             for (int buy = 0; buy <= 1; buy++)
//             {
//                 if (buy == 0)
//                 {
//                     profit=max(0+dp[ind+1][0], -arr[ind]+dp[ind+1][1]);
//                 }
//                 if (buy == 1)
//                 {
//                     profit = max(0+dp[ind + 1][1], arr[ind] + dp[ind + 1][0]);
//                 }
//                 dp[ind][buy] = profit;
//             }
//         }
//         return dp[0][0];
//     }

//Space Optimization
public:
    int stockBuySell(vector<int>& arr, int n){
        vector<int>ahead(2, 0);
        vector<int>cur(2, 0);
        ahead[0]=ahead[1]=0;
        int profit=0;
        for(int ind=n-1; ind>=0; ind--){
            for(int buy=0; buy<=1; buy++){
                if(buy==0){
                    profit=max(0+ahead[0], -arr[ind]+ahead[1]);
                }
                if(buy==1){
                    profit=max(0+ahead[1], arr[ind]+ahead[0]);
                }
                cur[buy]=profit;
            }
            ahead=cur;
        }
        return cur[0];
   }
};

int main()
{
    vector<int> arr = {9, 2, 6, 4, 7, 3};
    int n = arr.size();
    Solution obj;
    int ans = obj.stockBuySell(arr, n);
    cout << ans;
    return 0;
}