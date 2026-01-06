#include<iostream>
#include<vector>
using namespace std;

class Solution {
public:
// //Memoization
//     int memoization(int ind, vector<int>&heights, vector<int>&dp, int k){
//         if(ind == 0) return 0;
//         if(dp[ind] != -1) return dp[ind];
//         int mmSteps=INT_MAX;
//         for(int j=1; j<=k; j++){
//             if(ind-j >=0){
//                 int jump = memoization(ind-j, heights, dp, k)+abs(heights[ind] - heights[ind-j]);
//                 mmSteps=min(jump, mmSteps);
//             }
//         }
//         return dp[ind]=mmSteps;
//     }

//     int frogJump(vector<int>& heights, int k) {
//         int n=heights.size();
//         vector<int> dp(n, -1);
//         return memoization(n-1, heights, dp, k);
//     }

//Tabulation
    private:
    int tabulation(int n, vector<int>& height, vector<int>&dp, int k){
        dp[0]=0;
        for(int i=1; i<n; i++){
            int mmSteps = INT_MAX;
            for(int j=1; j<= k; j++){
                if(i-j >=0){
                    int jump=dp[i-j] + abs(height[i]-height[i-j]);
                    mmSteps=min(mmSteps, jump);
                }
            }
            dp[i]=mmSteps;
        }
        return dp[n-1];
    }

    public:
    int frogJump(vector<int>&heights, int k){
        int n=heights.size();
        vector<int>dp(n, -1);
        return tabulation(n, heights, dp, k);
    }
};

int main(){
    vector<int>heights={10, 5, 20, 0, 15};
    int k=2;
    Solution obj;
    int ans= obj.frogJump(heights, k);
    cout<<ans;
    return 0;
}
