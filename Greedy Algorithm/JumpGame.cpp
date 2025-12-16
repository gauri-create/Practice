#include<iostream>
#include<vector>
using namespace std;

class JumpGame{
    public:
    bool canJump(vector<int>& nums){
        int maxIndex=0;
        for(int i=0; i<nums.size(); i++){
            if(i>maxIndex) return false;
            maxIndex=max(maxIndex, i+nums[i]);
        }
        return true;
    }
};

int main(){
    vector<int>nums={3,2,1,0,4};
    cout<<"Array representing maximum jump from each index: ";
    for(int val: nums) cout<<val<<" ";
    cout<<endl;

    JumpGame game;
    bool ans = game.canJump(nums);
    if (ans)
        cout<<"It is possible to reach the last index."<<endl;
    else 
        cout<<"It is not possible to reach the last index"<<endl;
    return 0;
}
