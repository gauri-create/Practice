#include<iostream>
#include<vector>
using namespace std;

class Solution{
    public:
    int numberOfLIS(vector<int>& arr){
        int n=arr.size();
        vector<int>dp(n, 1);
        vector<int>ct(n, 1);
        int maxi=1;
        for(int i=0; i<n; i++){
            for(int j=0; j<i; j++){
                if(arr[j]<arr[i] && dp[j]+1>dp[i]){
                    dp[i]=dp[j]+1;
                    ct[i]=ct[j];
                }
                else if(arr[j]<arr[i] && dp[j]+1 == dp[i]){
                    ct[i]=ct[i]+ct[j];
                }
            }
            maxi=max(maxi, dp[i]);
        }
        int countLIS=0;
        for(int i=0; i<n; i++){
            if(dp[i]==maxi){
                countLIS += ct[i];
            }
        }
        return countLIS;
    }
};

int main(){
    vector<int> nums={1,3,5,4,7};
    Solution obj;
    int ans=obj.numberOfLIS(nums);
    cout<<ans;
    return 0;
}