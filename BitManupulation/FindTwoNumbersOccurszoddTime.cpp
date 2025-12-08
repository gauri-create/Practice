#include<iostream>
#include<vector>
using namespace std;

class Solution{
    public:
    vector<int> find2numbers(vector<int>&nums){
        int XOR=0;
        for(int i=0; i<nums.size(); i++){
            XOR=XOR^nums[i];
        }
        int rightmost=(XOR & XOR-1) & XOR;
        int b1=0, b2=0;
        for(int i=0; i<nums.size(); i++){
            if(nums[i] & rightmost)
                b1=b1^nums[i];
            else 
                b2=b2^nums[i];
        }
        if(b1<b2)
            return {b1, b2};
        return {b2,b1};
    }
};

int main(){
    Solution obj;
    vector<int>nums={1, 9, 1,2,8,2};
    vector<int>ans=obj.find2numbers(nums);
    for(auto i:ans){
        cout<<i<<" ";
    }
    return 0;
}