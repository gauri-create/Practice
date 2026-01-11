#include <iostream>
#include <vector>
using namespace std;

class Solution
{
//     //Memoization
// public:
//     int rodCutting(vector<int> price, int n)
//     {
//         vector<vector<int>> dp(n, vector<int>(n + 1, 0));
//         for (int length = 0; length <= n; length++)
//         {
//             dp[0][length]=length*price[0];
//         }
//         for(int i=1; i<n;i++){
//             for(int length=0; length<=n; length++){
//                 int notTake=dp[i-1][length];
//                 int take=INT_MIN;
//                 int rodLength=i+1;

//                 if(rodLength<=length){
//                     take=price[i]+dp[i][length-rodLength];
//                 }
//                 dp[i][length]=max(take, notTake);
//             }
//         }
//         return dp[n-1][n];
//     }

//Tabulation
// public:
//     int rodCutting(vector<int>& price, int n){
//         vector<vector<int>> dp(n, vector<int>(n+1, 0));

//         for(int length = 0; length<=n; length++){
//             dp[0][length]=price[0]*length;
//         }

//         for(int ind=1; ind<n; ind++){
//             for(int length=1; length<=n; length++){
//                 int notTake=0+dp[ind-1][length];
//                 int take=INT_MIN;
//                 int rodLength=ind+1;
//                 if(rodLength<=length){
//                     take=price[ind]+dp[ind][length-rodLength];
//                 }
//                 dp[ind][length]=max(notTake, take);
//             }
//         }
//         return dp[n-1][n];
//     }

//Space Optimization
public:
int rodCutting(vector<int>& price, int n){
    vector<int> prev(n+1, 0), curr(n+1, 0);
    for(int length=0; length<=n; length++){
        prev[length]=price[0]*length;
    }
    for(int ind=1; ind<n; ind++){
        for(int length=1; length<=n; length++){
            int notTake=0+prev[length];
            int take=INT_MIN;
            int rodLength = ind+1;

            if(rodLength<=length){
                take=price[ind]+curr[length-rodLength];
            }
            curr[length]=max(notTake,take);
        }
        prev=curr;
    }
    return prev[n];
}
};

int main()
{
    vector<int> price = {1, 6, 8, 9, 10, 19, 7, 20};
    int N = 8;
    Solution obj;
    int ans = obj.rodCutting(price, N);
    cout << ans;
    return 0;
}