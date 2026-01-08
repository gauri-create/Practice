#include<iostream>
#include<vector>
#include<numeric>
using namespace std;

class Solution{
    public:
    int countPartitions(int n, int diff, vector<int>& arr){
        int totalSum=accumulate(arr.begin(), arr.end(), 0);
        if((totalSum+diff) % 2 != 0 || diff>totalSum) return 0;
        int k=(totalSum+diff) / 2;
        vector<int> dp(k+1, 0);
        dp[0]=1;
        if(arr[0] <=k) dp[arr[0]]+=1;
        for(int i=1; i<arr.size(); i++){
            vector<int>curr(k+1, 0);
            curr[0]=1;

            for(int t=0; t<=k; t++){
                int notTake = dp[t];
                int take=0;
                if(arr[i] <= t){
                    take=dp[t-arr[i]];
                }
                curr[t] = take+notTake;
            }
            dp=curr;
        }
        return dp[k];
    }
};

int main(){
    int n=4;
    int diff=1;
    vector<int> arr={1,1,2,3};
    Solution obj;
    int ans = obj.countPartitions(n, diff, arr);
    cout<<ans;
    return 0;
}