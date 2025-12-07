#include<iostream>
#include<vector>
#include<list>
using namespace std;

class Solution{
    public:
    vector<vector<int> > powerSet(vector<int>& nums) {
        int subset=1<<nums.size();
        vector<vector<int>>ans;

        for(int i=0; i<subset; i++){
            vector<int> lists;

            for(int j=0; j<nums.size(); j++){
                if(i&(1<<j)){
                    lists.push_back(nums[j]);
                }
            }
            ans.push_back(lists);
        }
        return ans;
    }
    
};

int main(){
    vector<int>nums={1,2,3};
    Solution obj;
    vector<vector<int>>ans = obj.powerSet(nums);
    for(auto subset: ans){
        cout<<"[";
        for(auto ele: subset){
            cout<<ele<<" ";
        }
        cout<<"]"<<endl;
    }
}