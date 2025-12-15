#include<iostream>
#include<unordered_map>
#include<vector>
using namespace std;

class Solution {

    int func(vector<int>& nums, int k) {
        int l=0, r=0, cnt=0;
        unordered_map<int, int> mpp;
        while(r<nums.size()){
            mpp[nums[r]]++;
            while(mpp.size()>k){
                mpp[nums[l]]--;
                if(mpp[nums[l]]==0) mpp.erase(nums[l]);
                l++;
            }
            cnt=cnt+(r-l+1);
            r++;
        }
        return cnt;
    }
public:
    int subarraysWithKDistinct(vector<int>& nums, int k) {
        return func(nums, k)-func(nums, k-1);
    }
};

int main(){
    Solution obj;
    vector<int> nums={1,2,1,2,3};
    int k=2;
    int ans=obj.subarraysWithKDistinct(nums,k);
    cout<<ans;
    return 0;
}