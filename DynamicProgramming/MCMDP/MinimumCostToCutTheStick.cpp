#include<iostream>
#include<vector>
#include <algorithm>
using namespace std;

class Solution{
    //Recurssion
    // int findMinimumCost(int i, int j, vector<int>& cuts){
    //     if(i>j) return 0;
    //     int mini=INT_MAX;
    //     for(int ind=i; ind<=j; ind++){
    //         int ans=cuts[j+1]-cuts[i-1]+findMinimumCost(i, ind-1, cuts)+findMinimumCost(ind+1, j, cuts);
    //         mini=min(mini, ans);
    //     }
    //     return mini;
    // }
    // public:
    // int minCost(int n, vector<int>& cuts){
    //     int c=cuts.size();
    //     cuts.push_back(n);
    //     cuts.insert(cuts.begin(), 0);
    //     sort(cuts.begin(), cuts.end());
    //     return findMinimumCost(1, c, cuts);
    // }

    //Memoization
    // private:
    // int findMinimumCost(int i, int j, vector<int>& cuts, vector<vector<int>>& dp){
    //     if(i>j) return 0;
    //     if(dp[i][j]!=-1){
    //         return dp[i][j];
    //     }
    //     int mini=INT_MAX;
    //     for(int ind=i; ind<=j; ind++){
    //         int ans=cuts[j+1]-cuts[i-1]+findMinimumCost(i, ind-1, cuts, dp)+findMinimumCost(ind+1, j, cuts, dp);
    //         mini=min(mini, ans);
    //     }
    //     return dp[i][j]=mini;
    // }

    // public:
    // int minCost(int n, vector<int>& cuts){
    //     int c= cuts.size();
    //     cuts.push_back(n);
    //     cuts.insert(cuts.begin(), 0);
    //     sort(cuts.begin(), cuts.end());
    //     vector<vector<int>>dp(c+1, vector<int>(c+1, -1));
    //     return findMinimumCost(1, c, cuts, dp);
    // }

    //Tabulation
    public:
    int minCost(int n, vector<int>& cuts){
        int c=cuts.size();
        cuts.push_back(n);
        cuts.insert(cuts.begin(), 0);
        sort(cuts.begin(), cuts.end());
        
        vector<vector<int>>dp(c+2, vector<int>(c+2, 0));
        for(int i=c; i>=1; i--){
            for(int j=i; j<=c; j++){
                int mini= INT_MAX;
                for(int ind=i; ind<=j; ind++){
                    int ans=cuts[j+1]-cuts[i-1]+dp[i][ind-1]+dp[ind+1][j];
                    mini=min(mini, ans);
                }
                dp[i][j]=mini;
            }
        }
        return dp[1][c];
    }
};

int main(){
    int n=7;
    vector<int> cuts={1,3,4,5};
    Solution obj;
    int ans=obj.minCost(n, cuts);
    cout<<ans;
    return 0;
}