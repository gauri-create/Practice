#include <iostream>
#include <vector>
#include <algorithm>
#include <climits>
using namespace std;

class Solution
{
    // //Memoization
    // int solve(int i, int j1, int j2, int n, int m, vector<vector<int>>&grid, vector<vector<vector<int>>>&dp){
    //     if(j1<0 || j1>=m || j2<0 || j2>=m){
    //         return -1e9;
    //     }

    //     if(i==n-1){
    //         if(j1 == j2) return grid[i][j1];
    //         else return grid[i][j1]+grid[i][j2];
    //     }

    //     if(dp[i][j1][j2] != -1) return dp[i][j1][j2];
    //     int maxi = -1e9;
    //     int curr = (j1==j2)? grid[i][j1]: grid[i][j1]+grid[i][j2];

    //     for(int dj1 = -1; dj1<=1; dj1++){
    //         for(int dj2 = -1; dj2<=1; dj2++){
    //             int ans = curr+solve(i+1, j1+dj1, j2+dj2, n, m, grid, dp);
    //             maxi=max(maxi, ans);
    //         }
    //     }
    //     return dp[i][j1][j2] = maxi;
    // }
    // public:
    // int maxChocolates(vector<vector<int>>& grid){
    //     int n=grid.size();
    //     int m=grid[0].size();
    //     vector<vector<vector<int>>>dp(n, vector<vector<int>>(m, vector<int>(m, -1)));
    //     return solve(0, 0, m-1, n, m, grid, dp);
    // }

    // Tabulation
    // public:
    //     int maxChocolates(vector<vector<int>> grid)
    //     {
    //         int n = grid.size();
    //         int m = grid[0].size();
    //         vector<vector<vector<int>>> dp(n, vector<vector<int>>(m, vector<int>(m, 0)));

    //         for (int j1 = 0; j1 < m; j1++)
    //         {
    //             for (int j2 = 0; j2 < m; j2++)
    //             {
    //                 if (j1 == j2)
    //                     dp[n - 1][j1][j2] = grid[n - 1][j1];
    //                 else
    //                     dp[n - 1][j1][j2] = grid[n - 1][j1] + grid[n - 1][j2];
    //             }
    //         }
    //         for (int i = n - 2; i >= 0; i--)
    //         {
    //             for (int j1 = 0; j1 < m; j1++)
    //             {
    //                 for (int j2 = 0; j2 < m; j2++)
    //                 {
    //                     int maxi = -1e9;
    //                     int curr = (j1 == j2) ? grid[i][j1] : grid[i][j1] + grid[i][j2];
    //                     for (int dj1 = -1; dj1 <= 1; dj1++)
    //                     {
    //                         for (int dj2 = -1; dj2 <= 1; dj2++)
    //                         {
    //                             int newJ1 = j1 + dj1;
    //                             int newJ2 = j2 + dj2;
    //                             if (newJ1 >= 0 &
    //                                 & newJ1 < m && newJ2 >= 0 && newJ2 < m)
    //                             {
    //                                 maxi =max (maxi, curr + dp[i + 1][newJ1][newJ2]);
    //                             }
    //                             else
    //                             {
    //                                 maxi = max(maxi, (int)-1e9);
    //                             }
    //                         }
    //                     }
    //                     dp[i][j1][j2] = maxi;
    //                 }
    //             }
    //         }
    //         return dp[0][0][m - 1];
    //     }

    // Space optimization
public:
    int maxChocolates(vector<vector<int>> &grid)
    {
        int n = grid.size();
        int m = grid[0].size();

        vector<vector<int>> next(m, vector<int>(m, 0));
        vector<vector<int>> curr(m, vector<int>(m, 0));

        for (int j1 = 0; j1 < m; j1++)
        {
            for (int j2 = 0; j2 < m; j2++)
            {
                if (j1 == j2)
                    next[j1][j2] = grid[n - 1][j1];
                else
                    next[j1][j2] = grid[n - 1][j1] + grid[n - 1][j2];
            }
        }
        for (int i = n - 2; i >= 0; i--)
        {
            for (int j1 = 0; j1 < m; j1++)
            {
                for (int j2 = 0; j2 < m; j2++)
                {
                    int maxi = -1e9;
                    int currChoco = (j1 == j2) ? grid[i][j1] : grid[i][j1] + grid[i][j2];
                    for (int dj1 = -1; dj1 <= 1; dj1++)
                    {
                        for (int dj2 = -1; dj2 <= 1; dj2++)
                        {
                            int newJ1 = j1 + dj1;
                            int newJ2 = j2 + dj2;
                            if (newJ1 >= 0 && newJ1 < m && newJ2 >= 0 && newJ2 < m)
                            {
                                maxi = max(maxi, currChoco + next[newJ1][newJ2]);
                            }
                            else
                            {
                                maxi = max(maxi, (int)-1e9);
                            }
                        }
                    }
                    curr[j1][j2] = maxi;
                }
            }
            next = curr;
        }
        return next[0][m - 1];
    }
};

int main()
{
    vector<vector<int>> grid = {
        {2, 3, 1, 2},
        {3, 4, 2, 2},
        {5, 6, 3, 5}};
    Solution obj;
    int ans = obj.maxChocolates(grid);
    cout << ans;
    return 0;
}