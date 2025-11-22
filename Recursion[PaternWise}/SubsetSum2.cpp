#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

class Solution{
    public:
    vector<vector<int>>SubsetsWithDup(vector<int>&nums){
        vector<vector<int>> ans;
        vector<int>ds;
        sort(nums.begin(),nums.end());
        findSubsets(0,nums,ds,ans);
        return ans;
    }

    private:
    void findSubsets(int ind, vector<int>&arr, vector<int>&ds, vector<vector<int>>&ans){
        ans.push_back(ds);
        for(int i=ind; i<arr.size(); i++){
            if(i!=ind && arr[i]==arr[i-1])continue;
            ds.push_back(arr[i]);
            findSubsets(i+1, arr, ds, ans);
            ds.pop_back();
        }
    }
};

int main(){
    Solution obj;
    vector<int>arr={1,2,2};
    vector<vector<int>> ans = obj.SubsetsWithDup(arr);
    for(auto x: ans){
        cout<<"[";
        for(auto i: x){
            cout<<i<<" ";
        }
        cout<<"]"<<endl;
    }

}