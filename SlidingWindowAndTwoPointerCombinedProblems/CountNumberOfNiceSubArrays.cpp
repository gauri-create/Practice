#include<iostream>
#include<vector>
using namespace std;

class Solution{
    int numberofsubarraySumAtMostGoal(vector<int> & nums, int goal){
        if(goal <0) return 0;
        int l=0, r=0, sum=0, cnt=0;
        while(r<nums.size()){
            sum += (nums[r]%2);
            while(sum>goal){
                sum=sum-nums[l];
                l=l+1;
            }
            cnt=cnt+(r-l+1);
            r=r+1;
        }
        return cnt;
    }
    public:
    int numberOfOddSubarrays(vector<int> & nums, int goal){
       return numberofsubarraySumAtMostGoal(nums, goal)-numberofsubarraySumAtMostGoal(nums, goal-1);
    }
};

int main(){
    Solution obj;
    vector<int> nums={1,1,2,1,1};
    int goal=3;
    int ans = obj.numberOfOddSubarrays(nums, goal);
    cout<<ans;
    return 0;
}