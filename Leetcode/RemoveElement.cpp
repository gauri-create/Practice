#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

class Solution{
    public:
    int removeElement(vector<int>& nums, int val){
        if(nums.empty()) return 0;
        int k=0;
        for(int i=0; i<nums.size();i++){
            if(nums[i]!=val){
                nums[k]=nums[i];
                k++;
            }
        }
        for(int i=k; i<nums.size(); i++) nums[i]=0;
        return k;
    }
};

int main(){
    vector<int>nums={3,2,2,3};
    int val=3;
    Solution obj;
    int ans=obj.removeElement(nums,val);
    cout<<endl;
    cout<<ans;
    return 0;
}