#include<iostream>
#include<vector>
using namespace std;

class Solution{
    public:
    int findOddOccurence(vector<int>&nums){
        int XOR=0;
        for(int i:nums){
            XOR ^= i;
        }
        return XOR;
    }
};

int main(){
    vector<int>nums={4,4,6,1,2,1,2};
    Solution obj;
    int ans=obj.findOddOccurence(nums);
    cout<<ans<<endl;
    return 0;
}