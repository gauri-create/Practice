#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution{
    public:
    void nextPermutation(vector<int>& nums){
        int n=nums.size();
        
        for(int i=n-1; i>0; i--){
            if(nums[i-1] < nums[i]){
                int temp=nums[i-1];
                nums[i-1]=nums[i];
                nums[i]=temp;
                return;
            }
            if(nums[i] <nums[0] && nums[i]<nums[i-1]){
                reverse(nums.begin(), nums.end());
                return ;
            }
        }
    }
};

int main(){
    vector<int>nums={1,3,2};
    for(auto x: nums) cout<<x<<" ";
    cout<<endl;
    Solution obj;
    obj.nextPermutation(nums);
    for(auto x: nums) cout<<x<<" ";
    return 0;
}