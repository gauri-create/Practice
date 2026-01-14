#include<iostream>
#include<vector>
using namespace std;

class Solution{
    public:
    int matrixMultiplication(vector<int>& nums){
        int n=nums.size();
        vector<vector<int>>dp(n, vector<int>(n, INT_MAX));

        for(int i=1; i<n; i++){
            dp[i][i]=0;
        }

        for(int length=2; length<n; length++){
            for(int i=1; i<=n-length;i++){
                int j=i+length-1;
                for(int k=i; k<j; k++){
                    int cost=dp[i][k]+dp[k+1][j]+nums[i-1]*nums[k]*nums[j];
                    if(cost<dp[i][j]){
                        dp[i][j]=cost;
                    }
                }
            }
        }
        return dp[1][n-1];
    }
};

int main(){
    vector<int>nums={10,15,20,25};
    Solution obj;
    int ans=obj.matrixMultiplication(nums);
    cout<<ans;
    return 0;
}