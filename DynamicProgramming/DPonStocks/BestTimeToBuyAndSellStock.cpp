#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution{
    public:
    // //Brute 
    // int stockBuySell(vector<int>& prices, int n){
    //     int maxProfit = 0;
    //     for(int i=0; i<n; i++){
    //         for(int j=i+1; j<n; j++){
    //             int profit=prices[j]-prices[i];
    //             maxProfit=max(maxProfit, profit);
    //         }
    //     }
    //     return maxProfit;
    // }

    //Optimal
    int stockBuySell(vector<int>& prices, int n){
        int minPrice=INT_MAX;
        int maxProfit=0;
        for(int i=0; i<n; i++){
            if(prices[i]<minPrice){
                minPrice=prices[i];
            }
            int profit = prices[i]-minPrice;
            if(profit > maxProfit){
                maxProfit = profit;
            }
        }
        return maxProfit;
    }
};

int main(){
    vector<int>arr={10, 7, 5, 8, 11, 9};
    int n=6;
    Solution obj;
    int ans=obj.stockBuySell(arr, n);
    cout<<ans;
    return 0;
}