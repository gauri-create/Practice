#include<iostream>
#include<vector>
using namespace std;

class Solution{
    // //Memoization
    // int func(int i, int j, vector<vector<int>>& matrix, vector<vector<int>> &dp){
    //     if(i<0 || j<0 || matrix[i][j]==1) return 0;
    //     else if(i==0 && j==0) return 1;
    //     if(dp[i][j] !=-1) return dp[i][j];
    //     int up=func(i-1, j, matrix, dp);
    //     int left = func(i, j-1, matrix, dp);
    //     return dp[i][j] = up+left;
    // }

    // public:
    // int uniquePathsWithObstacle(vector<vector<int>> & matrix){
    //     int m=matrix.size();
    //     int n=matrix[0].size();
    //     vector<vector<int>> dp(m, vector<int>(n, -1));
    //     return func(m-1, n-1, matrix, dp);
    // }

    //Tabulation
    public:
    int uniquePathsWithObstacle(vector<vector<int>>& matrix){
        int m=matrix.size();
        int n=matrix[0].size();
        vector<vector<int>> dp(m, vector<int>(n, 0));
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                if(matrix[i][j] ==1){
                    dp[i][j]=0;
                    continue;
                }
                if(i==0 && j==0){
                    dp[i][j]=1;
                    continue;
                }
                int up=0;
                int left=0;

                if(i>0) up=dp[i-1][j];
                if(j>0) left=dp[i][j-1];
                dp[i][j]=up+left;
            }
        }
        return dp[m-1][n-1];
    }
};

int main(){
    vector<vector<int>>matrix={
        {0, 0, 0},
        {0, 1, 0},
        {0, 0, 0}
    }; 
    Solution obj;
    int ans=obj.uniquePathsWithObstacle(matrix);
    cout<<ans;
    return 0;
}