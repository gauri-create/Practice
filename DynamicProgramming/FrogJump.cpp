#include<iostream>
#include<vector>
using namespace std;

class Solution{
    private:
    //Memoization
    // int f(int ind, vector<int>& heights, vector<int>&dp){
    //     if(ind == 0) return 0;
    //     if(dp[ind] != -1) return dp[ind];

    //     int left = f(ind-1, heights)+abs(heights[ind] - heights[ind-1]);
    //     int right = INT_MAX;
    //     if(ind >1) right = f(ind-2, heights, dp)+abs(heights[ind]-heights[ind-2]);
    //     return dp[ind]=min(left, right);
    // }
    // public:
    // int frogJump(vector<int>& heights){
    //     int n= heights.size();
    //     vector<int>dp(n+1, -1);
    //     return f(n-1,heights, dp);
    // }

    //Tabulation
    // public:
    // int frogJump(vector<int>& heights){
    //     int n=heights.size();
    //     vector<int >dp(n,0);
    //     dp[0] = 0;
    //     for(int i=1; i<n; i++){
    //         int fs = dp[i-1] + abs(heights[i] - heights[i-1]);
    //         int ss = INT_MAX;
    //         if(i>1) ss=dp[i-2] + abs(heights[i]- heights[i-2]);
    //         dp[i]=min(fs, ss);
    //     }
    //     return dp[n-1];
    // }

    //space optimization
    public:
    int frogJump(vector<int>& heights){
        int n=heights.size();
        int prev=0;
        int prev2=0;
        for(int i=1; i<n; i++){
            int fs=prev+abs(heights[i]-heights[i-1]);
            int ss=INT_MAX;
            if(i>1) ss=prev2+abs(heights[i] - heights[i-2]);
            int curi = min(fs, ss);
            prev2=prev;
            prev=curi;
        }
        return prev;
    }

};

int main(){
    vector<int>heights={2,1,3,5,4};
    Solution obj;
    int ans=obj.frogJump(heights);
    cout<<ans;
    return 0;
}