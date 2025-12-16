#include<iostream>
#include<vector>
#include<unordered_map>
using namespace std;

class Solution{
    public:
    vector<int> topKFrequent(vector<int>&nums, int k){
        unordered_map<int, int> freq;
        for(int x: nums) freq[x]++;

        vector<vector<int>> bucket(nums.size()+1);
        for(auto& it: freq)bucket[it.second].push_back(it.first);

        vector<int>result;
        for(int i=nums.size(); i>=1 && result.size()<k ; i--){
            for(int num : bucket[i]){
                result.push_back(num);
                if(result.size()==k) break;
            }
        }
        return result;
    }
};

int main(){
    Solution obj;
    vector<int> nums= {1,1,1,2,2,3};
    int k=2;
    vector<int>ans=obj.topKFrequent(nums,k);
    for(int x : ans) cout<<x<<" ";
    return 0;
}
