#include<iostream>
#include<vector>
using namespace std;

class Solution{
    // private:
    // int getAns(vector<int>& arr, int ind, int buy, int n, int fee, vector<vector<int>>& dp){
    //     if(ind==n) return 0;
    //     if(dp[ind][buy] != -1) return dp[ind][buy];
    //     int profit;
    //     if (buy == 0){
    //         profit=max(0+getAns(arr, ind+1, 0, n, fee, dp), -arr[ind]+getAns(arr, ind+1, 1, n, fee, dp));
    //     }
    //     if(buy == 1){
    //         profit=max(0+getAns(arr, ind+1, 1, n, fee, dp), arr[ind]-fee+getAns(arr, ind+1, 0, n, fee, dp));
    //     }
    //     return dp[ind][buy]=profit;
    // }
    // public:
    // int stockBuySell(vector<int>& arr, int n, int fee){
    //     vector<vector<int>> dp(n, vector<int>(2, -1));
    //     if(n==0) return 0;
    //     int ans=getAns(arr, 0, 0, n, fee, dp);
    //     return ans;
    // }

    // //Tabulation
    // public:
    // int stockBuySell(vector<int>& arr, int n, int fee){
    //     if(n==0) return 0;
    //     vector<vector<int>>dp(n+1, vector<int>(2, 0));
    //     for(int ind=n-1; ind>=0; ind--){
    //         for(int buy=0; buy<=1; buy++){
    //             int profit;
    //             if(buy==0){
    //                 profit=max(0+dp[ind+1][0], -arr[ind]+dp[ind+1][1]);
    //             }
    //             if(buy == 1){
    //                 profit=max(0+dp[ind+1][1], arr[ind]-fee+dp[ind+1][0]);
    //             }
    //             dp[ind][buy]=profit;
    //         }
    //     }
    //     return dp[0][0];
    // }

    //Space optimization
    public:
    int stockBuySell(vector<int>& arr, int n, int fee){
        if(n==0) return 0;
        vector<int>ahead(2, 0);
        vector<int>cur(2, 0);

        ahead[0]=ahead[1]=0;
        int profit;
        for(int ind= n-1; ind>=0; ind--){
            for(int buy=0; buy<=1; buy++){
                if(buy==0){
                    profit=max(0+ahead[0],-arr[ind]+ahead[1]);
                }
                if(buy==1){
                    profit=max(0+ahead[1], arr[ind]-fee+ahead[0]);
                }
                cur[buy]=profit;
            }
            ahead=cur;
        }
        return cur[0];
    }
};

int main(){
    vector<int> arr={1,3,4,0,2};
    int n=arr.size();
    int fee=1;
    Solution obj;
    int ans=obj.stockBuySell(arr, n, fee);
    cout<<ans;
    return 0;
}
