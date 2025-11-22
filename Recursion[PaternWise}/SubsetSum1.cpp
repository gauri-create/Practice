#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution{
public:
    vector<int> subsetSums(vector<int>& nums) {
        vector<int>sumSubset;
        func(0,0,nums,nums.size(),sumSubset);
        sort(sumSubset.begin(), sumSubset.end());
        return sumSubset;
    }
private:
    void func(int ind, int sum, vector<int>&arr,int N, vector<int>&sumSubset){
        if(ind == N){
            sumSubset.push_back(sum);
            return;
        }
        func(ind+1, sum+arr[ind], arr, N, sumSubset);
        func(ind+1, sum, arr, N, sumSubset);
    }
};

int main(){
    Solution obj;

    vector<int>nums={2,3};
    vector<int>ans = obj.subsetSums(nums);
    for(auto i: ans) cout<<i<<" ";
    return 0;
}