#include<iostream>
#include<vector>
using namespace std;

class Solution{
    public:
    int longestOnes(vector<int> &nums, int k){
        int l=0, r=0, maxLen=0, zeros=0;
        while(r<nums.size()){
            if(nums[r]==0) zeros++;
            if(zeros>k){
                if(nums[l]==0)zeros--;
                l++;
            }
            if(zeros<=k){
                int len=r-l+1;
                maxLen=max(maxLen, len);
            }
            r++;
        }
        return maxLen;
    }

};

int main(){
    Solution obj;
    vector<int> nums={1,1,1,0,0,0,1,1,1,1,0};
    int k=3;
    int ans= obj.longestOnes(nums, k);
    cout<<ans;
    return 0;
}