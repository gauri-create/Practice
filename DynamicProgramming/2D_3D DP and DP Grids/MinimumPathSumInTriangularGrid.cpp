#include<iostream>
#include<vector>
using namespace std;

class Solution{
    // //Memoization
    // int solve(int i, int j, vector<vector<int>>&triangle, int n, vector<vector<int>> & dp){
    //     if(dp[i][j] != -1) return dp[i][j];
    //     if(i==n-1) return triangle[i][j];

    //     int down = triangle[i][j] + solve(i+1, j, triangle, n, dp);
    //     int diag=triangle[i][j]+solve(i+1, j+1, triangle, n, dp);

    //     return dp[i][j] = min(down, diag);
    // }
    // public:
    // int minimumPathSum(vector<vector<int>> &triangle){
    //     int n=triangle.size();
    //     vector<vector<int>>dp(n, vector<int>(n, -1));
    //     return solve(0, 0, triangle, n, dp);
    // }

    // //Tabulation
    // public:
    // int minimumPathSum(vector<vector<int>>&triangle){
    //     int n= triangle.size();
    //     vector<vector<int>>dp(n, vector<int>(n, 0));
    //     for(int j=0; j<n; j++){
    //         dp[n-1][j]=triangle[n-1][j];
    //     }

    //     for(int i=n-2;i>=0; i--){
    //         for(int j=i; j>=0; j--){
    //             int down=triangle[i][j]+dp[i+1][j];
    //             int diag=triangle[i][j]+dp[i+1][j+1];
    //             dp[i][j]=min(down, diag);
    //         }
    //     }
    //     return dp[0][0];
    // }

    //Space Optimization
    public:
    int minimumPathSum(vector<vector<int>>& triangle){
        int n=triangle.size();
        vector<int>front(n, 0);
        vector<int>cur(n, 0);
        for(int j=0; j<n; j++){
            front[j] = triangle[n-1][j];
        }

        for(int i=n-2; i>=0; i--){
            for(int j=i;j>=0; j--){
                int down=triangle[i][j]+front[j];
                int diagonal = triangle[i][j]+front[j+1];
                cur[j]=min(down, diagonal);
            }
            front=cur;
        }
        return front[0];
    }

};

int main(){
    vector<vector<int>> triangle={{1}, {1,2}, {1, 2, 4}};
    Solution obj;
    int ans= obj.minimumPathSum(triangle);
    cout<<ans;
    return 0;
}