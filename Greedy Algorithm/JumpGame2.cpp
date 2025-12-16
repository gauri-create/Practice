#include<iostream>
#include<vector>
using namespace std;

class Solution{
    public:
    int jump(vector<int>& nums){
        int jump=0, currentEnd=0, farthest=0;
        for(int i=0; i<nums.size()-1; i++){
            farthest = max(farthest, i+nums[i]);
            if(i==currentEnd){
                jump++;
                currentEnd=farthest;
            }
        }
        return jump;
    }
};

int main(){
    Solution obj;
    vector<int> nums={2,3,1,1,4};
    int ans = obj.jump(nums);
    cout<<ans;
    return 0;
}
