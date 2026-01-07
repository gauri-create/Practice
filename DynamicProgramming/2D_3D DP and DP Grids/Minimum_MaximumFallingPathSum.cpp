#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

class Solution {
// //Memoization
//     int mindfs(int row, int col, vector<vector<int>>& matrix, vector<vector<int>>& dp){
//         int n= matrix.size();
//         int m=matrix[0].size();
//         const int INF=INT_MAX/2;

//         if(col<0 || col>=m) return INF;

//         if(row== n-1){
//             return dp[row][col] = matrix[row][col];
//         }

//         if(dp[row][col] != -1) return dp[row][col];

//         int down = mindfs(row+1, col, matrix, dp);
//         int downLeft = mindfs(row+1, col-1, matrix, dp);
//         int downRight = mindfs(row+1, col+1, matrix, dp);

//         int ans=matrix[row][col]+min({down, downLeft, downRight});
//         return dp[row][col]=ans;
//     }

//     int maxdfs(int row, int col, vector<vector<int>>& matrix, vector<vector<int>>& dp){
//         int n= matrix.size();  
//         int m=matrix[0].size();
//         const int NEG_INF= INT_MIN/2;

//         if(col<0 || col>=m) return NEG_INF;

//         if(row== n-1){
//             return dp[row][col] = matrix[row][col];
//         }

//         if(dp[row][col] != NEG_INF) return dp[row][col];

//         int down = maxdfs(row+1, col, matrix, dp);
//         int downLeft = maxdfs(row+1, col-1, matrix, dp);
//         int downRight = maxdfs(row+1, col+1, matrix, dp);

//         int ans=matrix[row][col]+max({down, downLeft, downRight});
//         return dp[row][col]=ans;
//     }
//     public:
//     int minFallingPathSum(vector<vector<int>>& matrix) {
//         int n=matrix.size();
//         int m=matrix[0].size();

//         vector<vector<int>> dp(n, vector<int>(m, -1));
//         int minSum=INT_MAX;
//         for(int col=0; col<m; col++){
//             minSum = min(minSum, mindfs(0, col, matrix, dp));
//         }
//         return minSum;
//     }

//     int maxFallingPathSum(vector<vector<int>>& matrix) {
//         int n=matrix.size();
//         int m=matrix[0].size();

//         vector<vector<int>> dp(n, vector<int>(m, INT_MIN/2));
//         int maxSum=INT_MIN;
//         for(int col=0; col<m; col++){
//             maxSum = max(maxSum, maxdfs(0, col, matrix, dp));
//         }
//         return maxSum;
//     }


// //Tabulation
//     public:

//     int minFallingPathSum(vector<vector<int>>& matrix){
//         int n=matrix.size();
//         int m=matrix[0].size();
//         const int INF=INT_MAX/2;

//         vector<vector<int>> dp(n, vector<int>(m, 0));

//         for(int col=0; col<m; col++){
//             dp[n-1][col]=matrix[n-1][col];
//         }

//         for(int row=n-2; row>=0; row--){
//             for(int col=0; col<m; col++){
//                 int down=dp[row+1][col];
//                 int downLeft=(col>0)?dp[row+1][col-1]:INF;
//                 int downRight=(col<m-1)?dp[row+1][col+1]:INF;
//                 dp[row][col]=matrix[row][col]+min({down, downLeft, downRight});
//             }
//         }
//         int minSum = *min_element(dp[0].begin(), dp[0].end());
//         return  minSum;
//     }

//     int maxFallingPathSum(vector<vector<int>>& matrix){
//         int n=matrix.size();
//         int m=matrix[0].size();
//         const int NEG_INF=INT_MIN/2;

//         vector<vector<int>> dp(n, vector<int>(m, 0));

//         for(int col=0; col<m; col++){
//             dp[n-1][col]=matrix[n-1][col];
//         }

//         for(int row=n-2; row>=0; row--){
//             for(int col=0; col<m; col++){
//                 int down=dp[row+1][col];
//                 int downLeft=(col>0)?dp[row+1][col-1]:NEG_INF;
//                 int downRight=(col<m-1)?dp[row+1][col+1]:NEG_INF;
//                 dp[row][col]=matrix[row][col]+max({down, downLeft, downRight});
//             }
//         }
//         int maxSum = *max_element(dp[0].begin(), dp[0].end());
//         return  maxSum;
//     }

//Space Optimization
public:
    int minFallingPathSum(vector<vector<int>>& matrix){
        int n=matrix.size();
        int m=matrix[0].size();
        const int INF=INT_MAX/2;

        vector<int>dp(matrix[n-1]);
        for(int row=n-2; row>=0; row--){
            vector<int>curr(m, 0);
            for(int col=0; col<m; col++){
                int down=dp[col];
                int downLeft = (col>0) ? dp[col-1]:INF;
                int downRight=(col<m-1) ? dp[col+1]:INF;

                curr[col] = matrix[row][col] + min({down, downLeft, downRight});
            }
            dp=curr;
        }
        return *min_element(dp.begin(), dp.end());
    }

    int maxFallingPathSum(vector<vector<int>>& matrix){
        int n=matrix.size();
        int m=matrix[0].size();
        const int INF=INT_MIN/2;

        vector<int>dp(matrix[n-1]);
        for(int row=n-2; row>=0; row--){
            vector<int>curr(m, 0);
            for(int col=0; col<m; col++){
                int down=dp[col];
                int downLeft = (col>0) ? dp[col-1]:INF;
                int downRight=(col<m-1) ? dp[col+1]:INF;

                curr[col] = matrix[row][col] + max({down, downLeft, downRight});
            }
            dp=curr;
        }
        return *max_element(dp.begin(), dp.end());
    }
};

int main(){
    vector<vector<int>>matrix={
        {1,2,10,4},
        {100,3,2,1},
        {1,1,20,2},
        {1,2,2,1}
    };

    Solution obj;
    int mini = obj.minFallingPathSum(matrix);
    int maxi = obj.maxFallingPathSum(matrix);

    cout<<mini<<endl;
    cout<<maxi<<endl;
    return 0;
}