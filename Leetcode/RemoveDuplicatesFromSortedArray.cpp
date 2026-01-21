#include<iostream>
#include<vector>
#include<unordered_set>
using namespace std;

class Solution{
    public:
    int removeDuplicates(vector<int>& nums){
        if(nums.empty()) return 0;
        int k=1;
        for(int i=1; i<nums.size();i++){
            if(nums[i]!=nums[i-1]){
                nums[k]=nums[i];
                k++;
            }
        }
        for(int i=k; i<nums.size(); i++) nums[i]=0;
        return k;
    }
};

int main(){
    vector<int>nums={1,1,2};
    Solution obj;
    int ans=obj.removeDuplicates(nums);
    cout<<endl;
    cout<<ans;
    return 0;
}