#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

class Solution{
    public:
    vector<vector<int>> primeFactors(vector<int>& nums){
        int n=nums.size();
        vector<vector<int>> result(n);
        for(int i=0; i<n;i++){
            for(int j=2;j<=sqrt(nums[i]);j++){   
                while(nums[i]%j==0){
                    result[i].push_back(j);
                    nums[i]=nums[i]/j;
                }            
            }
            if(nums[i]>1){
                result[i].push_back(nums[i]);
            }
        }
        return result;
    }
};

int main(){
    Solution obj;
    vector<int>nums={2,3,4,5,6};
    vector<vector<int>>ans=obj.primeFactors(nums);
    for(auto i: ans){
        for(auto j: i){
            cout<<j<<" ";
        }
        cout<<endl;
    }
}